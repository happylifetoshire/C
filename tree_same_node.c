#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int num;
	struct _node* pleft;
	struct _node* pright;
}Node;

typedef struct _tree{
	Node * root;
}Tree;


Tree *creat_tree(void)
{
	Tree *tree=(Tree*)malloc(sizeof(Tree));
	tree->root=NULL;
	return tree;
}

void insert_tree(Tree* tree,int num)
{
	Node *newnode=(Node*)malloc(sizeof(Node));
	newnode->num=num;
	newnode->pleft=NULL;
	newnode->pright=NULL;

	Node* p=(tree->root);
	Node* q;
	if((tree->root)==NULL)
	{
		(tree->root)=newnode;		
	}
	else
	{
		while(p!=NULL)
		{
			q=p;
			if(num<p->num)
				p=p->pleft;
			else if(num>p->num)
				p=p->pright;
		}
		if(num<q->num)
		    q->pleft=newnode;
		else if(num>q->num)	
			q->pright=newnode;	
	}
}



void findnum(Node *root,int num,int*a,int i)
{
	Node *p=root;
	if(p->pleft==NULL&& num<p->num)
	{
		printf("no this num\n");
		return ;
	}
	if(p->pright==NULL&& num>p->num)
	{
		printf("no this num\n");
		return ;
	}
	a[i++]=p->num;
	printf("%d ",p->num);	
	if(num<p->num)
		findnum(p->pleft,num,a,i);
	else if(num>p->num)
		findnum(p->pright,num,a,i);				
	else
	{
		//printf("find out\n");
		return ;
	}	
}

void find_same_node(Node *root,int num1,int num2)
{
		

}

void mid_print_tree(Node *root)
{
	Node *p=root;
	
	if(p)
	{
		mid_print_tree(p->pleft);
		printf("%d ",p->num);
		mid_print_tree(p->pright);
	}
	else
		printf("0 ");
	
}

void pre_print_tree(Node *root)
{
	Node *p=root;
	
	if(p)
	{
		printf("%d ",p->num);
		pre_print_tree(p->pleft);
		pre_print_tree(p->pright);
	}
	else
	{
		printf("0 ");
	}
	
}
void post_print_tree(Node *root)
{
	Node *p=root;
	
	if(p)
	{
		post_print_tree(p->pleft);
		post_print_tree(p->pright);
		printf("%d ",p->num);
	}
	else
	{
		printf("0 ");
	}
	
}
int main()
{
	Tree *tree=creat_tree();
	int i=0;
	int v1[100]={0};
	int v2[100]={0};
	insert_tree(tree,5);
	insert_tree(tree,2);
	insert_tree(tree,4);
	insert_tree(tree,6);
	insert_tree(tree,1);
	insert_tree(tree,8);
	insert_tree(tree,9);
	insert_tree(tree,3);
	pre_print_tree(tree->root);
	printf("\n");
	
	findnum(tree->root,1,v1,i);
	printf("\n");
	i=0;
	findnum(tree->root,4,v2,i);
	printf("\n");
	for(i=0;i<100;i++)
	{
		if(v1[i]!=v2[i])
		{
			printf("%d\n",v1[i-1]);
			return 0;
		}
	}
	return 0;
}




