//Binary Search Tree  AVL

# include <iostream>
using namespace std;


struct tree{
	int data;
	tree *left=NULL;
	tree *right=NULL;
};
tree *root=NULL;



void insert();
void delete_node(int val);
void preorder_display(tree *p);
void postorder_display(tree *p);
void inorder_display(tree *p);

// Avl tree
int getHeight(tree *p);
int getBalanceFactor(tree *p);
tree* rightRotation(tree *x);
tree* leftRotation(tree *x);
void balanceTree(tree *p);
void preorderBalance(tree *q);
void chekBalanceFactor(tree *p);

int main(){
	int opt;
	int val;
	do{
		cout<<"\n\n Enter 1 for insertion  ";
		cout<<"\n Enter 2 to display preorder ";
		cout<<"\n Enter 3 to display inorder ";
		cout<<"\n Enter 4 to display postorder ";
		cout<<"\n Enter 5 to delete ";	
		cout<<"\n Enter 6 to get height ";
		cout<<"\n Enter 7 to to check balance factor ";
		cout<<"\n Enter 8 to preorder balance ";
		cout<<"\n Enter 9 to preorder balance factor";
		cout<<"\n Enter 0 to exit";
		cout<<"\n Enter your option: ";
		cin>>opt;
	switch(opt)
	{
		case 1: insert();
		break;
		case 2: preorder_display(root);
		break;
		case 3: inorder_display(root);
		break;
		case 4: postorder_display(root);
		break;
		case 5:
			
			cout<<"\n\n Enter value: ";
			cin>>val;
			 delete_node(val);
			break;
			
		case 6: 
		cout<<"\n Height: "<<getHeight(root);
		break;
		case 7: cout<<getBalanceFactor(root);
		break;
		case 8: preorderBalance(root);
		break;
		case 9:chekBalanceFactor(root);
		break;
		default:
			cout<<"\n Wrong option";
				
	}
	}while(opt!=0);
	
	return 0;
	
}


void insert(){
	tree *curr=new tree;
	int val;
	cout<<"\n\n Enter value: ";
	cin>>val;
	curr->data=val;
	
	if(root==NULL){
		root=curr;
	}
	else{
		tree *p=root;
		tree *p1;
		while(p!=NULL){
			p1=p;
			if(val>=p->data){
				p=p->right;
			}
			else{
				p=p->left;
			}
		}
		
		if(curr->data>p1->data){
			p1->right=curr;
		}
		else{
			p1->left=curr;
		}
	}
	
	
}


void preorder_display(tree *p){
	
	if(p!=NULL){
		cout<<"\n Value is: "<<p->data;
		preorder_display(p->left);
		preorder_display(p->right);
	
	}
}

void inorder_display(tree *p){
	
	if(p!=NULL){
		inorder_display(p->left);
		cout<<"\n Value is: "<<p->data;
		inorder_display(p->right);
	}	
}

void postorder_display(tree *p){
	
	if(p!=NULL){
		postorder_display(p->left);
		postorder_display(p->right);
		cout<<"\n Value is: "<<p->data;		
	}
}


void delete_node(int val){
	
	tree *k;
	tree *z;
	z=root;
	while(z!=NULL && val!=z->data){
		k=z;
		if(val>=z->data){
			z=z->right;
		}
		else{
			z=z->left;
		}
	}
	
	if (z==NULL){
		cout<<"\n Value not found";
		return;
	}
	
	if(z==root && z->left==NULL && z->right==NULL){
		root=NULL;
		return;
	}
	
	cout<<"\n k is : "<<k->data;
	cout<<"\n z is : "<<z->data;
	
	if(z->left==NULL && z->right==NULL){
		if(k->left==z){
			k->left=NULL;
		}
		else{
			k->right=NULL;
		}
	}
	
	else if(z->left!=NULL && z->right==NULL){
		if(k->left==z){
			k->left=z->left;
		}
		else{
			k->right=z->left;
		}
	}
	
	else if(z->left==NULL && z->right!=NULL){
		if(k->left==z){
			k->left=z->right;
		}
		else{
			k->right=z->right;
		}
	}
	
	else if(z->left!=NULL && z->right!=NULL){
		tree *p=z;
		p=p->right;
		while(p->left!=NULL){
			k=p;
			p=p->left;
		}	
		z->data=p->data;
		k->left=NULL;
	}
	
}


int getHeight(tree *p){
	if (p==NULL){
		return 0;
		
	}
	else{
		int lHeight=getHeight(p->left);
		int rHeight=getHeight(p->right);
		if (lHeight>rHeight){
			return lHeight+1;
		}
		else{
			return rHeight+1;
		}
	}
}

int getBalanceFactor(tree *p){
	if(p!=NULL){
	
	int balance;
	balance=getHeight(p->left)-getHeight(p->right);
	return balance;
}}

void preorderBalance(tree *q){
	
	if(q!=NULL){	
	balanceTree(q);
	preorderBalance(q->left);	
	preorderBalance(q->right);
}
}


void chekBalanceFactor(tree *p){
	if(p!=NULL){
	
	int b=getBalanceFactor(p);
	cout<<"\n\nNode is: "<<p->data;
	cout<<"\nBalance Factor is: "<<b;
	chekBalanceFactor(p->left);
	chekBalanceFactor(p->right);
}
}



void balanceTree(tree *p){
	
	if(p!=NULL){
	
	int balance=getBalanceFactor(p);
	if(balance<-1){
		if (getHeight(p->left)>getHeight(p->right)){
			p->left=rightRotation(p->left);
		}
		p=leftRotation(p);
	}
	else if(balance>1){
		if(getHeight(p->right)>getHeight(p->left)){
			p->right=leftRotation(p->right);
		}
		p=rightRotation(p);
	
	}}
}


tree* leftRotation(tree *x){
	tree *y=x->right;
	
	x->right=y->left;
	y->left=x;
	if(x==root){
		root=y;
	}
	return y;
	
}

tree* rightRotation(tree *x){
	tree *y=x->left;
	
	x->left=y->right;
	y->right=x;
	if(x==root){
		root=y;
	}
	
	return y;
	
}
