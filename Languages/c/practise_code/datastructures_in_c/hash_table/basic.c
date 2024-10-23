#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct DataItem {
    int key;
    int value;
} data;

data* hashArray[SIZE];
data* dummyItem;

int hashCodeGenertor (int key){
    return key % SIZE ; 
}

void insert (int key, int data)
{
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->value = data;
    item->key = key;

    int index = hashCodeGenertor(key);

    while (hashArray[index] != NULL && hashArray[index]->key != -1)
    {
        ++index;

        index %= SIZE;
    }
    hashArray[index] = item;
}

int main ()
{
    /**
    int index , index1, index2;
    data data1 = {50, 30};
    data data2 = {2, 50};
    data data3 = {5,1};

    printf("the data is %d, and the key is %d\n", data1.value, data1.key);

    index = hashCodeGenertor(data1.key);
    index1 = hashCodeGenertor(data2.key);
    index2 =hashCodeGenertor(data3.key);
    printf("the key for the data tou have keyed in is %d\n", index);
    printf("the key for the 2nd data tou have keyed in is %d\n", index1);
    printf("the key for the  3rd data tou have keyed in is %d\n", index2);
    */
   dummyItem->key = -1;
   dummyItem->value= -1;

    insert(1, 20);
    insert(14,3);
    insert(31,2); 
    insert(13, 20);
    insert(3, 3);
    insert(11,2); 
    insert(12, 20);
    insert(30,3);
    insert(21,2); 


    return (0);
}