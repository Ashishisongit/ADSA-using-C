#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
#define size 10

struct DataItem
{
    int data;
    int key;
};
struct DataItem *hashArray[size];

int hashIndex(int key)
{
    return key % size;
}

void insert(int key, int data)
{
    struct DataItem *item = (struct DataItem *)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;
    int Index = hashIndex(key);
    if (hashArray[Index] == NULL)
    {
        hashArray[Index] = item;
        printf(" The Data %d is stored at Index %d Having key %d\n", data, Index, key);
    }
    else
    {
        printf(" The Index %d is Already Occupied by an item.\n", Index);
        free(item);
    }
}
void main()
{
    insert(78, 981);
    insert(45, 478);
    insert(94, 45);
    insert(53, 589);
    insert(45, 845);


    return;
}
