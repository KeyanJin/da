#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node * next;

}Node;
// 初始化单链表
Node * initLinkedList()
{
    Node * list = (Node *)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    return list;
}
// 头插法
void headInsert(Node * list,int data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->next = list->next;
    list->next = node;
    node->data = data;
    list->data++;
}
// 尾插法
void tailInsert(Node * list,int data)
{
    Node * head = list;
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    list = list->next;
    while(list->next)
    {
        list = list->next;
    }
    list->next = node;
    head->data++;
}
// 删除元素
void _delete(Node * list,int data)
{
    Node * pre = list;
    Node * current = list->next;
    while(current)
    {
        if(current->data == data)
        {
            pre->next = current->next;
            free(current);
            break;
        }
        pre = current;
        current = current->next;
    }
    list->data--;
}
// 打印链表
void printList(Node * list)
{
    list = list->next;
    while (list)
    {
        printf("%d ",list->data);
        list = list->next;
    }
    printf("\n");
}
