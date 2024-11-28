#include <stdio.h>
#include <stdlib.h>

typedef struct Q {
    int x;
    int i;
    struct Q *nxt; 
    struct Q *prv;
} q;

q *s = NULL;
q *e = NULL;

void add(int newX, int ind) {
    q *new = (q*)malloc(sizeof(q));
    new->x = newX;
    new->i = ind; 
    new->nxt = NULL; 
    new->prv = NULL; 
    if (s == NULL) {
        s = new;
        e = new;
    } else {
        q *tmp = e; 
        tmp->nxt = new; 
        new->prv = tmp; 
        e = new;
    }
}

void adj() {
    if (s == NULL || e == NULL) return;
    q *tpmS = s;
    s = s->nxt;
    if (s != NULL) s->prv = NULL;
    q *tmpE = e;
    e = e->prv;
    if (e != NULL) e->nxt = NULL; 
}

int sum(int n, int *arr1, int *arr2) {
    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (s == NULL || e == NULL) break;
        if (s->x >= e->x) {
            arr1[i] = s->x;
            arr2[i] = s->i;
            tot += s->x;
            adj();
        } else {
            arr1[i] = e->x;
            arr2[i] = e->i;
            tot += e->x;
            adj();
        }
    }
    return tot;
}

int main(void) {
    int i = 0, n, idx = 1, in; 
    while (2 > 1){
        scanf("%d", &in); 
        if (in == -1) break;
        add(in, idx);
        idx++;
    }
    scanf("%d", &n); 
    int sV[n];
    int sI[n];
    int xSum = sum(n, sV, sI);
    printf("%d\n", xSum);
    for (; i < n; i++) {
        if (sV[i] != 0) printf("%d %d\n", sV[i], sI[i]);
    }
}