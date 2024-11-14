#include<stdio.h>
#include<stdlib.h>

char stack[20];
int stackSize=-1;
char postfix[20];

int prec(char sembol){
	if((sembol=='+' || sembol=='-'))
	  return 1;
	else if((sembol=='*' || sembol=='/'))
	  return 2;
	else 
	  return 3;
}
void push(char prec){
	stackSize++;
    stack[stackSize]=prec;
}
char pop(){
	char temp;
	
	temp=stack[stackSize];
	stackSize--;
	return temp;
}

void infixtopostfix(char infix[],int size){
	int i=0,j=0,k;
	for(i=0;i<size;i++){
	    if(prec(infix[i])==3){
	       postfix[j]=infix[i];
		   j++;	
		}else{
		    if(stackSize == -1){
		   		push(infix[i]);
		    }else{
		   		if(prec(infix[i])>prec(stack[stackSize])){
   	  	   				push(infix[i]);
   	  	   		}else{
			      	while((prec(infix[i]) <= prec(stack[stackSize])) && stackSize >=0){
			  	   	   postfix[j]=pop();
			  	   	   j++;
				    }
				    push(infix[i]);
   	  	   		}			   	
			}	   
		}
	}
	while(stackSize>=0){
		postfix[j]=pop();
		j++;
	}
}

int main(){
	char infix[20],kontrol;
	int N=0;
	printf("Infix notation:");
	do{
		scanf("%c",&kontrol);
		if(kontrol!='0' && kontrol != ' '){
		   infix[N]=kontrol;
		   N++; 	
		}
	}while(kontrol!='0');
	
	infixtopostfix(infix,N);
	
	printf("\nPostfix notation:");
	for (int l = 0; l < N; l++) {
	    if (postfix[l] != '\0') {
	        printf("%c", postfix[l]);
	    }
	}
	printf("\n");
	
system("pause");
return 0;
}


