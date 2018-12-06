#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 1000

typedef struct Stack_El{
    	int data;
    	struct Stack_El* son;
} Stack_El;

int min(int x, int y) {
	if(x <= y)
        	return x;
    	else
        	return y;
}

int max(int x, int y) {
    	if(x >= y)
        	return x;
    	else
    		return y;
}

void push(int data, Stack_El* head, Stack_El* element) {
    	element->data = data;
    	element->son = NULL;
    	Stack_El* tmp = head;
    	while(tmp->son)
        	tmp = tmp->son;
    	if(tmp != element) tmp->son = element;
    	printf("push: %d\n", data);
}

int pop(Stack_El* head) {
    	Stack_El* tmp = head;
    	Stack_El* tmp1 = NULL;
    	while(tmp->son){
        	tmp1 = tmp;
        	tmp = tmp->son;
    	}
    	int element = tmp->data;
    	if(tmp1)
        	tmp1->son = NULL;
    	printf("pop: %d\n", element);
    	return element;
}

int main() {
    	//Инициализация;
    	int stack_size = -1;
    	Stack_El* stack = (Stack_El*)malloc(sizeof(Stack_El));
    	char str[N];
	printf("Please, enter the data line:\n");
    	fgets(str, N, stdin);
    	if(str[0] == '\n'){ //Поиск ошибки(пустая строка);
        	fprintf(stderr, "ERROR: You entered an empty line!\n");
        	free(stack);
        	return 0;
    	}
    	int i = strlen(str);
    	int count_of_brackets = 0;
    	printf("\n");
    
    	//Работа со стеком;
    	while(i >= 1){
        	i--;
        	if(str[i] == '('){
            	count_of_brackets++; //Поиск ошибки(название операции);
            	if(((i - 1) < 0) || (((i - 1) < 0) && ((str[i - 1] != 'm') || (str[i - 1] != 'M')))){
                		fprintf(stderr, "ERROR: Expected a name of operation before '('!\n");
                		free(stack);
                		return 0;
            	}
            	continue;
        	}
        	if(str[i] == ')'){
            	count_of_brackets--;
            	continue;
        	}
        	if((str[i] == ' ') || (str[i] == ',') || (str[i] == '\t') || (str[i] == '\n') || (str[i] == '\0'))
            	continue;
        
        	if(isdigit(str[i])){ //Пуш элемента в стек;
            	stack = (Stack_El*)realloc(stack, (stack_size + 2) * sizeof(Stack_El));
            	push((int)(str[i] - '0'), stack, &stack[++stack_size]);
            	continue;
        	}
        	if((str[i] == 'm') || (str[i] == 'M')){ //Вызов фунции min или max;
		    	if(stack_size < 1){ //Поиск ошибки(кол-во элементов);
				fprintf(stderr, "mERROR: There are 2 args should be in a function!\n");
        			free(stack);
        			return 0;
			}
			
            	int x = pop(stack);
                	stack_size--;
            	int y = pop(stack);
                	stack_size--;
            
            	if(str[i] == 'm'){
                		stack = (Stack_El*)realloc(stack, (stack_size + 2) * sizeof(Stack_El));
				push(min(x, y), stack, &stack[++stack_size]);
            	}
			if(str[i] == 'M'){
			    	stack = (Stack_El*)realloc(stack, (stack_size + 2) * sizeof(Stack_El));
				push(max(x, y), stack, &stack[++stack_size]);
			}
            	continue;
        	}
        
        	fprintf(stderr, "ERROR: Unexpected symbol %c!\n", str[i]);
        	free(stack);
        	return 0;
    	}
    
    	//ошибка построения;
    	if(count_of_brackets != 0){
        	fprintf(stderr, "ERROR: Counts of symbols '(' and ')' aren't equal!\n");
        	free(stack);
        	return 0;
    	}
 	if(stack_size != 0){ //Поиск ошибки(кол-во аргументов);
		fprintf(stderr, "ERROR: There are 2 args should be in a function!\n");
        	free(stack);
        	return 0;
	}
    
    	//Результат;
    	printf("\nResult: %d\n", pop(stack));
    	free(stack);
    	return 0;
}