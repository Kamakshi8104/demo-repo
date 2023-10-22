#include <iostream>
#include<string>
using namespace std;
bool yes_user();
class stck
{
 private:
  char stck1[100];
  int top=-1;
  int max=100;
 public:
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
int check_pair(char c1,char c2){
    if((c1=='{' && c2=='}') || (c1=='[' && c2==']') || (c1=='(' && c2==')')){
        return 1;
    }
    else{return 0;}
}
int main(){
   string expression;
   stck s;
   cin>>expression;
   size_t size=expression.length();
   int valid=1;
   int index=0;
   while(index<size){
       if (expression.at(index)=='(' || expression.at(index)=='[' || expression.at(index)=='{' ){
           s.push(expression[index]);
       }
       if (expression.at(index)==')' || expression.at(index)==']' || expression.at(index)=='}' ){
           if(s.IsEmpty()==true){
               valid=0;
               break;//return false
               
           }
           else{
           char c=s.pop();
           
           valid=check_pair(c,expression.at(index));
           }
         
       }
        if(valid==0){
               break;
        }
        index++;
       
       
   }
   if(s.IsEmpty()==false){
       valid=0;
   }
   if(valid==1){
       cout<<"expression has valid parenthesis"<<endl;
   }
   else{
       cout<<"not a valid expression"<<endl;
   }
}
