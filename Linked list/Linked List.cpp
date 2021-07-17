#include <iostream>
using namespace std;
void insert_end();

struct node{
	int id;
	
	node *next=NULL; 
};
node *first=NULL;
node *last=NULL;

int main() {
	
	int n;
	cout<<"Enter number of nodes: ";
	cin>>n;
	
	for(int i=0;i<2;i++){
	
	node *curr;
	curr=new node;
	curr->next=NULL;
	
	cout<<"\n Enter id:   ";
	cin>>curr->id;
	if(first==NULL)
	{
		first=last=curr;
	}
	last->next=curr;
	last=curr;
	
}
	
	for (int i=0;i<n-2;i++){
	node *curr;
	curr=new node;
	curr->next=NULL;
	
	cout<<"\n Enter id:   ";
	cin>>curr->id;
	
	if(first==NULL)
	{
		first=last=curr;
	}
	else{		
		last->next=curr;
		last=curr;
	}
	
	node *p1=first;
	node *p2=first;
	
	p2=p2->next;
	
	if(p2->next!=NULL && p1->next!=NULL){
	
	while(p2->next!=last){
		p1=p1->next;
		p2=p2->next;
	}
	if(p1->id+p2->id>last->id){
			last=p2;
			last->next=NULL;
		}
}
	
	}
	

	return 0;
}

