#include <stdio.h>
#include <stdlib.h>

struct mystructure{
 char *name;
 int age;
 int id;
};

int main (void)
{
/*to acces a structure you must create a variable of it*/
struct mystructure valleyrock;

/*to acces the members of a structure we use the (.)*/
valleyrock.name = "dan";
valleyrock.age = 20;
valleyrock.id = 5;


/*to print the values*/
printf("the information for valleyrock is \n%s \n%d \n%d \n",valleyrock.name, valleyrock.age, valleyrock.id );

return (0);
}

