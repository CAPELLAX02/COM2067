#include <stdio.h>
#include <stdlib.h>

struct nodeFB {
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS {
	int id;
	struct nodeGS *next;
};

struct newNodeFB {
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS {
	int id;
	struct newNodeFB *next;
};

// You must write all the function definitions to be used in this lab into this file. 
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.

void printFB(
	struct nodeFB* startFB
) {
	while (startFB != NULL) { 
        printf("%d %d\n", startFB->id, startFB->age); 
        startFB = startFB->next; 
    }
	printf("\n");
}

void printGS(struct nodeGS* startGS) {
	while (startGS != NULL) { 
        printf("%d\n", startGS->id); 
        startGS = startGS->next; 
    } 
	printf("\n");
}

void printAll(struct newNodeFB* startNewFB) {
	struct newNodeGS* startNewGS = (struct newNodeGS*) malloc(sizeof(struct newNodeGS));
	struct newNodeFB* newCurrFB;
	struct newNodeGS* newCurrGS;
	newCurrFB = startNewFB;
	newCurrGS = startNewGS;
	for (;;) {
		newCurrGS = newCurrFB->next;
		newCurrFB = newCurrGS->next;
		if (newCurrGS == NULL || newCurrFB == NULL) break;
		printf("%d %d\n", newCurrFB->id, newCurrFB->age);
		printf("%d\n", newCurrGS->id);
	}
}

void createFinalList(
	struct newNodeFB** startNewFB,
	struct nodeFB* startFB,
	struct nodeGS* startGS
) {
	struct newNodeGS* startNewGS = (struct newNodeGS*) malloc(sizeof(struct newNodeGS));
	struct newNodeFB* tempStartNewFb = (struct newNodeFB*) malloc(sizeof(struct newNodeFB));
	*startNewFB = tempStartNewFb;
	struct newNodeFB* newCurrFB;
	struct newNodeGS* newCurrGS;
	struct nodeFB* currFB;
	struct nodeGS* currGS;
	newCurrFB = *startNewFB;
	newCurrGS = startNewGS;
	currFB = startFB;
	currGS = startGS;
	while (currFB != NULL) {	
		newCurrFB->id = currFB->id;
		newCurrFB->age = currFB->age;
		newCurrFB->next = newCurrGS;
		newCurrGS->id = currGS->id;
		currFB = currFB->next;
		currGS = currGS->next;
		printf("%d %d\n", newCurrFB->id, newCurrFB->age);
		printf("%d\n", newCurrGS->id);
	}
}

void insertFB(
	struct nodeFB** startFB,
	int id,
	int age
) {
	struct nodeFB* newNode = (struct nodeFB*) malloc(sizeof(struct nodeFB));
	newNode->id = id;
	newNode->age = age;
	struct nodeFB* curr; 
    if (*startFB == NULL || (*startFB)->id >= newNode->id) { 
        newNode->next = *startFB; 
        *startFB = newNode; 
    } else {
        curr = *startFB; 
        while (curr->next != NULL && curr->next->id < newNode->id) 
            curr = curr->next; 
        newNode->next = curr->next; 
        curr->next = newNode; 
    }
}

void insertGS(
	struct nodeGS** startGS,
	int id
) {
	struct nodeGS* newNode = (struct nodeGS*) malloc(sizeof(struct nodeGS));
	newNode->id = id;
	struct nodeGS* curr; 
    if (*startGS == NULL || (*startGS)->id <= newNode->id) { 
        newNode->next = *startGS; 
        *startGS = newNode; 
    } else {
        curr = *startGS; 
        while (curr->next != NULL && curr->next->id > newNode->id)
            curr = curr->next; 
        newNode->next = curr->next; 
        curr->next = newNode; 
    }
}