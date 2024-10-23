#include <stdio.h>

int main(int argc, char *argv[]){
    int x = 0;
        if (argc >= 2){
            printf("the arguments supplied are: \n");
            while (x < argc){
                printf(" [%s]\n", argv[x]);
                x++;
            }
        } else {
            printf("one argument is expected \n");
        }
    return (0);
}