#include <stdlib.h>
#include <stdio.h>

typedef struct String
{
    char * data;
    int len;
} String;
// 初始化字符串
String * initString()
{
    String * str = (String *)malloc(sizeof(String));
    str->len = 0;
    str->data = NULL;
    return str;
}
// 赋值操作
void StringAssign(String * my_str,char * str)
{
    if (my_str->data)
    {
        free(my_str);
    }
    int len = 0;
    char * temp = str;
    while (*temp)
    {
        len++;
        temp++;
    }
    if(len == 0)
    {
        my_str->data = NULL;
        my_str->len = 0;
    }
    else
    {
        my_str->data = (char *)malloc(sizeof(char) * (len + 1));
        my_str->len = len;
        temp = str;
        for(int i = 0;i < len;i++,temp++)
        {
            my_str->data[i] = *temp;
        }
    }  
}
// 打印字符串
void printString(String * my_str)
{
    for(int i = 0;i < my_str->len;i++)
    {
        // printf("%c",my_str->data[i]);
        printf(i == 0 ? "%c" : "->%c",my_str->data[i]);
    }
    printf("\n");
}
// 暴力匹配
int forceMatch(String * master,String * subject)
{
    int index = -1;
    int masterPointer = 0;
    int subjectPointer = 0;
    while (masterPointer < master->len && subjectPointer < subject->len)
    {
        if(master->data[masterPointer] == subject->data[subjectPointer])
        {
            masterPointer++;
            subjectPointer++;
        }
        else
        {
            masterPointer = masterPointer - subjectPointer + 1;
            subjectPointer = 0;
        }
    }
    index = masterPointer - subject->len;
    return index;
}
int main(void)
{
    String * str1 = initString();
    StringAssign(str1,"Hello World");
    String * str2 = initString();
    String * str3 = initString();
    StringAssign(str3,"Hello");
    StringAssign(str2,"World");
    int index1 = forceMatch(str1,str2);
    int index2 = forceMatch(str1,str3);
    printf("%d,%d",index1,index2);
    return 0;
    
}