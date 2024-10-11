#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int data;
    struct Node * next;
    
}Node;

// 初始化链表
Node * initList()
{
    Node * list = (Node *)malloc(sizeof(Node));
    list->data = 0;
    list->next = list;
    return list;
}
// 头插法
void headInsert(Node * list,int data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = list->next;
    list->data++;
    list->next = node;
}
// 尾插法
void tailInsert(Node * list,int data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    Node * current = list;
    while (current->next != list)
    {
        current = current->next;
    }
    current->next = node;
    node->next = list;
    node->data = data;
    list->data++;
    
}
// 删除元素
int delete(Node * list,int data)
{
    Node * pre = list;
    Node * current = list->next;
    while (current->data != data)
    {
        current = current->next;
        pre = pre->next;
        if(current == list)
            return FALSE;
    }
    pre->next = current->next;
    free(current);
    return TRUE;
}
// 打印链表
void printList(Node * list)
{
    Node * node = list->next;
    while(node != list)
    {
        printf("%d->",node->data);
        node = node->next;
    }
    printf("NULL\n");
}



int main()
{
    Node * list = initList();
    headInsert(list,1);
    headInsert(list,3);
    tailInsert(list,2);
    tailInsert(list,4);
    printList(list);
    int status1 = delete(list,3);
    int status2 = delete(list,5);
    printf("%d,%d\n",status1,status2);
    printList(list);


    return 0;
}

