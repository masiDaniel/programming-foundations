#include <stdio.h>


int main(){

    while (1){

    int a, b, c,d, result;
    char operation;
    printf("key in the first number you want to use\n");
    scanf("%d", &a);
    printf("key in the second number you want to use\n");
    scanf("%d", &b);
    
    getchar();
    printf("key in the numbers you want to use\n ");
    scanf("%c", &operation);


    switch (operation)
    {
        case '+':
            result = a + b;
            printf("{%d} + {%d} = %d\n", a, b, result);
            break;
        case '-':
            result = a - b;
            printf("{%d} - {%d} = %d\n", a, b, result);
            break;
        
        case '*':
            result = a * b;
            printf("{%d} * {%d} = %d\n", a, b, result);
            break;
        
        case '/':
            if (b != 0){
                result = a / b;
                printf("{%d} / {%d} = %d\n", a, b, result);
            }else
            {
                printf("Error: Diviion by zero\n");
                return 1;
            }
            break;
        default:
            printf("invalid operator\n");
            return 1;
        
    };

    
    }
    return 0;
}