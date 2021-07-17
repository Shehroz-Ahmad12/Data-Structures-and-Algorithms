//		Name 	:	Shehroz Ahmad
//		Reg.no.:	Sp19-BCS-032


#include <iostream>
using namespace std;

void display();
void reverse_print();
void reverse();
void palindrome();
void swap_values();
void swap_nodes();


struct record{
	int id;
	record *next=NULL;
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
	first = last = curr;
	if (n>1){
	
		for (int i=2;i<=n;i++){
			
			
			curr=new record;
			last->next=curr;
			last=curr;
			cout<<"\n\n Enter id: ";
			cin>>id1;
			curr->id=id1;		
		}}
		
	curr->next=NULL;
	
	int opt;
	do{
		
		cout<<"\n\n\n\n Enter 0 to display: ";
		cout<<"\n\n Enter 1 to print reverse: ";
		cout<<"\n\n Enter 2 to reverse list: ";
		cout<<"\n\n Enter 3 to check palindrome: ";
		cout<<"\n\n Enter 4 to swap values: ";
		cout<<"\n\n Enter 5 to swap nodes: ";
		cout<<"\n\n Enter 6 to exit: ";
		cin>>opt;
		switch(opt){
			case 0:display();
			break;
			case 1:reverse_print();
			break;
			case 2:reverse();
			break;
			case 3:palindrome();
			break;
			case 4:swap_values();
			break;
			case 5:swap_nodes();
			break;
			case 6:cout<<"\nSign off";
			break;
			default: cout<<"\n\n Wrong input";
				
		}
	}while(opt!=6);

//	display();
//	swap_nodes();
//	reverse();
//	reverse_print();
//	palindrome();
//	swap_values();



	return 0;
}

void display(){
	record *p = first;
	while(p!=NULL){
		cout<<"\n\n id is: "<<p->id;
		cout<<"\n "<<p->next;
		p=p->next;
	}
}

void reverse_print(){
	record *p=last;
	record *k=first;
	while (p!=first){
		if(k->next==p){
			cout<<"\n\n id is: "<< p->id;
			p=k;
			k=first;}
		else{
			k=k->next;
			
		}}
	cout<<"\n\n id is: "<<k->id;
}

void reverse(){
	record *pl=last;
	record *p=first;
	
	int n=0;
	while (p!=NULL){		//Counting Nodes
		p=p->next;
		n++;
	}
	p=first;
	for (int i=n;i>0;i--){
		p=first;
		for(int j=i-1;j>0;j--){
			p=p->next;
		}
		pl->next=p;
		pl=p;
	}
	record *temp=first;		//Setting last and first
	first=last;
	last=temp;
	last->next=NULL;
}


void palindrome(){

	record *po=first;
	record *pf=first;
	bool b=true;
	int n=0;
	while (po!=NULL){		//Counting Nodes
		po=po->next;
		n++;
	}
	
	po=first;
	for (int i=0;i<n;i++){
		pf=first;
		for (int j=0; j<n-1-i; j++ ){
			pf=pf->next;
			
		}
		if (po->id!=pf->id){
			b=false;
			}
		po=po->next;
		
	}
	if (b==true){
		cout<<"\n\n palindrome";
		
	}
	else{
		cout <<"\n\n not palindrome";
	}
}



void swap_values(){
	
	record *p=first;
	int x,y;
	cout<<"\n\n Please Enter Value for x: ";
	cin>>x;
	cout<<"\n\n Please Enter Value for y: ";
	cin>>y;
	record *p1;
	record *p2;
	while(p!=NULL){
		if(p->id==x){
			p1=p;
		}		
		if (p->id==y){
			p2=p;
		}
		p=p->next;
	}
	p1->id=y;
	p2->id=x;	
	}
	

	
void swap_nodes(){
	int x,y;
	cout<<"\n\n Please Enter first position for x: ";
	cin>>x;
	cout<<"\n\n Please Enter second position for y: ";
	cin>>y;
	
	record *po=first;
	record *pf=first;
	record *k=po;		
	record *m=pf;
	
	for (int i=1;i<x;i++){		//Searching required nodes on position
		k=po;
		po=po->next;			//	k and m are previous nodes of required nodes
	}
	
	for (int i=1;i<y;i++){
		m=pf;
		pf=pf->next;
	}
		m->next=po;
		k->next=pf;
		k=pf->next;
		pf->next=po->next;
		po->next=k;
		
		if (po==first){		//Resetting first and last
			first=pf;
		}
		if (pf==last){
			last=po;
		}
	}	
