#include <stdio.h>
#include <stdlib.h>
/**
 * main - malloc
 *
 * Return 0;
 */
int main(void)
{
    char *str;
    str = malloc(sizeof(char) * 3);
    str[0] = 'o';
    str[1] = 'k';
    str[2] = '\n';
    printf("%s\n", str);

    free(str);
    printf("%c\n", str[5]);
    return (0);
}
