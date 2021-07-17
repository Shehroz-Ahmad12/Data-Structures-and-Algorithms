#include <iostream>
using namespace std;


void josepheusProblem();


struct record{
	int id;
	record *next=NULL;
};

record *first=NULL;
record *last=NULL;

void josepheusProblem(){
	int pos;
	cout<<"\n Enter position: ";
	cin>>pos;
	record *p=first;
	
	int count=1;
	while(count!=pos){
			p=p->next;
			count++;
		}
	while(p->next!=p){
		p->next=p->next->next;
		p=p->next;
		
				
	}
	cout<<"\n Result is ";
		cout<<p->id;
	}


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
	last = first= curr;
	last->next=last;
	if (n>1){
	
		for (int i=2;i<=n;i++){
			
			
			curr=new record;
			last->next=curr;
			last=curr;
			cout<<"\n\n Enter id: ";
			cin>>id1;
			curr->id=id1;		
		}}
		
	curr->next=first;
	
	josepheusProblem();	
	return 0;
}
