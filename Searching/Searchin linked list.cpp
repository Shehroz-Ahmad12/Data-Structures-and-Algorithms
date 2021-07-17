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
void search();
bool recursiveSearch(stu *p,int n,int index);

int main() {
	int opt;
	do{
		cout<<"\n\n Enter 1 for insertion  ";
		cout<<"\n Enter 2 to display ";
		cout<<"\n Enter 3 to search ";
		cout<<"\n Enter 4 to search recursive ";
		cout<<"\n Enter 0 to exit";
		cout<<"\n Enter your option: ";
		cin>>opt;
	switch(opt)
	{
		case 1: insert_end();
		break;
		case 2: display();
		break;
		case 3: search();
		break;
		case 4:
			int index;
			index=1;
			stu *p;
			p=first;
			int n;
			cout<<"\n Enter value to search: ";
			cin>>n;
			cout<<recursiveSearch(p,n,index);
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

void search(){
	int x;
	cout<<"\n Enter id to find: ";
	cin>>x;
	bool find=false;
	stu *p=first;
	int index=1;
	while(p!=NULL && find==false){
		if(p->id==x){
			find=true;
		}
		else{
			p=p->next;
			index++;
		}
	}
	if(find==true){
		cout<<"Value found at index: "<<index;
	}
	else{
		cout<<"Value Not Found";
	}
	
}

bool recursiveSearch(stu *p,int n,int index){
	if(p->id==n){
		cout<<"\nValue found at index "<<index<<"\n";
		return true;		
	}
	else if(p->next==NULL){
		cout<<"Value not found!!\n";
		return false;
	}
	else{
		return recursiveSearch(p->next,n,++index);
	}
}
