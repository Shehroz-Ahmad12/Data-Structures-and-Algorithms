//Shehroz Ahmad    SP19-BCS-032
#include <iostream>
using namespace std;

void insertionSort(int size);
void selectionSort(int size);
void bubbleSort(int size);
void display(int size);

void bubbleRecursion(int size,int i,int j);
void swapBubble(int size,int i,int j);

void selectionRecursion(int size,int i,int j);

void insertionRecursion(int size,int i,int j);
void shift(int size, int i,int j,int temp);

void mergeSort(int arr[],int first,int last);
void merge(int arr[],int first,int mid,int last);

int arr[8]={6,13,1,16,2,7,11,20};


int main(){
	int size=8;
	int opt;
	do {
		cout<<"\n\nEnter 1 to display ";
		cout<<"\nEnter 2 to bubble sort ";
		cout<<"\nEnter 3 to selection sort ";
		cout<<"\nEnter 4 to insertion sort ";
		cout<<"\nEnter 5 to merge sort ";
		cout<<"\nEnter 6 to bubble sort using recursion ";
		cout<<"\nEnter 7 to selection sort using recursion ";
		cout<<"\nEnter 8 to insertion sort using recursion \n";
		cin>>opt;
		switch(opt){
			case 1:display(size);
				break;
			case 2:bubbleSort(size);
				break;
			case 3:selectionSort(size);
				break;
			case 4:insertionSort(size);
				break;
			case 5:mergeSort(arr,0,7);
				break;
			case 6:bubbleRecursion(size,0,0);
				break;
			case 7:selectionRecursion(size,0,1);
				break;
			case 8:insertionRecursion(size,1,0);
				break;
			default:
				cout<<"\n Wrong option ";
			
			
		}
				
		
	}while(opt!=0);
	
	return -1;
	
}
///////////////////////BUBBLE SORT////////////////////////

void bubbleSort(int size){
	
	int temp;
	for(int i=0;i<size;i++){
		for (int j=0;j<size-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}	
}

/////////////////////RECURSIVE BUBBLE SORT/////////////////////


void bubbleRecursion(int size,int i,int j){
	if (i==size-1){
		return;
	}
	else{			
			swapBubble(size,i,j);
			i++;j=0;
			bubbleRecursion(size,i,j);
	}	
}


void swapBubble(int size,int i,int j){
	if(j==size-i){
		return;
	}	
	else{
		if(arr[j]>arr[j+1]){
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
		j++;
		swapBubble(size,i,j);
		}
	}

///////////////////SELECTION SORT///////////////////////////////
	

void selectionSort(int size){
	int min_index;
	int temp;
	for (int i=0;i<size;i++){
		min_index=i;
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[min_index]){
				min_index=j;
			}
			
		}
			temp=arr[min_index];
			arr[min_index]=arr[i];
			arr[i]=temp;
		
	}	
}	


///////////////////SELECTION SORT RECURSIVE////////////////////////////


void selectionRecursion(int size,int i,int j){
	int min_index;
	int temp;
	if(i==size){
		return;
	}
	else{
		min_index=i;
		if(j==size){
			return;
		}
		else{
			if(arr[j]>arr[min_index]){
				min_index=j;
				}
				
			selectionRecursion(size,i,j+1);
		}
		temp=arr[i];
		arr[i]=arr[min_index];
		arr[min_index]=temp;
		selectionRecursion(size,i+1,0);
	}
	
}


//////////////////////INSERTION SORT/////////////////////////


void insertionSort(int size){
	int temp;
	int j;
	for(int i=1;i<size;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>=temp){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
}

//////////////////INSERTION SORT RECURSION///////////////////////////



void insertionRecursion(int size,int i,int j){
	int temp;
	if(i==size){
		return;
	}
	else{
		temp=arr[i];
		j=i-1;
		shift(size,i,j,temp);
		arr[j+1]=temp;
		i++;
		insertionRecursion(size,i,j);
	}
}

void shift(int size,int i,int j,int temp){
	if(j<0 || arr[j]<temp){
		return;
	}
	else{
		arr[j+1]=arr[j];
		j=j-1;
		shift(size,i,j,temp);
	}
}

/////////////////MERGE SORT////////////////////////


void merge(int arr[],int first,int mid,int last){
	int i=first;
	int fA=first, lA=mid, fB=mid+1, lB=last;
	
	int temp[last+1];	
	
	while(fA<=lA && fB<=lB){
		if(arr[fA]<arr[fB]){
			temp[i]=arr[fA];
			fA++;
			i++;
			
		}else{
			temp[i]=arr[fB];
			fB++;
			i++;
		}
		
	}
	while(fA<=lA){
		temp[i]=arr[fA];
		fA++;
		i++;
	}
	while(fB<=lB){
		temp[i]=arr[fB];
		fB++;
		i++;
	}
	
	for(int i=first;i<=last;i++){
		arr[i]=temp[i];
	}
}


void mergeSort(int arr[],int first,int last){
	int mid;
	if(first<last){
		mid = (first+last)/2;
		mergeSort(arr,first,mid);
		mergeSort(arr,mid+1,last);
		merge(arr,first,mid,last);
		
	}
}
	
//////////////////////DISPLAY////////////////////////


void display(int size)
	{
	cout<<"\n In display method";	
	for(int i=0; i<size; i++)
		{
			cout<<"\n Value in "<<i<<" index";
			cout<<" is: "<<arr[i];
		}
	}
