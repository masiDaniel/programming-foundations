#include <stdio.h>

void swap_by_reference(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int swap_by_value(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
    return (y);
}

int main(void)
{
    int a, b;
    a = 6 , b = 10;
    printf("a = [%d], b = [%d] \n", a, b);
    swap_by_reference(&a, &b);

    printf("a = [%d], b =  [%d] \n", a, b);

    int c = swap_by_value(5, 6);
    printf("the number is [%d] \n", c);
    printf("this proves thet the function has achive its purpose \n");
    return (0);
}