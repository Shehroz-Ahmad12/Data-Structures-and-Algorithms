//SP19-BCS-032		Shehroz Ahmad
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////

void insert_end();
void display();
void bubble_sort();
void selection_sort();
void insertion_sort();
int countNodes();


/////////////////////////////////////////////////////////

struct record{
	int id;
	record *next=NULL; 
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
		case 4:	selection_sort();
			break;
		case 5:	insertion_sort();
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
/////////////////////BUBBLE SORT////////////////////////////

void bubble_sort(){
	
	record *p=first;
	
	int count=countNodes();
	
	cout<<"\n\n Count: "<<count;		
	int temp;
	
	for(int i=0;i<count;i++){
		for(int j=0;j<count-i-1;j++){
			if(p->id>p->next->id){
				temp=p->id;
				p->id=p->next->id;
				p->next->id=temp;
	
			}	p=p->next;
		}
		p=first;
	}	
}

//////////////////////SELECTION SORT/////////////////////////////

void selection_sort(){
	int temp;
	
	int count=countNodes();	
	record *p=first;
	record *min_index;
	record *q=p;
	
	
	for (int i=0;i<count;i++){
		min_index=p;
		q=p->next;
		for(int j=i+1;j<count;j++){
			if(min_index->id>q->id){
				min_index=q;
					}
				q=q->next;
			}	
					
			temp=min_index->id;
			min_index->id=p->id;
			p->id=temp;
	
			p=p->next;
	}
}


//////////////////INSERTION SORT//////////////////////////////



void insertion_sort(){
	record *p=first;
	
	record *q=first;
	record *c=first;
	
	c=c->next;
	
	while(c!=NULL){
		q=p;
		while(q!=c){
			if(q->id>c->id){
				int temp=c->id;
				c->id=q->id;
				q->id=temp;
			}
			else{
				q=q->next;
			}
		}
		c=c->next;
	}
		
}
///////////////////////////////////////

