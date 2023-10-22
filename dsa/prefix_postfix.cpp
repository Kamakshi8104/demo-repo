#include <iostream>
#include <string>

using namespace std;
class Stack{
  private:
  int top;
  string arr[100];
  
  public:
  Stack(){
    top=-1;
    
    
  }
  bool IsEmpty()
  {
      if(top==-1)
      {
          return true;
      }
      else{
          return false;
      }
  }
    bool IsFull()
  {
      if(top==(sizeof(arr)/sizeof(arr[0]))-1)
      {
          return true;
      }
      else{
          return false;
      }
  }
  void push(string data)//1
{
    if(IsFull())
    {
        cout<<"Stack Overflow"<<endl;
    }
    else{
        
        top++;
        arr[top]=data;
    }
}
string pop(){ //2
    if(IsEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        return "x";
    }
    else{
        string popObj=arr[top];
        top--;
        return popObj;
    }
}
string peek()//3
{
    if(IsEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        string x="x";
        return x;
    }
    else{
        cout<<endl;
        return arr[top];
    }
}
void display()//4
{
    if(IsEmpty())
    {
        cout<<"No elements added"<<endl;
    }
    else{
        
        while(!(IsEmpty())){
            cout<<pop();
            

        }
        
    }
   
}

};
bool check_operator(char s){
    if(s=='+' || s=='-' || s=='*' || s=='/'){
        return true;
    }
    else{
        return false;
    }
    


}

int main()
{
    Stack s;
    string exp;
    cin>>exp;
    size_t length=exp.length();
    int index=length-1;
    while(index<length){
      if(!check_operator(exp[index])){
        string s1(1,exp[index]);
        s.push(s1);
      }
      else{
        string op1=s.pop();
        string op2=s.pop();
        string sub=op1+op2+exp[index];
        s.push(sub);

      }
      index--;
        


    }
    s.display();


    

}

