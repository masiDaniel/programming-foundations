#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 6

int array[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

bool isFull(){
    return itemCount == MAX;
}

bool isEmpty(){
    return itemCount == 0;
}

int removeData(){
    int data = array[front++];
    if (front == MAX){
        front = 0;
    }

    itemCount--;
    return data;
}

void insert(int data){
    if (!isFull())
    {
        if (rear == MAX - 1)
        {
            rear = -1;
        }

        array[++rear] = data;
        itemCount++;
    }
}


int main (){
    insert(1);
    insert(3);
    insert(0);
    insert(20);

    while (!isEmpty())
    {
        int n = removeData();
        printf("%d ", n);
    }
    printf("\n");
    if (isEmpty())
    {
        printf("the queue is empty\n");
        // return (0);
    }

    insert(1);
    insert(2);
    insert(3);
    insert(4);

    while (!isEmpty())
    {
        int n = removeData();
        printf("%d ", n);
    }
    return (0);
}