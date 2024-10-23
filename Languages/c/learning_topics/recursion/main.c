#include <stdio.h>

int factorial_recursion(int n)
{
    //this function gets to n = 1 and multiplies backwards till it gets the answer
   
   if (n == 1){
    return 1;

   }
   else
   {
    return n * factorial_recursion(n - 1);
   }
}

int factorial_iterative(int n){
    int result = 1;

    while (n > 1)
    {
        result *= n; // result = result * n
        n--;
    }
    
    return result;
}


int main()
{ 
    int result = factorial_recursion(5);
    int iterative_result = factorial_iterative(5);
    printf("factorial of 5 is %d \n", result);
    printf("factorial of 5 is %d \n", iterative_result);
    return 0;
}