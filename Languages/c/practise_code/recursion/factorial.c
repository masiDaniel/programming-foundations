#include <stdio.h>
 
long int factorial(unsigned int i)
{
	unsigned int x = i;
	int factorial_result;

	while (i > 1){

		factorial_result = x * i;
		factorial(i);
		i--;
	}
	// int x = i;
	// if (i == 1)
	// {
	// 	return 1;
	// }

	// int factorial_result = x * i;
	// return 1 * factorial(i - 1);

	return (factorial_result);
}

int main(void)
{
	unsigned int num;
	while (1){
		printf("enter the number you want to get the factorial of : \n");
		scanf("%u", &num);
		long int result = factorial(num);
		printf("%ld\n", result);

	}

	return 0;
}
