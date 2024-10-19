#include <stdio.h>
#include <stdlib.h>

#define MAX 2
#define MIN 1

struct node
{
    int item[MAX + 1], count;
    struct node *link[MAX + 1];
    struct node *parent;
};

struct node *root;

struct node *createnode(int item, struct node *child)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->item[1] = item;
    newnode->count = 1;
    newnode->link[0] = root;
    newnode->link[1] = child;
    newnode->parent = NULL;

    if (child != NULL)
    {
        child->parent = newnode;
    }

    return newnode;
}

void insert(int item, int position, struct node *node, struct node *child)
{
    int j = node->count;
    while (j > position)
    {
        node->item[j + 1] = node->item[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->item[j + 1] = item;
    node->link[j + 1] = child;
    node->count++;
}

void splitnode(int item, int *value, int position, struct node *node,
               struct node *child, struct node **newnode)
{
    int median, j;

    if (position > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *newnode = (struct node *)malloc(sizeof(struct node));
    j = median + 1;
    while (j <= MAX)
    {
        (*newnode)->item[j - median] = node->item[j];
        (*newnode)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*newnode)->count = MAX - median;

    if (position <= MIN)
    {
        insert(item, position, node, child);
    }
    else
    {
        insert(item, position - median, *newnode, child);
    }
    *value = node->item[node->count];
    (*newnode)->link[0] = node->link[node->count];
    node->count--;
}

int set(int item, int *value,
        struct node *node, struct node **child)
{
    int position;
    if (!node)
    {
        *value = item;
        *child = NULL;
        return 1;
    }

    if (item < node->item[1])
    {
        position = 0;
    }
    else
    {
        for (position = node->count;
             (item < node->item[position] && position > 1); position--)
            ;
        if (item == node->item[position])
        {
            return 0;
        }
    }
    if (set(item, value, node->link[position], child))
    {
        if (node->count < MAX)
        {
            insert(*value, position, node, *child);
        }
        else
        {
            splitnode(*value, value, position, node, *child, child);
            return 1;
        }
    }
    return 0;
}

void insertion(int item)
{
    int flag, i;
    struct node *child;

    flag = set(item, &i, root, &child);
    if (flag)
        root = createnode(i, child);
}

void copy(struct node *mynode, int position)
{
    struct node *dummy;
    dummy = mynode->link[position];

    for (; dummy->link[0] != NULL;)
        dummy = dummy->link[0];
    mynode->item[position] = dummy->item[1];
}

void rightshift(struct node *mynode, int position)
{
    struct node *x = mynode->link[position];
    int j = x->count;

    while (j > 0)
    {
        x->item[j + 1] = x->item[j];
        x->link[j + 1] = x->link[j];
        j--;
    }
    x->item[1] = mynode->item[position];
    x->link[1] = x->link[0];
    x->count++;

    x = mynode->link[position - 1];
    mynode->item[position] = x->item[x->count];
    mynode->link[position] = x->link[x->count];
    x->count--;
    return;
}

void leftshift(struct node *mynode, int position)
{
    int j = mynode->link[position]->count;
    struct node *x = mynode->link[position - 1];

    x->count++;
    x->item[x->count] = mynode->item[position];
    x->link[x->count] = mynode->link[position]->link[0];

    mynode->link[position]->link[0] = mynode->link[position]->link[1];

    x = mynode->link[position];
    mynode->item[position] = x->item[1];
    x->link[0] = x->link[1];
    x->count--;

    while (j > 1)
    {
        x->item[j] = x->item[j - 1];
        x->link[j] = x->link[j - 1];
        j--;
    }
    return;
}

void merge(struct node *mynode, int position)
{
    int j = 1;
    struct node *x1 = mynode->link[position], *x2 = mynode->link[position - 1];

    x2->count++;
    x2->item[x2->count] = mynode->item[position];
    x2->link[x2->count] = mynode->link[0];

    while (j <= x1->count)
    {
        x2->count++;
        x2->item[x2->count] = x1->item[j];
        x2->link[x2->count] = x1->link[j];
        j++;
    }

    j = position;
    while (j < mynode->count)
    {
        mynode->item[j] = mynode->item[j + 1];
        mynode->link[j] = mynode->link[j + 1];
        j++;
    }
    mynode->count--;
    free(x1);
}

void adjust(struct node *mynode, int position)
{
    if (!position)
    {
        if (mynode->link[1]->count > MIN)
        {
            leftshift(mynode, 1);
        }
        else
        {
            merge(mynode, 1);
        }
    }
    else
    {
        if (mynode->count != position)
        {
            if (mynode->link[position - 1]->count > MIN)
            {
                rightshift(mynode, position);
            }
            else
            {
                if (mynode->link[position + 1]->count > MIN)
                {
                    leftshift(mynode, position + 1);
                }
                else
                {
                    merge(mynode, position);
                }
            }
        }
        else
        {
            if (mynode->link[position - 1]->count > MIN)
                rightshift(mynode, position);
            else
                merge(mynode, position);
        }
    }
}

void updateparent(struct node *mynode, struct node *parent)
{
    if (mynode)
    {
        mynode->parent = parent;
        for (int i = 0; i <= mynode->count; i++)
        {
            updateparent(mynode->link[i], mynode);
        }
    }
}

void levelordertraversal(struct node *root)
{
    if (root == NULL)
        return;

    struct node **queue = (struct node **)malloc(1000 * sizeof(struct node *));
    int front = -1, rear = -1, currentlevel = 0, nextlevel = 0;

    queue[++rear] = root;
    currentlevel++;

    while (front != rear)
    {
        struct node *current = queue[++front];
        currentlevel--;

        for (int i = 1; i <= current->count; i++)
        {
            printf("%d", current->item[i]);
            if (i < current->count)
            {
                printf("-");
            }
        }

        if (current->parent != NULL)
        {
            printf(" (");
            for (int i = 1; i <= current->parent->count; i++)
            {
                printf("%d", current->parent->item[i]);
                if (i < current->parent->count)
                {
                    printf("-");
                }
            }
            for (int i = 0; i <= current->parent->count; i++)
            {
                if (current->parent->link[i] == current)
                {
                    if (i == 0)
                        printf(" L)");
                    else if (i == current->parent->count)
                        printf(" R)");
                    else
                        printf(" M)");
                }
            }
        }
        if (currentlevel != 0)
            printf(" ");
        for (int i = 0; i <= current->count; i++)
        {
            if (current->link[i] != NULL)
            {
                queue[++rear] = current->link[i];
                nextlevel++;
            }
        }

        if (currentlevel == 0)
        {
            printf("\n");
            currentlevel = nextlevel;
            nextlevel = 0;
        }
    }

    free(queue);
}

int main()
{
    int data;

    while (1)
    {
        scanf("%d", &data);

        if (data == -1)
            break;

        insertion(data);
    }
    updateparent(root, NULL);
    levelordertraversal(root);
    return 0;
}