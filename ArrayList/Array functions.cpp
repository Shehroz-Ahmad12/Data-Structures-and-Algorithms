#include<iostream> 
using namespace std; 
void insert();
void display(); 
bool is_full();
bool is_empty();
void del_start();
void del_end();
void shift_left(int si, int li);
int arr[10]; 
int si=-1, li=-1, size=10;

int main() 
	{
 	int opt;
 	do
 	{
 		cout<<"\n Enter 1 to insert: ";
 		cout<<"\n Enter 2 to display: ";
 		cout<<"\n Enter 3 to delete value from start";
 		cout<<"\n Enter 4 to delete value from end";
 		cout<<"\n Enter 5 to insert at start";
 		cout<<"\n Enter 6 to insert after specific";
 		cout<<"\n Enter 7 to delete after specific";
 		cout<<"\n Enter 8 to insert before specific";
 		cout<<"\n Enter 9 to delete before specific";
 		cout<<"\n Enter 0 to exit ";
 		
 		cin>>opt;
 		switch(opt)
 		{
 			case 1: insert();
 			break;
 			case 2: display();
 			break;
 			case 3: del_start();
 			break;
 			case 4: del_end();
 			break;
 			default:
 				cout<<"\n Wrong option";
		 }
 		 		
	 }while(opt!=0);

   return 1; 
   } 
   
   
void insert() 
	{ 
	if(!is_full())
	{
	cout<<"\n Starting index: si "<<si<<"  last index: li is: "<<li;
	if(si==-1)
	{
		si=li=0;
	}else if(li<size-1){
	
	
		li+=1;
	}else{
		shift_left(si, li);
		si--;
		}
	cout<<"\n Enter value in li index: ";
	cin>>arr[li];
	}else{
		cout<<"\n Array is already full";
	}	
	}

void display()
	{
	cout<<"\n In display method";	
	for(int i=si; i<=li; i++)
		{
			cout<<"\n Value in "<<i<<" index";
			cout<<" is: "<<arr[i];
		}
	}



void del_start()
{
	if(!is_empty())	
	{
		cout<<"\n value to be deleted is: "<<arr[si];
		if(si==li)
		{
			si=li=-1;
		}else{
			si++;
		}
		
	}else{
		cout<<"\n Array is already empty";
	}
}

void del_end()
{
	if (!is_empty){
		li--;
	}
	else{
		cout<<"\n Array is already empty";
	}
	
}

void insert_after(){
	if(is_full){
		cout<<"\n There is no space";
	}
	else if(is_empty){
		cout<<"\n Array is empty";
	}
	else{
		
	}
}

void shift_left(int si, int li)
{
  for(int i=si; i<=li; i++)
  {
  	arr[i-1]=arr[i];
	  }	
}

bool is_full()
{
	if(si==0 && li==size-1)
	{
		return true;
		}else{
			return false;
		}
}

bool is_empty()
{
	if(si==-1)
	{
		return true;
	
	}else {
		return false;
	}
}
