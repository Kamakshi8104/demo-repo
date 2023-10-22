# define MAX 100
#include <iostream>
#include<string>
using namespace std;

class stck{
 private:
  int top;
  int arr[MAX];
 public:
  stck(){
    top=-1;
  }
  bool IsFull(){
    if(top==MAX-1){
        return true;
    }
    else{
        return false;
    }
  }
  bool IsEmpty(){
    if(top==-1){
        return true;
    }
    else{return false;}
  }
  void push(int c){
    if(IsFull()){
        cout<<"stack overflow"<<endl;
        return ;
    }
    else{
        top++;
        arr[top]=c;
    }

  }
  int pop(){
    if(IsEmpty()){
        cout<<"stack is empty"<<endl;
        return 0;
    }
    else{

        int  c=arr[top];
        top--;
        return c;



    }
  }
  int peek(){
    if(IsEmpty()){
        cout<<"stack is empty"<<endl;
        return 0;

    }
    else{
        int  c=arr[top];
        return c;
    
    }
  }
    
    
        
    

  


     
};

int char_to_int(char a){
    int x=a-'0';
    return x;

}

int calc(int op1,int op2,char c){
    int result;
    if(c=='+'){
        result=op1+op2;


    }
    else if(c=='-'){
        result=op2-op1;
    }
    else if(c=='*'){
        result=op1*op2;
    }
    else if(c=='/'){
        result =op2/op1;

    }
    
    return result;
}
int main(){
    stck s;
    string exp;
    cin>>exp;
    size_t length=exp.length();
    int index=0;
    //cout<<index<<endl;
    while(index<length){
       char c=exp[index];
       //cout<<c<<endl;
       if(  c=='+' ||  c=='-' ||  c=='*' ||  c=='/'){
        
          int op1=s.pop();
          int op2=s.pop();
          int result=calc(op1,op2,c);
          cout<<"result " <<result<<endl;
          s.push(result);
          
         
       }
       else{
         s.push(char_to_int(c));
       }
       index++;
    }
    cout<<"the result is:  "<<s.pop()<<endl;
    

    
}