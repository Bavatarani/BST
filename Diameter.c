#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tnode  {
	int data;
	struct tnode * leftc;
	struct tnode * rightc;
};

void insert(struct tnode **, int num);
void inorder(struct tnode * s);
int max(int a, int b);
int height(struct tnode* node);
int diameter(struct tnode * tree);

int main()  {
	struct tnode * root=NULL;
	char ch[5];
	int num;
	do {
		printf("Enter the element to be inserted in the tree\n");
		scanf("%d",&num);
		insert(&root, num);
		printf("Do you want to insert another element?\n");
		scanf("%s",ch);
	}while(strcmp(ch,"yes")==0);

	printf("The elements in the tree are");
	inorder(root);
	printf("\n");
	printf("The diameter of the tree is %d\n",diameter(root));
	return 0;
}

void insert(struct tnode ** s, int num) {
	/*---------Fill your code here-------------*/
	struct tnode *nn =(struct tnode*)malloc(sizeof(struct tnode));
	nn->data=num;
	nn->leftc=NULL;
	nn->rightc=NULL;
	if(*s==NULL)
	{
	    *s=nn;
	}
	else
	{
	    struct tnode *temp=*s,*prev;
	    while(temp!=NULL)
	    {
	        prev=temp;
	        if(temp->data<num)
	        {
	            temp=temp->rightc;
	        }
	        else
	        {
	            temp=temp->leftc;
	        }
	    }
	    if(prev->data<num)
	    {
	        prev->rightc=nn;
	    }
	    else
	    {
	        prev->leftc=nn;
	    }
	}
}
void inorder(struct tnode *s)
{
    if(s!=NULL){
    inorder(s->leftc);
    printf("%d",s->data);
    inorder(s->rightc);
    }
}

int diameter(struct tnode * tree)  {
/*---------Fill your code here-------------*/
    if(tree==NULL)
    {
        return 0;
    }
    else
    {    
        int lh=height(tree->leftc);
        int rh=height(tree->rightc);
        int ld=diameter(tree->leftc);
        int rd=diameter(tree->rightc);
        return max((lh+rh+1),max(ld,rd));
    }
}
 

int height(struct tnode* node)  {
/*---------Fill your code here-------------*/
    if(node==NULL)
    {
     return 0;   
    }
    else
    {
     return 1+max(height(node->leftc),height(node->rightc));
    }
} 

int max(int a, int b)  {
  return (a >= b)? a: b;
}
