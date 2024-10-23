#include <stdio.h>
#include <stdlib.h>
/*self referential structure*/

typedef struct node {
    int data;
    struct node *link;
} nodes_of_list;

//below we have defined two pointers of type struct node *
nodes_of_list *head = NULL;
struct node *current = NULL;

//treversing the list
void print_list()
{
    //here also we reate a new pointer which points to the same location as head
    struct node *new_pointer = head;

    printf("this sre the elements in the list\n");

    while (new_pointer != NULL)
    {
        printf(" %d ", new_pointer->data);
        new_pointer = new_pointer->link;
    }

    printf("this is the end of the list\n");
}


void insert_begining(int num)
{
    struct node *new_link = malloc(sizeof(struct node));
    new_link->data = num;

    new_link->link = head;

    head = new_link;
}

int main (void)
{
/*this is a pointer to struct node*/
 struct node *head = NULL;
/*this is the firt node */

/*allocate memory for struct node*/
 head = (struct node *)malloc(sizeof(struct node));

/*head can access the data and ink using arrow operator*/
head->data = 100;
head->link = NULL;

/*this proves that we have succesfully manipulated data*/
printf("%d\n", head->data);

/*this is the second node*/
struct node *current = malloc(sizeof(struct node));
current->data = 200;
current->link = NULL;
head->link = current;

printf("the data in the second node is %d\n", current->data);
/*this is the third node */
/*we can repeat the same methods as above */
/*we can also reuse the current pointer */

current = malloc(sizeof(struct node));
current->data = 300;
current->link = NULL;

/*this is the new part*/
head->link->link = current;



printf("the items in node 3 is %d \n",current->data);

insert_begining(90);
insert_begining(2);
insert_begining(4);


print_list();
return (0);
}
