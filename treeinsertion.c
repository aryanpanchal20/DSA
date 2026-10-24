#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root=NULL;

struct Node *createNode(int val)
{
    struct Node *newnode = malloc(sizeof(struct Node));

    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

void insert(int val)
{
    struct Node *newnode = createNode(val);

    if(root==NULL)
    {
        root=newnode;
        return;
    }

 struct Node **queue=malloc(1000*sizeof(struct Node *));

 int front=0,rear=0;

 queue[rear++]=root;

 while(front<rear)
 {
    struct Node *temp=queue[front++];

    if(temp->left==NULL)
    {
        temp->left=newnode;
        free(queue);
        return;
    }

    queue[rear++]=temp->left;

    if(temp->right==NULL)
    {
        temp->right=newnode;
        free(queue);
        return;
    }

    queue[rear++]=temp->right;
 }

 free(queue);
}


void preorder(struct Node *node)
{
    if(node==NULL)
    {
        return;
    }

    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node *node)
{
    if(node==NULL)
    {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);
}

void inorder(struct Node *node)
{
    if(node==NULL)
    {
        return;
    }

    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);

}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);

}