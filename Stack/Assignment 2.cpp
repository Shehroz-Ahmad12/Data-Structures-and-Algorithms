//SP19-BCS-032

#include<iostream>

#define SIZE 100

using namespace std;

class STACK
{
    private:
    	
        char num[SIZE];
        int top;
    public:
        STACK();  
		
	
   		void push(char s){
		   
		    if(isFull()){
		        cout<<"\n Stack is already full";
		    }else{
		        
		   		++top;
		   		num[top]=s;
		}
}	

		void pop(){
           
            char temp;
            //check for empty
            if(isEmpty())
                cout<<"\n List is already empty ";
                    else{
            temp=num[top];
            --top;
            cout<<"\n Poped value is:  "<<temp;
                    }
        }
       
	   
	    void palindrome(){
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
      
	  
	    void reverse(){
			int pi=0;
			int pf=top;
			int temp;
			while(pi!=top/2){
				temp=num[pi];
				num[pi]=num[pf];
				num[pf]=temp;
				pi++;
				pf--;
		}		}
		
		
		void parenthesis(){
			string exp;
			cout<<"\n Enter expression: ";
			cin>>exp;
			cout<<exp;
			int lengthExp;
			lengthExp=exp.length();
			int x=0;
		
			for (int i=0;i<lengthExp;i++){
				if (exp[i]=='('){
					push('(');
				}
				else if(exp[i]==')'){
					if(num[top]=='('){			
						pop();
				}	else{
					cout<<"\n Unbalanced Expression";
					break;
				}	
			}	}
			if (isEmpty()){
				cout<<"Expression is balanced";
			}
	}
			void checkBrackets(){
				string exp;
				cout<<"\n Enter expression: \n";
				cin>>exp;
				cout<<exp;
				for (int i=0;i<exp.length();i++){
					if ((exp[i]=='[') || (exp[i]=='{' )|| (exp[i]=='(')){
						push(exp[i]);
					}
					else if(exp[i]==')'){
						if (num[top]=='('){
							pop();
						}
						else{
							cout<<"\n Unbalanced Equation ";
							break;
						}
					}
					else if(exp[i]=='}'){
						if (num[top]=='{'){
							pop();
						}
						else{
							cout<<"\n Unbalanced Equation ";
							break;
						}
					}
					else if(exp[i]==']'){
						if (num[top]=='['){
							pop();
						}
						else{
							cout<<"\n Unbalanced Equation ";
							break;
						}
					}
				}
				if (isEmpty()){
					cout<<"\n Balanced Equation";
				}	
			}
			
			
			
		
        
	
	   
	    bool isEmpty(){
		    if(top==-1)
		        return true;
		    else
		        return false;
		}
      
	    bool isFull(){
		    if(top==(SIZE-1))
		        return true;
		    else
		        return false;
		}
       
	    void displayItems(){
		    int i; //for loop
		    cout<<"STACK is: ";
		    for(i=(top); i>=0; i--)
		        cout<<num[i]<<" ";
		    cout<<endl;
		}
        
};

STACK::STACK(){
	top=-1;
}
int main(){
    
    STACK stk;
    int choice;
    char n,temp;

    do
    {
        cout<<endl;

        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items (Print STACK)."<<endl;
        cout<<"4 - Check Parenthesis "<<endl;
        cout<<"5 - Reverse Stack "<<endl;
        cout<<"6 - Check Palindrome "<<endl;
        cout<<"7 - Check Brackets "<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0: break;

            case 1:
            	char ele;
		        cout<<"\n Enter element: ";
		        cin>>ele;
            	stk.push(ele);
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
			case 7:
				stk.checkBrackets();
				break;
				
            default:
                cout<<"An Invalid choice."<<endl;
        }
    }while(choice!=0);


    return 0;

}



