#include<stdio.h>
#include<malloc.h>
struct node {
    int data;
    struct node *left,*right;
};
//create//
struct node *create(struct node *root)
{
    struct node *p=NULL,*temp=NULL;
    int i,n;
    printf("enter how many values");
    scanf("%d",&n);
    printf("enter actual value");
    for(i=0;i<n;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->left=p->right=NULL;
        if(root==NULL)
        root=p;
        else{
            temp=root;
            while(temp!=NULL)
            {
                if(p->data<temp->data)
                {
                    if(temp->left==NULL)
                    {
                        temp->left=p;
                        break;
                        
                        temp=temp->left;
                    }}
                    else if(p->data>temp->data)
                    {
                        if(temp->right==NULL)
                        {
                            temp->right=p;
                            break;
                        }
                        else temp=temp->right;
                    }
                
            }
        }
    }
    return(root);
}
//insert//
struct node *insert(struct node *root)
{
    struct node *p=NULL,*temp=NULL;
    printf("enter the value to insert");
    p=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&p->data);

p->left=p->right=NULL;
if(root==NULL)
root=p;
else{
    temp=root;
    while(temp!=NULL)
    {
        if(p->data<temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left=p;
                break;

            }
            else temp=temp->left;

        }
        else if(p->data>temp->data)
        {
            if(temp->right==NULL)
            {
                temp->right=p;
                break;

            }
            else
            temp=temp->right;
        }
    }
}
return(root);
}
//inorder//
void inorder(struct node *root)
{
    struct node *ptr=NULL;
    ptr=root;
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d",ptr->data);
        inorder(ptr->right);
    }
}
//preorder//
void preorder(struct node *root)
{
    struct node *ptr=NULL;
    ptr=root;
    if(ptr!=NULL)
    {
        printf("%d",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
//postorder//
void postorder(struct node *root)
{
    struct node *ptr=NULL;
    ptr=root;
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d",ptr->data);
    }
}
//count//
int totalnodes(struct node *root)
{
    struct node *ptr=NULL;
    ptr=root;
    static int c=0;
    if(ptr==NULL)
    return 0;
    else{
        totalnodes(ptr->left);
        c++;
        totalnodes(ptr->right);
    }
    return c;
    
}
//leaf countt//
int leafcount(struct node *root)
{
    static int l=0;
    if(root!=NULL)
    {
        leafcount(root->left);
    if(root->left==NULL&&root->right==NULL)
    l++;
    leafcount(root->right);
}
return 1;
}
//nonleaf count//
int nonleafcount(struct node *root)
{
    static int l=0;
    if(root==NULL||root->left==NULL&&root->right==NULL)
    return 0;
    else{
        l++;
    }
    nonleafcount(root->left);
    nonleafcount(root->right);
}
//copy a tree
struct node *treecopy(struct node *root)
{
    struct node *p=NULL;
    if(root==NULL)
    return NULL;
    else{
        p=(struct node *)malloc(sizeof(struct node));
        p->data=root->data;
        p->left=treecopy(root->left);
        p->right=treecopy(root->right);
        return p;
    }
}
//mirror imagr of tree//
void mirror(struct node *root)
{
    struct node *p=NULL;
    if(root==NULL)
    return;
    else
    p=root->left;
    root->left=root->right;
    root->left=p;
    mirror(root->left);
    mirror(root->right);
}
//compare two list//
int isequaltree(struct node *t1,struct node *t2)

{
    if(t1==NULL&&t2==NULL)
    {
        return 1;
    }
    return(t1==t2)&&(t1->data==t2->data)&&isequaltree(t1->left,t2->left)&&isequaltree(t1->right,t2->right);

}
//c height//
int cheight(struct node *p)
{
    int ll,rl;
    if(p==NULL)
    return 0;
    else{
        ll=cheight(p->left);
        rl=cheight(p->right);
        if(ll>rl)
        return(ll+1);
        else
        return(rl+1);
    }
}
//print level//
int printlevel(struct node *root,int l)
{
    if(root==NULL)
    return 0;
    if(l==1)
    printf("%d",root->data);
    else if(l>1)
    {
        printlevel(root->left,l-1);
        printlevel(root->right,l-1);
    }
}
//print level wise//
void printlevelwise(struct node *root)
{
    int h,i;
    h=cheight(root);
    printf("the height of tree is %d",h);
    printf("the level wise node are:");
    i=1;
    do{
        printf("%d",i);
        printlevel(root,i);
        i++;
    }
    while(i<=h);

}
//print c level//
int printclevel(struct node *root,int l)
{
    if(root==NULL)
    return 0;
    if(l==1)
    return 1;
    return(printclevel(root->left,l-1)+printclevel(root->right,l-1));
}