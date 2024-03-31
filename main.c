#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}
	Node;
	

typedef struct Stack {
	Node* top;
}
	Stack;

Node* createNode(int data) {
	Node* node = malloc(sizeof(node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

int is_empty(Stack*);

void push(Stack* stack, int data){
	Node* newNode = createNode(data);
// if the Stack is Empty
	if (is_empty(stack)){
		stack->top = newNode;
	}
	else {
		Node* prevTop =  stack->top;
		prevTop->prev = newNode;
		newNode->next = prevTop;
		stack->top = newNode;

	}
}
void print_stack(Stack* stack) {
	Node* curr = stack->top;
	while (curr != NULL) {
		printf("%d\n",curr->data);
		curr = curr->next;
	}
	printf("\n");
}
int pop(Stack* stack) {
// if stack is empty
	if (is_empty(stack)) {
		perror("Underflow Error");
		return (-1);
	}
	Node* currTop = stack->top;
	stack->top = stack->top->next;
	int removedData = currTop->data;
	free(currTop);
	return removedData;
}
// if stack is empty
int is_empty(Stack* stack) {
	return stack->top == NULL;
}

int main(void) {
	Stack stack;
	stack.top = NULL;
	printf("the stack is empty: %d\n", is_empty(&stack));
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	print_stack((&stack));
	while (is_empty(&stack) == 0) {
		int removed = pop(&stack);
		printf( "removed %d\n", removed);
		if (removed % 2 == 1) {
			push(&stack, 100);
		}
	}
	printf("is stack empty: %d \n", is_empty(&stack));
	return (0);
}
