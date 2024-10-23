#include <stdio.h>

int stringlength(char *words)
{
	int a = 0;
	while (*words != '\0')
	{
	a++;
	words++;
	}
	return (a);
}

int main(void)
{
	printf("this part runs\n");
	int length;
	char *test = "hello world";
	length = stringlength(test);
	printf("%d\n", length);

	return (0);
}
