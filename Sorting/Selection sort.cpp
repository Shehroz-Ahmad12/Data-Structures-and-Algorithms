#include <iostream>
using namespace std;


void insert();
void display();
bool is_full();
bool is_empty();
void sort();
void second(int i,int j,int min_index);

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
	int min_index;
	int temp;
	for (int i=0;i<=li;i++){
		min_index=i;
		for(int j=i+1;j<=li;j++){
			if(arr[j]<arr[min_index]){
				min_index=j;
			}
			
			temp=arr[min_index];
			arr[min_index]=arr[i];
			arr[i]=temp;
		}
		
	}	
}

void recursive_sort(int i,int j){
	
	int min_index;
	int temp;
	if(i>li){
		return;
	}
	else{
		second(i,i+1,min_index);
		temp=arr[min_index];
		arr[min_index]=arr[i];
		
		arr[i]=temp;
		recursive_sort(i++,i+1);
	}
	
}	

void second(int i,int j,int min_index){
	if(j>li){
		return;
	}
	else{
		if (arr[j]<arr[min_index]){
			min_index=j;
		}
		else{
			second(i,j++,min_index);
		}
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
 			case 4: recursive_sort(0,1);
 			break;
 			default:
 				cout<<"\n Wrong option";
		 }
 		 		
	 }while(opt!=0);
	
	
	
	return -1;
}
