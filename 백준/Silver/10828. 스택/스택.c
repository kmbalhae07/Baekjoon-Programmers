#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10001

typedef struct{
    int item[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int is_full(Stack *s) {
    return s->top == MAX_SIZE-1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int e){
    s->item[++(s->top)] = e;
}

//비어있으면 -1 출력
int pop(Stack *s) {
    if(is_empty(s)) {
        return -1;
    } else {
        return s->item[(s->top)--];
    }
}

int size(Stack *s) {
    return s->top+1;
}

int empty(Stack *s) {
    if(is_empty(s)) {
        return 1;
    } else {
        return 0;
    }
}

int top(Stack *s) {
    if(is_empty(s)) {
        return -1;
    } else {
        return s->item[s->top];
    }
}

int main() {
    Stack s;
    initStack(&s);

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            int num;
            scanf("%d", &num);
            if (is_full(&s)) {
                printf("Stack overflow\n");
            } else {
                push(&s, num);
            }
        } else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop(&s));
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&s));
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty(&s));
        } else if (strcmp(command, "top") == 0) {
            printf("%d\n", top(&s));
        }
    }
}