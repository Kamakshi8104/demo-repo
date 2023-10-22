#include <iostream>
using namespace std;
#define max 100
class queque{
 private:
  int front ;
  int rear;
  
  int arr[max];
 public:
  queque(){
    front=-1;
    rear=-1;
  }
  bool IsFull(){
      if(rear==max-1){
          return true;
      }
      else{
          return false;
      }
  }
  bool IsEmpty(){
      if((rear==-1 && front==-1)||(front>rear)){
          return true;
      }
      else{
          return false;
      }
  }
  void insert(int x){
      if(!IsFull()){
          rear++;
          arr[rear]=x;
          if(rear==0){
              front=0;
          }

      }
     
      else{
            cout<<"queue is full"<<endl;
          }
  }
 
  int Delete(){
      if(IsEmpty()){
          cout<<"queue is empty"<<endl;
          return 0;
      }
      else{
          return arr[front++];
         
         
         
      }
  }
};
void push(queque *q,int x){
    if(q->IsFull()){
        cout<<"stack overflow"<<endl;
    }
    else{
        q->insert(x);
    }
}
void pop(queque *q1,queque *q2){
    while(!(q1->IsEmpty())){
        int x=q1->Delete();
        if(!q1->IsEmpty()){
            q2->insert(x);
        }
        else{
            cout<<x<<endl;
        }
       
    }
    while(!(q2->IsEmpty())){
        q1->insert(q2->Delete());
    }
    

    
   
}
void peek(queque *q1,queque *q2){
    int x;
    while(!(q1->IsEmpty())){
         x=q1->Delete();
        if(!q1->IsEmpty()){
            q2->insert(x);
        }
        else{
            cout<<x<<endl;
        }
       
    }

    while(!(q2->IsEmpty())){
        q1->insert(q2->Delete());
    }
    q1->insert(x);
    

    
   
}



int main() {
    queque q1;
    queque q2;
    queque *Q1=&q1;
    queque *Q2=&q2;
    queque **x1=&Q1;
    queque **x2=&Q2;
    
    push(Q1,10);
    push(Q1,20);
    push(Q1,30);
    pop(Q1,Q2);
    pop(Q1,Q2);
    peek(Q1,Q2);
    pop(Q1,Q2);
    
   
   

    return 0;
}
