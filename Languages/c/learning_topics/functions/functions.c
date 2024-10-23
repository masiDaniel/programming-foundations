#include <stdio.h>


void modify_my_para (int m)
{
	printf("the value of m is :[%d]\n",m);
	m = 100;
	printf("the new value of m  in the function is : [%d]\n ", m);

}

/** this calls a function by value
 * this is not effective as it only changes the value as a copy
 * this does not change it from the actual memory location
*/
void swap(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("\t\ta is [%d], and b is [%d] \n", a, b);
}

/**this calls a function by refrence
 * this is a more efficient manner because it edits them in the memory location 
 * hence actual change happens.
*/
void swapByRefrence(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("\t\ta is [%d], b is [%d] \n ", *a, *b);
}

int main(void)
{
	int n = 98;
	int a = 5, b = 10;
	int c = 15, d = 20;


	printf("The value of n intially is [%d]\n", n);
	modify_my_para(n);
	printf("\t\tafter function call the value of n is [%d]\n", n);

	printf("the values of [a] and [b] initally are [%d], [%d].\n", a, b);
	swap(a ,b);

	printf("\t\tthe values of a and b after function call are [%d], [%d]\n", a, b);

	swapByRefrence(&c, &d);
	printf("the values of c and d are [%d], [%d]\n", c, d);
	return (0);
}
