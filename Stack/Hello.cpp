#include<iostream>

#define SIZE 100

using namespace std;

class STACK
{
    private:
    	
        char num[SIZE];
        int top;
    public:
        STACK();    //defualt constructor
        void push(char s);
        void palindrome();
        void reverse();
        void parenthesis();
        void infix();
        bool isEmpty();
        bool isFull();
        void displayItems();
        void pop(){
            //to store and print which number
            //is deleted
            char temp;
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

void STACK::push(char s){
    //check stack is full or not
    if(isFull()){
        cout<<"\n Stack is already full";
    }else{
        char ele;
        cout<<"\n Enter element: ";
        cin>>ele;
    ++top;
    num[top]=s;
}
}

void STACK::displayItems(){
    int i; //for loop
    cout<<"STACK is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    cout<<endl;
}

void STACK::reverse(){
	int pi=0;
	int pf=top;
	int temp;
	while(pi!=top/2){
		temp=num[pi];
		num[pi]=num[pf];
		num[pf]=temp;
		pi++;
		pf--;
		
	}
}
void STACK::palindrome(){
	bool b=true;
	STACK stk2;
	int x=0;
	for(int i=top ;i>-1;i--){
		stk2.num[i]=num[x];
		x++;
	}
	for (int i=0;i<SIZE;i++){
		if(stk2.num[i]!=num[i]){
			b=false;
			break;			
		}
	}
	if (b==false){
		cout<<"Not palindrome";
	}else{
		cout<<"\n Its palindrome";
		
	}
}
void STACK::parenthesis(){
	string exp;
	cout<<"\n Enter expression: ";
	cin>>exp;
	cout<<exp;
	int lengthExp;
	lengthExp=exp.length();
	int x=0;
	bool b=true;
	for (int i=0;i<lengthExp;i++){
		if (exp[i]=='{'){
			push('{');
		}
		else if(exp[i]=='}'){
			if(num[top]=='{'){			
				pop();
		}	else{
			cout<<"\n Unbalanced Expression";
			break;
		}	
	}	
	}
	if (stk.isEmpty){
		cout<<"Expression is balanced";
	}
}
void STACK::infix(){
	
}
int main(){
    //declare object
    STACK stk;
    int choice;
    char n,temp;

    do
    {
        cout<<endl;

        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items (Print STACK)."<<endl;
        cout<<"4 - Parnthsis "<<endl;
        cout<<"5 - Parnthsis "<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0: break;

            case 1:

               stk.push('{');
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
			case 5:
				stk.reverse();
				break;
			case 6:
				stk.palindrome();
				break;
            default:
                cout<<"An Invalid choice."<<endl;
        }
    }while(choice!=0);


    return 0;

}
