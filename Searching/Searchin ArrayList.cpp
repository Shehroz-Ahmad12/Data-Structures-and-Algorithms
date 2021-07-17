//SP19-BCS-032		Shehroz Ahmad
#include <iostream>
using namespace std;


void insert();
void display();
bool is_full();
bool is_empty();
void search(int x);
bool recursiveSearch(int n,int x);
int binarySearch(int x);
int binarySearchRecursive(int sti,int lti,int x);


int si=-1, li=-1, size=10;
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
	
void search(int x){
	
	bool find=false;
	int i=si;
	while(i<=li && find==false ){
		if(arr[i]==x){
			find=true;
		}
		else{
			i++;
		}
	}
	if (find==true){
	
		cout<<"\n Value find at index: "<<i;
}
	else{
		cout<<"\nNot found";
	}	
}	
bool searchRecursive(int n,int x){
	if(arr[n]==x){
		cout<<"\n\nValue found at index: "<<n<<"\n";
		return true;
	}
	else if(n==size-1){
		cout<<"\n\nValue Not Found\n ";
		return false;
		
	}
	else{
		return searchRecursive(n+1,x);
	}
}

int binarySearch(int x){
	bool f=false;
	int sti,lti;
	sti =si;
	lti=li;
	
	while(sti<=lti){
		int mid=(sti+lti)/2;	
		if(arr[mid]==x){
			f=true;
			cout<<"\n value found at: ";	
			return mid;
		}
		else if(arr[mid]<x){
			sti=mid+1;
		}
		else if(arr[mid]>x){
			lti=mid-1;
		}}
		if (f==false){
			return -1;
		}
		
		
}

int binarySearchRecursive(int sti,int lti,int x){
	bool f=false;
	int mid=(sti+lti)/2;
	
	if(arr[mid]==x){
		cout<<"\n\nValue found at index: ";
		return mid;
	}
	else{
		if(sti==lti){
			cout<<"\n\nValue not found";
			return -1;}
		
		else if(arr[mid]<x){
			return binarySearchRecursive(mid+1,lti,x );
		}
		else if(arr[mid]>x){
			return binarySearchRecursive(sti,mid-1,x);
			}	}
}


int main(){
	int val;
 	int opt;
 	do
 	{
 		cout<<"\n \n Enter 1 to insert: ";
 		cout<<"\n Enter 2 to display: ";
 		cout<<"\n Enter 3 to search: ";
 		cout<<"\n Enter 4 to Recursive search: ";
 		cout<<"\n Enter 5 to Binary search: ";
 		cout<<"\n Enter 6 to Binary Recursive search: ";
 		cout<<"\n Enter option:  ";
 		cin>>opt;
 		switch(opt)
 		{
 			case 1: insert();
 			break;
 			case 2: display();
 			break;
 			case 3:
				cout<<"\n Enter element to find in List: \n";
				cin>>val;
				search(val);
	 			break;
 			case 4:
	 			cout<<"\nEnter element to search: ";
	 			cin>>val;
	 			cout<< searchRecursive(0,val);
	 			break;
 			case 5:
 				
 				cout<<"\nEnter element to search: ";
 				cin>>val;
 				cout<<binarySearch(val);
 				break;
 			case 6:
 				int val;
 				cout<<"\nEnter element to search: ";
 				cin>>val;
 				cout<<binarySearchRecursive(si,li,val);
				break;
 			default:
 				cout<<"\n Wrong option";
		 }
 		 		
	 }while(opt!=0);
	
	return -1;
}

