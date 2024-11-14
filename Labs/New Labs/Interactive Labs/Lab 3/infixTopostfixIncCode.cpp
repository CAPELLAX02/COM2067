#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int stackIndex=-1;
int postfixIndex=-1;
char infix[100],stack[100],postfix[100];

int bos(char stack[]);

void ekle(char temp);
void cikar(char temp );
int gelenKarakteriKontrolEt(char siradakiEleman);

int stackGirerken(char temp);
int stackIci(char temp);

int main(){
  int i=0;
  printf("Lutfen ifadeyi giriniz...");
  printf("\n");
  scanf("%s",infix);
  printf("%s",infix);
   
  
  while(infix[i]!='\0'){
       
      if(gelenKarakteriKontrolEt(infix[i]) != 0){
      		  
	  		if(gelenKarakteriKontrolEt(infix[i]) == 1){
                postfixIndex++;
				postfix[postfixIndex]=infix[i]; 
                
      
          	}else{
                if(bos(stack)==0){
                  ekle(infix[i]);            
                }else{
                    if(stackGirerken(infix[i]) <= stackIci(stack[stackIndex]))
                       cikar(infix[i]);
                    
					else{
						ekle(infix[i]);
					}
                       
                } 
          	}
      		
      }else{
      	 	printf("ifadede %c karakteri olamaz \n",infix[i]);
      }
        
      i++;        
  }
  while(stackIndex >=0){
  	 if(stack[stackIndex] != '('){
  	 	 ++postfixIndex;
		 postfix[postfixIndex]=stack[stackIndex];
		 	
  	 }
  	 --stackIndex;
	
  }
  printf("\n");
  printf("posfix:%s",postfix);
 
     
system("pause");
return 0;     
}
int bos(char stack[]){
    if(stackIndex==-1)
      return 0;
    else
      return 1;
}
int stackGirerken(char temp){
    if(temp == '(')
      return 4;
   if(temp == '+' || temp == '-')
      return 1;
   if(temp == '*' || temp == '/' )
      return 2;
   if(temp == ')')
   	  return -1;
  
}
int stackIci(char temp){
     if(temp == '(')
      return 0;
   if(temp == '+' || temp == '-')
      return 1;
   if(temp == '*' || temp == '/' )
      return 2;
   
}

void ekle(char temp){
    ++stackIndex;
	stack[stackIndex]=temp;
}
void cikar(char temp){
    if(temp == ')'){ 
    	while(stack[stackIndex] != '(' && stackIndex != -1){
    		++postfixIndex;
			postfix[postfixIndex] = stack [stackIndex];
    		--stackIndex;
    	}
    	if(stackIndex == -1 ){
    		printf("Girilen islem yanlistir not: Parantez acilmadan kapatilmis !!\n");
    	}else{
    		--stackIndex;
        }
    }else{
   		while( stackGirerken(temp) <= stackIci(stack[stackIndex]) && stackIndex !=-1 ){
   			++postfixIndex;
			postfix[postfixIndex] = stack [stackIndex];
    		--stackIndex;
   		}
   		ekle(temp);
    }
}
int gelenKarakteriKontrolEt(char siradakiEleman){
	if(siradakiEleman >= '0' && siradakiEleman<= '9'){
		return 1;
	}else if(siradakiEleman== '+' || siradakiEleman == '-' || siradakiEleman == '*'|| siradakiEleman == '/'|| siradakiEleman== '('|| siradakiEleman== ')'){
		return 2;
	}else{
		return 0;
	}
}

