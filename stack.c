#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node * next;
    
}Node;

// 初始化
Node * initStack()
{
    Node * stack = (Node *)malloc(sizeof(Node));
    stack->data = 0;
    stack->next = NULL;
    return stack;
}
// 判断是否为空
int isEmpty(Node * stack)
{
    if(stack->data == 0 || stack->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// 弹出元素
int pop(Node * stack)
{
    int popData;
    Node * pre = stack;
    Node * current = stack->next;
    if(isEmpty(stack))
    {
        return -1;
    }
    else
    {
        while (current->next)
        {
            current = current->next;
            pre = pre->next;
        }
        popData = current->data;
        free(current);
        pre->next = NULL;
        return popData;
    }
}
// 添加元素
void push(Node * stack ,int data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    Node * pre = stack;
    while (pre->next)
    {
        pre = pre->next;
    }
    pre->next = node;    
    node->data = data;
    node->next = NULL;
}
// 打印stack
void printStack(Node * stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        Node * current = stack;
        for(;current->next != NULL;current = current->next)
        {
            printf("%d->",current->data);
        }
    }
}