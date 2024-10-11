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
        my_str->data = (char *)malloc(sizeof(char) * len + 1);
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

int main(void)
{
    my_string * str = init_string();
    string_assign(str,"Hello");
    print_string(str);
    return 0;
}
