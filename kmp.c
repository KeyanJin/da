#include <stdio.h>
#include <stdlib.h>

typedef struct my_string
{
    char * data;
    int len;
}my_string;
// 初始化字符串
my_string * init_string()
{
    my_string * str = (my_string *)malloc(sizeof(my_string));
    str->data = NULL;
    str->len = 0;
    return str;
}
// 赋值
void string_assign(my_string * my_str,char * str)
{
    if(my_str->data)
    {
        free(my_str);
    }
    int len = 0;
    char * temp = str;
    while (*temp)
    {
        temp++;
        len++;
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
void print_string(my_string * my_str)
{
    for(int i = 0;i < my_str->len;i++)
    {
        printf("%c",my_str->data[i]);
    }
    printf("\n");
}
// Next 数组的获取
int * get_next(my_string * str)
{
    int * next = (int *)malloc(sizeof(str->len));
    int i = 0;
    int j = -1;
    next[i] = j;
    while (i < str->len - 1)
    {
        if (j == -1 || str->data[i] == str->data[j])
        {
            j++;
            i++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }        
    }
    return next;
    
}
// KMP算法实现
void KMP_match(my_string * mas,my_string * sub,int * next)
{   
    int i = 0;
    int j = 0;
    while (i < mas->len && j < sub->len)
    {
        if(mas->data[i] == sub->data[j])
        {
            i++;
            j++;
        }
           
        else
        {
            j = next[j];
        }
    }
    if(j == sub->len)
    {
        printf("match success\n");
    }
    else
    {
        printf("match fail\n");
    }
}
int main(void)
{
    


    return 0;
}

