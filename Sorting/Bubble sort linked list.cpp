//SP19-BCS-032		Shehroz Ahmad
#include <iostream>
using namespace std;


struct stu{
	int id;
	
	stu *next=NULL; 
};
stu *first=NULL;
stu *last=NULL;

void insert_end();
void display();

void bubble_sort(int count);

int main() {
	int opt;
	do{
		cout<<"\n\n Enter 1 for insertion  ";
		cout<<"\n Enter 2 to display ";
		cout<<"\n Enter 3 to search ";
	
		cout<<"\n Enter 0 to exit";
		cout<<"\n Enter your option: ";
		cin>>opt;
	switch(opt)
	{
		case 1: insert_end();
		break;
		case 2: display();
		break;
		case 3: 
		int count;
		count=0;
		stu *p1=first;
		while(p1!=NULL){
			count++;
			p1=p1->next;
		}
		
		cout<<"\n Count is: "<<count;
		
		
		break;
		default:
		cout<<"\n Wrong option";
		}	
	}while(opt!=0);

	return 0;
}

void insert_end()
{
	cout<<"\n Insert at end method: ";	
	
		stu *curr;
		curr=new stu;
		curr->next=NULL;
		
		cout<<"\n Enter id:   ";
		cin>>curr->id;
		
		
	if(first==NULL)
	{
		cout<<"\n Before this insertion the list is empty";
		first=last=curr;
		cout<<"\n After insertion first points: "<<first->id;
			cout<<"\n After insertion last points: "<<last->id;		
	}	
	else{
		cout<<"\n First pointer points to:  "<<first->id;
		cout<<"\n Last pointer points to:  "<<last->id;
		last->next=curr;
		last=curr;
		cout<<"\n After insertion:";
		cout<<"\n First pointer points to:  "<<first->id;
		cout<<"\n Last pointer points to:  "<<last->id;
		}		
		
}
void display()
{
		cout<<"\n Display method: ";	
		stu *p;
		p=first;
		while(p!=NULL)
		{
			cout<<"\n ID is:  "<<p->id;
			
			p=p->next;
		}
}



void bubble_sort(int count){
	int temp;

	stu* p=first;

	
	cout<<"count is"<<count;
	p=first;
	stu* q=p->next;
	for(int i=0;i<=count;i++){
		for(int j=0;j<=count-i;j++){
			if(p->id<q->id){
				temp=p->id;
				p->id=q->id;
				q->id=temp;
			}p=p->next;
			q=q->next;
		}
		p=first;
		q=p->next;
	}
	
}



