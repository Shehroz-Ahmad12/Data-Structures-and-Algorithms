//SP19-BCS-032
//Postfix Evaluation is not giving output because i was facing problem in type casting 




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
		    int i; 
		    cout<<"STACK is: ";
		    for(i=(top); i>=0; i--)
		        cout<<num[i]<<" ";
		    cout<<endl;
		}
		
		void infix(){ 
			string exp;
			cout<<"\n Enter Expression: ";
			cin>>exp;
			string output;
			int len = exp.length();
			
			for (int i=0;i<len;i++){
			
				if(exp[i]>='a' && exp[i]<='z'){
					output+=exp[i];
				}
			
				else if(exp[i]=='('){
					push('(');
				}	
			
				else if(exp[i]==')'){
			
					while(!isEmpty() && num[top]!='('){
						char temp=num[top];
						pop();
						output+=temp;
			
						if (num[top]=='('){
							pop();
						}
					}
				}
				else{
					while(!isEmpty() && checkPrec(exp[i])>=checkPrec(num[top])){
						char temp=num[top];
						pop();
						output+=temp;
					}
					push(exp[i]);
					
					}
				}
				
				while(!isEmpty()){
					char temp=num[top];
					pop();
					output+=temp;
				}
				
				cout<<"\n \nResult is: "<<output;
				evaluatePostfix(output);
			} 
			
		int checkPrec(char op){
			if (op=='+' || op=='-'){
				return 1;
			}
			else if (op=='*' || op=='/'){
				return 2;
			}
			else{
				return -1;
			}
		}
		
       void evaluatePostfix(string exp){
       		STACK stk2;
       		for(int i=0;i<exp.length();i++){
       			if (exp[i]>='a' && exp[i]<='z'){
       				stk2.push(exp[i]);
       				
				   }
				else {
					
					char val1=stk2.num[top];
					stk2.pop();
					char val2=stk2.num[top];
					stk2.pop();
					int res=operation(val1, val2, exp[i]);
					char resc=char(res);
					stk2.push(resc);
				}
			   }
       	
	   }
	   	int operation(int a,int b,char op){
	   		if(op=='+'){
	   			return a+b;
			   }
			else if(op=='-'){
				return a-b;				
			}
			else if(op=='*'){
				return a*b;
			}
			else if(op=='/'){
				return a/b;
			}
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

        cout<<"1 - Infix to Postfix "<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            
                
			case 1:
				stk.infix();
				break;
				
            default:
                cout<<"An Invalid choice."<<endl;
        }
    }while(choice!=0);


    return 0;

}

        
       

