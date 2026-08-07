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
   int n , key , data;
    printf("Enter the Number of Elements : ");
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
    printf("\nEnter the Key and the Data of Element %d: ",i+1);
    scanf("%d %d",&key ,&data);
    insert(key,data);
    }    
    return;
}
