#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "22290230.h"

struct nodeFB *startFB = NULL;
struct nodeGS *startGS = NULL;
struct newNodeFB *startNewFB = NULL;

int main()
{
	int id, age;
	scanf("%d", &id);
	while(id!=-1)
	{		
		scanf("%d", &age);
		insertFB(&startFB, id, age);
		scanf("%d", &id);
	}
	
	scanf("%d", &id);
	while(id!=-1)
	{		
		insertGS(&startGS, id);
		scanf("%d", &id);
	}
	
	printFB(startFB); 
	printGS(startGS);	
	createFinalList(&startNewFB,startFB,startGS); 	
	printAll(startNewFB); 
	
	return 0;
		
}
