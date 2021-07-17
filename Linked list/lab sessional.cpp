#include<iostream>
using namespace std;
void ins();
void del();
void display();

struct record{
	int id;
	record *next=NULL;
	record *prev=NULL;
};
record *first=NULL;
record *last=NULL;

int main(){
	
	int n;
	int id1;
	cout<<"\n\n Enter number of nodes: ";
	cin>>n;
	
	record *curr;
	curr=new record;
	cout<<"\n\n Enter id: ";
	cin>>id1;
	curr->id=id1;
	curr->prev=NULL;
	first = last = curr;
	if (n>1){
	
		for (int i=2;i<=n;i++){
			
			
			curr=new record;
			last->next=curr;
			curr->prev=last;
			last=curr;
			cout<<"\n\n Enter id: ";
			cin>>id1;
			curr->id=id1;		
		}}
		
	curr->next=NULL;
	
//	ins();
	
	del();
	display();
return 0;	
};


void ins(){
	record *p=last;
	record *curr=new record;
	
	curr->prev=last;
	last->next=curr;
	curr->id=(p->id)+(p->prev->id);
	last=curr;
	last->next=NULL;
}

void display(){
	record *p=first;
	while(p!=NULL){
		cout<<"\n\n id is: "<<p->id;
		p=p->next;
	} 
}

void del(){
	record *p=first->next;	
	while (p->next!=NULL){
		if (p->id==(p->next->id)+(p->prev->id)){
			p->prev->next=p->next;
			p->next->prev=p->prev;
			p=p->next;
		}
		p=p->next;
	}
	
}
