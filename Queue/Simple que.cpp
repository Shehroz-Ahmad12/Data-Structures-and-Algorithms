#include <iostream>
using namespace std;

class que{
	private:
		int size;
		int front;
		int rear;
		int *q;
	
	public:
		 que(){
			size=10;
			q=new int[size];
		 	front=-1;
		 	rear=-1;
		 }
		 que(int x){
		 	size=x;
			q=new int[size] ;
			front=-1;
			rear=-1;
					}
		 
		 
		 bool isEmpty(){
		 	if(rear==-1){
		 		return true;
			 }
			 else{
			 	return false;
			 }
		 }
		 
		 bool isFull(){
		 	if(rear==size-1){
		 		return true;
			 }
			 else{
			 	return false;
			 }
		 }
		 
		 void enqueue(int x){
		 	if(isFull()){
		 		cout<<"\n No Space in the Queue ";
			 }
			 else{
			 	if(front==-1){
			 		front=rear=0;
				 }
				 else{
				 	rear++;
				 }
				 q[rear]=x;
			 }
		}
		
		int dequeue(){
						
				if (isEmpty())
				{
			         cout<<"Queue is already empty";	
			         return -1;	
				}
				else 
				{
					return q[front++];
				}
			

		}
		
		
		int Front(){
			
				return q[front];
			
		}
		
		void display(){
			if (isEmpty()){
				cout<<"\n\n Array is Empty";
			}
			else{
				int x=front;
				while(x!=rear+1){
					cout<<"\n Element is: "<<q[x];
					x++;
				}
			}
		}
};


int main(){
	que q1;
	int opt;
	int x,y,z;
	do{
		cout<<"\nPress 1 to enqueue ";
		cout<<"\nPress 2 to dequeue ";
		cout<<"\nPress 3 to show front ";
		cout<<"\nPress 4 to display ";
		cout<<"\nPress 0 to quit ";
		
		cout<<"\nEnter Option: ";
		cin>>opt;
		
		switch(opt){
			case 1:
				cout<<"\n\n Enter value to be enqueued: \n";
				cin>>x;
				q1.enqueue(x);
				break;
			case 2:
				y=q1.dequeue();
				cout<<"\n"<<y;
				break;
			case 3:
				z=q1.Front();
				cout<<"\n"<<z;
				break;
			case 4:
				q1.display();
				break;
			default:
				cout<<"Invalid Input";	
				break;
		}
		
	}while (opt!=0);
	
	
	
	return 0;
}
