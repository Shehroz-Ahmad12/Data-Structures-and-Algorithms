#include <iostream>
using namespace std;


void insert();
void display();
bool is_full();
bool is_empty();
void mergeDiv(int arr[],int li,int ri);
void merge(int arr[],int li,int m,int ri);

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
	
void merge(int a[],int first,int mid,int last){
	int firstA=first, lastA=mid, firstB=mid+1, lastB=last, i=first;
	int temp[last+1];	
	while(firstA<=lastA && firstB<=lastB){
		if(a[firstA]<a[firstB]){
			temp[i]=a[firstA];
			firstA++;
		}else{
			temp[i]=a[firstB];
			firstB++;
		}
		i++;
	}
	while(firstA<=lastA){
		temp[i]=a[firstA];
		firstA++;
		i++;
	}
	while(firstB<=lastB){
		temp[i]=a[firstB];
		firstB++;
		i++;
	}
	
	i=first;
	while(i<=last){
		a[i]=temp[i];
		i++;
	}
}

void mergeDiv(int a[],int first,int last){
	int mid;
	if(first<last){
		mid = (first+last)/2;
		mergeDiv(a,first,mid);
		mergeDiv(a,mid+1,last);
		merge(a,first,mid,last);
		
	}
	//merge(a,first,mid,last);
	
	
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
 			case 3: mergeDiv(arr,0,5);
 			break;
 			default:
 				cout<<"\n Wrong option";
		 }
 		 		
	 }while(opt!=0);
	
	
	
	return -1;
}
