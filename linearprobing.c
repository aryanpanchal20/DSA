#include<stdio.h>
#define size 10

int table[size];

int hash(int key)
{
    return key%size;

}

void insert(int val)
{
    int index=hash(val);

    for (int i=0 ;i<size;i++)
    {
        int pos=(index+i)%size;

        if(table[pos]==-1)
        {
            table[pos]=val;

            printf("%d Value inserted at pos  %d\n",val,pos);
            return;

        }

        if(table[pos]==val)
        {
             printf("keyy is already exits");
             return;
        }



    }

    printf("hash table  is fulled\n");

}


void display()
{

    printf("hash tabl elemnt \n");
  for(int i=0;i<size;i++)
  {
    if(table[i]==-1)
    {
        printf("elemnt is 0\n");

    }else{

        printf("%d\n",table[i]);
    }
    


  }


}
void search(int val)
{
    int index = hash(val);

    for (int i = 0; i < size; i++)
    {
        int pos = (index + i) % size;

        if (table[pos] == val)
        {
            printf("Element found at index %d\n", pos);
            return;
        }
    }

    printf("Element not found\n");
}


int main()
{

     for(int i=0;i<size;i++)
     {

        table[i]=-1;
     }
    insert(23);
    insert(43);
    insert(45);
    insert(55);
    


    search(45);
    display();
}