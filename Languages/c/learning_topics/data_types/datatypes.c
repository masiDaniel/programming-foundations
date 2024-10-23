#include <stdio.h>
int main (void)
{
//these are the values
int a= 30;
int b;
// this is the pointer
int *point;
// this is assigning the memory address of a to the pointer
point =&a ;
// here we get the sizes of different data type 
printf("size of char is : %lu \n",sizeof(char));
printf("size of int is : %lu \n",sizeof(int));
printf("size of float is : %lu \n",sizeof(float));
printf("size of double is : %lu \n",sizeof(double));
printf("the size of a pointer is %lu in bytes\n ", sizeof(point));
//here we get to see the memory addresses of the variables declared above
printf("the memory address of a is %p\n ",&a);
printf("the memory address of b is %p\n ",&b);
printf("the memory address of the pointer is %p\n ",&point);
printf("the memory address of a is %p\n ",&a);
//here we get to see the memory address stored in the pointer 
printf("the value contained in point is  %p\n ",point );
// we can see the value inside the memory address sstores in the pointer
printf("the value inside the memory address stores in the pointer is :%d\n", *point);
// below we get to see how pointers woek in real situations 
printf("the value inside a is %d \n",a);
*point = 300;
printf("the value inside a  is %d \n",a);

return (0);
}
