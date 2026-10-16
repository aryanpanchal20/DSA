
#include <stdio.h>
#define size 10

int table[size];

int hashfunction(int key)
{
    return key % size;
}

void insert(int val)
{
    int index = hashfunction(val);

    for(int i = 0; i < size; i++)
    {
        int pos = (index + i) % size;

        if(table[pos] == -1)
        {
            table[pos] = val;
            printf("%d inserted at position: %d\n", val, pos);
            return;
        }

        if(table[pos] == val)
        {
            printf("Key already exists\n");
            return;
        }
    }

    printf("Hash table is full\n");
}

void display()
{
    printf("\nHash table elements:\n");

    for(int i = 0; i < size; i++)
    {
        if(table[i] == -1)
        {
            printf("Position %d: Empty\n", i);
        }
        else
        {
            printf("Position %d: %d\n", i, table[i]);
        }
    }
}

void search(int key)
{
    int index=hashfunction(key);
    for(int i=0;i<size;i++)
    {
        int pos = (index + i) % size;
        
    }

}

int main()
{
    for(int i = 0; i < size; i++)
    {
        table[i] = -1;
    }

    insert(23);
    insert(7);
    insert(12);
    insert(5);

    display();

    return 0;
}
