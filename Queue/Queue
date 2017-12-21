#include <iostream>

class Node{
public:
    int data;
    Node *next, *prev;
};


class queue_m                                                                   //na massive
{
    int data[100000];
    long int start = -1, end = 0;
public:
    void push_back(int);
    int pop_front();
};

void queue_m::push_back(int n){
    if(end == 0)
        start++;
    this->data[this->end++] = n;
}

int queue_m::pop_front(){
     if(this->start == -1)
       return -1;
    return this->data[this->start++];
}

class queue_s                                                                   //na spiske
{
    Node *start = NULL, *end = NULL;
public:
    void push_back(int);
    int pop_front();
};

void queue_s::push_back(int n)
{
    if(this->end == NULL) {
        this->end = (Node*) malloc(sizeof(Node));
        this->end->data = n;
        this->end->next = NULL;
        this->end->prev = NULL;
        this->start = this->end;
    }
    else {
        this->end->next = (Node *) malloc(sizeof(Node));
        this->end->next->prev = this->end;
        this->end = this->end->next;
        this->end->data = n;
        this->end->next = NULL;
    }
}

int queue_s::pop_front()
{
    int a = 0;
    if (start == NULL)
        return a;
    if (start == end) {
        a = this->start->data;
        free(start);
        this->start = NULL;
        this->end = NULL;
        //free(end);
    }
    else {
        Node *to_free = this->start;
        a = this->start->data;
        this->start = this->start->next;
        this->start->prev = NULL;
        free(to_free);
    }
    return a;
}


class stack_m                                                                   //na massive
{
    int data[100000];
    long int top = 0;

public:
    void push(int);
    int pop();
};

void stack_m::push(int n){
    this->data[this->top++] = n;
}

int stack_m::pop(){
    if(this->top == 0)
        return -1;
    top--;
    return this->data[this->top];
}

class stack_s                                                               //na spiske
{
    Node *top = NULL;

public:
    void push(int);
    int pop();
};

void stack_s::push(int n)
{
    if(top == NULL) {
        this->top = (Node *) malloc(sizeof(Node));
        this->top->data = n;
        this->top->next = NULL;
        this->top->prev = NULL;
    }
    else
    {
        this->top->next = (Node *) malloc(sizeof(Node));
        this->top->next->prev = this->top;
        this->top = this->top->next;
        this->top->data = n;
        this->top->next = NULL;
    }
}

int stack_s::pop()
{
    int a = 0;
    if (top == NULL)
        return a;
    if ((top->prev == NULL) && (top->next == NULL)) {
        a = this->top->data;
        free(top);
        this->top = NULL;
    }
    else {
        Node *to_free = this->top;
        a = this->top->data;
        this->top = this->top->prev;
        this->top->next = NULL;
        free(to_free);
    }
    return a;
}
int main() {
    int a;
/*
    queue_s qu;
    int a;
    for (int i = 0; i < 15; i++)
        qu.push_back(i);


    for (int i = 0; i < 15; i++) {
        a = qu.pop_front();
        printf("%i ", a);
    }

    stack_m S;
    for(int i = 0; i < 15; i++)
        S.push(i);

    for(int i = 0; i < 15; i++) {
        a = S.pop();
        printf("%i ", a);
    }


    stack_s S1;
    for(int i = 0; i < 15; i++)
        S1.push(i);

    for(int i = 0; i < 15; i++) {
        a = S1.pop();
        printf("%i ", a);
    }
*/
    queue_m qu1;

    for (int i = 0; i < 15; i++)
        qu1.push_back(i);


    for (int i = 0; i < 15; i++) {
        a = qu1.pop_front();
        if(a == -1)
            printf("queue doesn't exist \n");
        else
            printf("%i ", a);
    }

    return 0;
}
