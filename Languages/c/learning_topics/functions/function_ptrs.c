#include <stdio.h>

void modify_my_parameter(int *m)
{
    int new;
    printf("how much money do you want to transfer?");
    scanf("%d", &new);
    *m = new;
}

int main(void)
{

    int n = 98;
    int m = 100;

    int *p;
    p=&n;


    printf("value of n is [%d]\n",n);
    modify_my_parameter(p);
    printf("the value of n after the call: [%d]\n", n);

    printf("value of m is [%d]\n",m);
    modify_my_parameter(&m);
    printf("the value of m after the call: [%d]\n", m);

    

    printf("\n\t==========================\n\n");
    
    printf("the address of n [%p]\n",&n);
    printf("the value of p is [%p]\n",p);
    printf("address of p is [%p]\n",&p);


    return (0);
}
