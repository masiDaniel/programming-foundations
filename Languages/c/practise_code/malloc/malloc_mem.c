#include <stdio.h>
#include <stdlib.h>

void m(int n0, int n1, int n2);
/**
 * main - example
 *
 * return: 0
 */

int main(void)
{
m(98, 402, -1025);
return (0);
}


/**
 * m - stores 3 int in a new allocated space in memory and prints the sum
 * @n0: integer
 * @n1: integer
 * @n2: integer
 *
 * Return: nothing
 */

void m(int n0, int n1, int n2)
{
int *tab;
int sum;

tab = malloc(sizeof(*tab) * 3);
tab[0] = n0;
tab[1] = n1;
tab[2] = n2;

sum = tab[0] + tab[1] + tab[2];
printf("%d + %d + %d = %d", tab[0], tab[1], tab[2], sum);
}
