#include <iostream>
using namespace std;
void insert_end();
void insert_start();
void display_list();
void delete_first();
void delete_last();
void display_specific();
void insert_after();
void insert_before();
void delete_after();
void delete_before();

struct record{
	int id;
	float marks;
	record *next= NULL;
};

record *first=NULL;
record *last=NULL;

int main(){
	int option;
	
	do{
		cout<<"\n\n Please enter 1 for insertion at end: ";
		cout<<"\n\n Please enter 2 for insertion at start: ";
		cout<<"\n\n Please enter 3 for deletion at end: ";
		cout<<"\n\n Please enter 4 for deletion at start: ";
		cout<<"\n\n Please enter 5 for display of specific id: ";
		cout<<"\n\n Please enter 6 for insertion after specific id: ";
		cout<<"\n\n Please enter 7 for insertion before specific id: ";
		cout<<"\n\n Please enter 8 for deletion after specific id: ";
		cout<<"\n\n Please enter 9 for deletion before specific id: ";
		cout<<"\n\n Please enter 10 to display list: ";
		cout<<"\n\n Please enter 0 to exit: \n";
		cin>>option;
		switch (option){
			case 1: insert_end();
			break;
			case 2: insert_start();
			break;
			case 3: delete_last();
			break;
			case 4: delete_first();
			break;
			case 5: display_specific();
			break;
			case 6: insert_after();
			break;
			case 7: insert_before();
			break;
			case 8: delete_after();
			break;
			case 9: delete_before();
			break;
			case 10: display_list();
			break;
			
			default:
				cout<<"\n\n Wrong option \n";
		}
	}
	while (option!=0);
	return 0;
}


void insert_end(){
	
	record *curr;
	curr = new record;
	curr->next=NULL;
	
	cout<<"\n\n Enter id: ";
	cin>>curr->id;
	cout<<"\n\n Enter marks: ";
	cin>>curr->marks;
	
	if(first==NULL){
		cout<<"\n\n Before this insertion list was empty ";
		first=last=curr;
		
	}
	else{
		last->next=curr;
		last=curr;
		}	
}



void insert_start(){
	record *curr;
	curr = new record;
	curr->next=NULL;
	
	cout<<"\n\n Enter id: ";
	cin>>curr->id;
	cout<<"\n\n Enter marks: ";
	cin>>curr->marks;
	
	if(first==NULL){
		cout<<"\n\n Before this insertion list was empty ";
		first=last=curr;
	}
	else {
		curr->next=first;
		first=curr;
	}
}

void display_list(){
	record *p=first;
	if(first==NULL){
		cout<<"\n\n List is empty";
	}

	else {

		while(p!=NULL){
			cout<<"\n\n id is: "<<p->id;
			cout<<"\n\n marks is: "<<p->marks;
			p=p->next;
		}
	}
	delete p;
}


void delete_first(){
	if (first==NULL){
		cout<<"\n\n List is empty";
		
	}
	else if (first==last){
		first=NULL;
		last=NULL;
	}
	else{
		first=first->next;
		
		}
	
	
}
void delete_last(){
	record* p=first;
	if (first==NULL){
		cout<<"\n\n List is empty";
	}
	else if(first==last){
		first=NULL;
		last=NULL;
	}
	else{
	
	while(p!=NULL){
		if(p->next->next==NULL){
			p->next=NULL;
			break;
		}
		p=p->next;
	}
}
	delete p;	
}


void display_specific(){
	record *p=first;
	cout<<"\n\n Please enter id to display";
	int required_id;
	cin>>required_id;
	while (p!=NULL){
		if(p->id==required_id){
			cout<<"\n\n id is "<<p->id;
			cout<<"\n\n marks are "<<p->marks;
		}
		p=p->next;
	}
	delete p;
}


void insert_after(){
	
	
	record *p=first;
	record *curr=new record;
	int required_id;
	cout<<"\n\n Enter required id to find: "; 
	cin>>required_id;
	
	cout<<"\n\n Enter id: ";
	cin>>curr->id;
	cout<<"\n\n Enter marks: ";
	cin>>curr->marks;
	
	if (first==NULL){
		cout<<"\n\n List is empty";
	}
	
	else{
		while((p->id!=required_id)&&(p!=NULL)){
			p=p->next;
		}
		if(p==last){
			p->next=curr;
			last=curr;
		}
		else{
			curr->next=p->next;
			p->next=curr;
		}
		
	}
	delete p;
}


void insert_before(){
	
	record *p=first;
	record *k;
	record *curr=new record;
	int required_id;
	cout<<"\n\n Enter required id to find: "; 
	cin>>required_id;
	
	cout<<"\n\n Enter id: ";
	cin>>curr->id;
	cout<<"\n\n Enter marks: ";
	cin>>curr->marks;
	
	if (first==NULL){
		cout<<"\n\n List is empty";
	}
	
	else{
		while((p->id!=required_id)&&(p!=NULL)){
			k=p;
			p=p->next;
		}
		if(p==first){
			curr->next=p;
			first=curr;
			
		}
		else{
			curr->next=p;
			k->next=curr;
		}
		
	}
	delete p,k;
}



void delete_after(){
	record *p=first;
	int required_id;
	cout<<"\n\n Enter required id to find: "; 
	cin>>required_id;
	
	if (first==NULL){
		cout<<"\n\n List is empty";
	}
	else{
		while((p->id!=required_id)&&(p!=NULL)){
			p=p->next;		
		
	}
			if (p->next!=NULL){
				p->next=p->next->next;
			}
			else{
				cout<<"\n\n It is the last id or id does not exists ";
			}
	
		
	}
	delete p;
	
}



void delete_before(){
	record *p=first;
	record *k;
	int required_id;
	cout<<"\n\n Enter required id to find: "; 
	cin>>required_id;
	
	if (first==NULL){
		cout<<"\n\n List is empty";
	}
	else{
		while((p->next->id!=required_id)&&(p!=NULL)){
			k=p;
			p=p->next;		
		
	}
			if (p==first){
				cout<<"\n\n It is first element";
			}
			else{
				k->next=p->next;
			}
	
		
	}
	delete p,k;
	
}
