#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////

void insert_end();
void display();
void insertion_sort();
int countNodes();
void bubble_sort();
void selection_sort();

/////////////////////////////////////////////////////////

struct record{
	int id;
	record *next=NULL; 
	record *prev=NULL;
};
record *first=NULL;
record *last=NULL;

////////////////////////////////////////////////////

int main(){
	int opt;
	do{
		cout<<"\n\n Enter 1 for insertion  ";
		cout<<"\n Enter 2 to display ";
		cout<<"\n Enter 3 to Bubble sort ";
		cout<<"\n Enter 4 to Selection sort ";		
		cout<<"\n Enter 5 to Insertion sort ";
		cout<<"\n Enter 0 to exit";
		cout<<"\n Enter your option: ";
		cin>>opt;
	switch(opt)
	{
		case 1: insert_end();
		break;
		case 2: display();
		break;
		case 3: bubble_sort();	
		break;
		case 4: selection_sort();
		break;
		case 5: insertion_sort();
		break;
		default:
		cout<<"\n Wrong option";
		}	
	}while(opt!=0);

	
	
	return 0;
}

/////////////////////////INSERT////////////////////////////////


void insert_end()
{
	cout<<"\n Insert at end method: ";	
	
		record *curr;
		curr=new record;
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
		
}
///////////////////////DISPLAY//////////////////////////


void display()
{
		cout<<"\n Display method: ";	
		record *p;
		p=first;
		while(p!=NULL)
		{
			cout<<"\n ID is:  "<<p->id;
			
			p=p->next;
		}
}
//////////////////////////////////////////////////
int countNodes(){
	record *p=first;
	int count=0;
	while(p!=NULL){
		p=p->next;
		count++;
	}
	return count;
//	cout<<"\n\n Count: "<<count;
}
//////////////////INSERTION SORT//////////////////////////


void insertion_sort(){
	int temp;
	record *i;
	record *p;
	for(i=first->next;i!=NULL;i=i->next){
		temp=i->id;
		p=i;
		while(p!=NULL && p->prev->id>=temp){
			p->id=p->prev->id;
			p=p->prev;
		}
		p->id=temp;
	}
		
}
/////////////////////////////////////////////////////
void selection_sort(){
	int temp;
	
	int count=countNodes();	
	record *i=first;
	record *min_index;
	record *p;
	
	
	for (i;i!=NULL;i=i->next){
		min_index=i;
	
		for(p=i->next;p!=NULL;p=p->next){
			if(p->id<min_index->id){
				min_index=p;
			}
}
		temp=min_index->id;
		min_index->id=i->id;
		i->id=temp;
}}



/////////////////////////////////////////////


void bubble_sort(){
	
	record *p=first;
	record *q=first;
			
	int temp;
	
	for(p;p->next!=NULL;p=p->next){
		for(q;q!=p;q=q->next){
			if(q->id>q->next->id){
				temp=q->id;
				q->id=q->next->id;
				q->next->id=temp;
			}	
		}
		
	}	
}


