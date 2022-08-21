#include<stdio.h>
#include<stdlib.h>
int flag=0;
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node* NODE;
NODE root=NULL;
NODE temp;
NODE cur;
int item;
void create(int item)
{
    temp=(NODE)malloc(sizeof(NODE));
    temp->info=item;
    temp->llink=temp->rlink=NULL;
}
NODE insert(NODE root,int item)
 {
    NODE prev;
    create(item);
    if(root==NULL)
      {
        root=temp;
        return root;
      }
    prev=NULL;
    cur=root;
    while(cur!=NULL)
     {
        prev=cur;
        if(item==cur->info)
          {
              printf("Duplicate items are not allowed\n");
              free(temp);
              return NULL;
          }
        if(item<cur->info)
          cur=cur->llink;
        else 
          cur=cur->rlink;
     }
    if(item<prev->info)
      prev->llink=temp;
    else
      prev->rlink=temp;
    return root;     
 }
int search(NODE root,int item)
{
    if(root==NULL)
      return 0;
    if(item==root->info)
      return 1;
    if(item<root->info)
      return search(root->llink,item);
    return search(root->rlink,item);
}
void preorder(NODE root)
{
    if(root==NULL)
     return;
    printf("%d\t",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
void inorder(NODE root)
{
    if(root==NULL)
     return;
    inorder(root->llink);
    printf("%d\t",root->info);
    inorder(root->rlink);
}
void postorder(NODE root)
{
    if(root==NULL)
     return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t",root->info);
}
void traversal(NODE root)
{
  int ch;
  printf("\n\t1.preorder\n2.inorder\t3.postorder\n");
    printf("enter the choice\n");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1: preorder(root);
              break;
      case 2: inorder(root);
              break;
      case 3: postorder(root);
              break;
    default:  printf("Wrong choice\n ");
              break;
    }
    printf("\n");
}
void main()
{
    int choice=1,i,n,key;
    printf("\n\tBST Operation\n");
    printf("\n 1.Create\n 2.Insertion\n 3.Search\n 4.Traversal\n 5.Exit\n ");
    while(choice)
    {
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :printf("Enter the no.of nodes\n");
                    scanf("%d",&n); 
                    for(i=0;i<n;i++)
                    { 
                     printf("Your item :\t");
                     scanf("%d",&item);   
                     root=insert(root,item);
                    }
                    break;
            case 2 :printf("Your item :\t");
                    scanf("%d",&item);
                    root=insert(root,item);
                    break;
            case 3 :printf("Your key to be searched\n");
                    scanf("%d",&key);
                    item=search(root,key);
                    if(item==0)
                     printf("Search is unsucessful\n");
                    else
                     printf("Search is sucessful\n");
                    break;
            case 4 :traversal(root);
                    break;
            case 5 :exit(0);
                    break;
            default:printf("Invalid input\n");
        }
        
    }
}