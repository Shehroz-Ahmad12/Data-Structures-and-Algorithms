#include <iostream>
using namespace std;


void insert();
void display();
bool is_full();
bool is_empty();
void sort();
void recursive_sort(int i);
void SSort(int j,int temp);

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
	
	
void sort(){
	int temp;
	int j;
	for(int i=1;i<=li;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>=temp){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
}	

void recursive_sort(int i){
	int temp;
	int j;
	if (i>li){
		return;
	}
	else{
		temp=arr[i];
		j=i-1;
		SSort(j,temp);
		arr[j+1]=temp;
		
	}
}

void SSort(int j,int temp){
	if(j<0 && arr[j]<temp){
		return;
		
	}
	else{
		arr[j+1]=arr[j];
		j=j-1;
		SSort(j,temp);
	}
	
}
int main(){
	
 	int opt;
 	do
 	{
 		cout<<"\n \n Enter 1 to insert: ";
 		cout<<"\n Enter 2 to display: ";
 		cout<<"\n Enter 3 to sort: ";
 		
 		cout<<"\n Enter option:  ";
 		cin>>opt;
 		switch(opt)
 		{
 			case 1: insert();
 			break;
 			case 2: display();
 			break;
 			case 3: sort();
 			break;
 			case 4: recursive_sort(1);
 			default:
 				cout<<"\n Wrong option";
		 }
 		 		
	 }while(opt!=0);
	
	
	
	return -1;
}
