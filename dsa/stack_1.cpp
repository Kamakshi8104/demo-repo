#include <iostream>
using namespace std;
bool yes_user();
# define max 100
class stck
{
 private:
  
  int stck1[max];
  int top;
  
 public:
  stck(){
    top=-1;
    
    
  }
  bool IsEmpty(){
      if(top==-1){
          return true;
      }
      else{
          return false;
      }
  }
  bool IsFull(){
      if(top==(max-1)){
          return true;
      }
      else{
          return false;
      }
  }
  void push(int d){
      if(IsFull()){
       cout<<"stack overflow"<<endl;
      }
      else{
       top=top+1;
       stck1[top]=d;
       
      }
     
  }
   int pop(){
      if(IsEmpty()){
       cout<<"stack underflow"<<endl;
       return 0;
      }
      else{
          int d=stck1[top];
          top=top-1;
          return d;
         
       
      }
     
   }
  int peek(){
     if(IsFull()){
       cout<<"stack overflow"<<endl;
       return 0;
      }
     else{
       int d=stck1[top];
       return d;
      }
     
  }  
};
bool yes_user(){
    char contd;
    cout<<"do u want to continue?(y/n)"<<endl;
    cin>>contd;
    if(contd=='y'){
        return true;
    }
    else if(contd=='n'){
        return false;
    }
    else{
        cout<<"error"<<endl;
        cout<<"your number will be empty"<<endl;
        return false;
    }
   
 }
int main(){
    stck s1;
    stck s2;
    cout<<"enter first large number"<<endl;
    int d;
    while(yes_user()){
       
        cin>>d;
        s1.push(d);
        d=0;
    }
     cout<<"enter second large number"<<endl;
    while(yes_user()){
       
        cin>>d;
        s2.push(d);
        d=0;
    }
    stck s3;
    int carry=0;
    while(!(s1.IsEmpty()) && !(s2.IsEmpty())){
        int add=s1.pop()+s2.pop()+carry;
        if(add>=10){
            carry=1;
            add=add%10;
        }
        s3.push(add);
       
    }
   while(s1.IsEmpty()==false){
       int add=s1.pop()+carry;
        if(add>=10){
            carry=1;
            add=add%10;
        }
        s3.push(add);
       
       
   }
   while(s2.IsEmpty()==false){
       int add=s2.pop()+carry;
        if(add>=10){
            carry=1;
            add=add%10;
        }
        s3.push(add);
       
       
   }
   if(carry==1){
       s3.push(1);
   }
   while(!(s3.IsEmpty())){
       cout<<s3.pop();
   }
   
}


