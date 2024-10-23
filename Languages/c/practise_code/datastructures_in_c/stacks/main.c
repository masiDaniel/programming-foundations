#include <stdio.h>
#include <stdlib.h>
#define MAX 10


int count = 0;

struct stack {
	int items[MAX];
	int top;
};

typedef struct stack mystack;



void createEmptyStack(mystack *s);
int isfull(mystack *s);
int isempty(mystack *s);
void push(mystack *s, int newitem);
void pop(mystack *s);
void printstack(mystack *s);



int main (void)
{
	int ch, result_s, result_s2, input_element;

	mystack *s = (mystack *)malloc(sizeof(mystack));
	mystack *s2 = (mystack *)malloc(sizeof(mystack));

	createEmptyStack(s);
	

	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);

	result_s = isfull(s);

	if (result_s == 1){
		printf("cannot continue adding elements\n");
	}else{
		printf("can continue adding elements\n");
		// add_numerous_elements(result_s);
	}
	
	printf("the number of items in (s) is [%d]\n", count);


	printstack(s);
	pop(s);
	printf("\n after popping \n");
	printstack(s);

	createEmptyStack(s2);
	free(s);
	free(s2);


	return (0);
}


/**the funtion takes a pointer of an
 *instance of 'mystack' s which we create in the main  as its parameter
 *it sets the 'top' member of mystack pointed to by s to -1
 *when the top is -1 it indicated the stack is empty
*/

void createEmptyStack(mystack *s){
	s->top = -1;
}


/**this function checks is the stack is full by seeing if the value of top is 9
 * explain the logic
*/
int isfull(mystack *s){
	if (s->top == MAX - 1)
		return (1);
	else
		return (0);
}



/**this function checks if the stack is empty by checking if the value of top is -1
 * explain the logic
*/
int isempty(mystack *s){
	if (s->top == -1)
		return (1);
	else
		return (0);
}



/*this function takes two parameters, first a pointer to the stack
 * and the integer value to be pushed into the stack
 *here it checks if the stack is full
 *if the stack is not full it proceeds to perform the push operation
 *it increments the 'top'. this is important because 
 *it moves the top of the stack to the next available position
*/

/*this adds the 'newitem' value in the items array at the current 'top' position*/

void push(mystack *s, int newitem)
{
	if (isfull(s)){
		printf("stack is full\n");
	}else {
		s->top++;
		s->items[s->top] = newitem;
	}
	count++;
}


void pop(mystack *s){
	if (isempty(s)){
		printf("\n stack is empty\n");
	}else {
		printf("item popped = %d", s->items[s->top]);
		s->top--;
	}
	count--;
	printf("\n");
}



void printstack(mystack *s){
	printf("\tstack items: [");
	for (int i = 0; i < count; i++){
		printf("%d ", s->items[i]);
	}
	printf("]");
	printf("\n");
}


// void add_numerous_elements(int x){
// 	int result, input_element;
// 	while (result != 1){
// 		printf("enter the element you want to add\n");
// 		scanf("%d", &input_element);
// 		push(&s, input_element);
// 		result = isfull(s);
// 	}

// }