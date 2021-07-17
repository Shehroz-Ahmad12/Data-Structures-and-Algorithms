#include <iostream>
using namespace std;


void insert();
void display();
bool is_full();
bool is_empty();
void bubble_sort();
void swap(int i,int j);

int si=-1, li=-1;
int size=10;
int arr[10];


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
	}}
	
	
void bubble_sort(){
	int temp;
	for(int i=0;i<=li;i++){
		for (int j=0;j<=li-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}	

}	
void bubble_recursive(int i,int j){
	
	if(i>li){
		return;
	}
	else{	
		if (j>li-i){
			j=0;
			bubble_recursive(i++,j);
			
		}	
		else{
			
			swap(i,j++);
		}	
			
			}
		
	}


void swap(int i,int j){
		if(j>li-i){
			return;
		}
		
		else{
		
		if(arr[j]>arr[j+1]){
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
		swap(i,++j);
		}
	
}

int main(){
	
 	int opt;
 	do
 	{
 		cout<<"\n \n Enter 1 to insert: ";
 		cout<<"\n Enter 2 to display: ";
 		cout<<"\n Enter 3 to bubble sort: ";
 		cout<<"\n Enter 4 to bubble recursive sort: ";
  		cout<<"\n Enter option:  ";
 		cin>>opt;
 		switch(opt)
 		{
 			case 1: insert();
 			break;
 			case 2: display();
 			break;
 			case 3: bubble_sort();
 			break;
 			case 4: bubble_recursive(0,0);
 			break;
 			default:
 				cout<<"\n Wrong option";
		 }
 		 		
	 }while(opt!=0);
	
	
	
	return -1;
}
