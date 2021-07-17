#include<iostream>

#define SIZE 5

using namespace std;

class STACK
{
    private:
    	
        int num[SIZE];
        int top;
    public:
        STACK();    //defualt constructor
        void push();
        void parenthesis();
        bool isEmpty();
        bool isFull();
        void displayItems();
        void pop(){
            //to store and print which number
            //is deleted
            int temp;
            //check for empty
            if(isEmpty())
                cout<<"\n List is already emepty ";
                    else{
            temp=num[top];
            --top;
            cout<<"\n Poped value is:  "<<temp;
                    }
        }
};
STACK::STACK(){
    top=-1;
}

bool STACK::isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}

bool STACK::isFull(){
    if(top==(SIZE-1))
        return true;
    else
        return false;
}

void STACK::push(){
    //check stack is full or not
    if(isFull()){
        cout<<"\n Stack is already full";
    }else{
        int ele;
        cout<<"\n Enter element: ";
        cin>>ele;
    ++top;
    num[top]=ele;
}
}

void STACK::displayItems(){
    int i; //for loop
    cout<<"STACK is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    cout<<endl;
}

void STACK::parenthesis(){
	string exp;
	cout<<"\n Enter expression: ";
	cin>>exp;
	cout<<exp;
	
}

int main(){
    //declare object
    STACK stk;
    int choice, n,temp;

    do
    {
        cout<<endl;

        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items (Print STACK)."<<endl;
        cout<<"4 - Parnthsis "<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0: break;

            case 1:

               stk.push();
            break;

            case 2:
               stk.pop();

            break;

            case 3:
                stk.displayItems();
                break;
			case 4:
				stk.parenthesis();
				break;
            default:
                cout<<"An Invalid choice."<<endl;
        }
    }while(choice!=0);


    return 0;

}
