#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root=NULL;

void preorder()
{
    if(root==NULL)
    {
        printf("Empty tree");
        return;
    }

    printf("%d ",root->data);
    printf("%d ",root->left->data);
    printf("%d ",root->right->data);
};


void postorder()
{
    if(root==NULL)
    {
        printf("Empty");
        return;
    }
    printf("\n");

    printf("%d ",root->left->data);
    printf("%d ",root->right->data);
    printf("%d ",root->data);

};

void inorder()
{
    if(root==NULL)
    {
        printf("Empty");
        return;
    }

    printf("\n");

    printf("%d ",root->left->data);
    printf("%d ",root->data);
    printf("%d ",root->right->data);

};



int insert(int val)//20
{
    struct Node *current=malloc(sizeof(struct Node));//a200
    current->data=val;//20
    current->left=NULL;
    current->right=NULL;

    if(root==NULL)
    {
        root=current;
        return;
    }


    if(root->left==NULL)
    {
        root->left=current;
        return;

    }

    if(root->right==NULL)
    {
        root->right=current;
        return;

    }


}

int main()
{


    insert(10);
    insert(20);
    insert(30);

    printf("Preorder");
    preorder(); 

    // root = malloc(sizeof(struct Node));
    // struct Node *second=malloc(sizeof(struct Node));
    // struct Node *third=malloc(sizeof (struct Node));

    // root->data=10;
    // root->left=second;
    // root->right=third;

    // second->data=20;
    // second->right=NULL;
    // second->left=NULL;


    // third->data=30;
    // third->right=NULL;
    // third->left=NULL;

    // preorder();
    // printf("");
    // postorder();
    // inorder();

}