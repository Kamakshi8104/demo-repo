#include <iostream>
using namespace std;
class queue_circular{
    private:
      int *p;
      int first;
      
      int size;
      int capacity;
      int next_index;
    public:
    queue_circular(int s){
        p=new int [s];
        first=-1;
        
        size=0;
        capacity=s;
        next_index=0;

    }
    bool isempty(){
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }
    bool isfull(){
        if(size==capacity){
            return true;

        }
        else{
            return false;
        }
    }
    void enqueue(int a){
        if(!isfull()){
            if(first==-1){
                first=0;

            }
            p[next_index]=a;
            next_index=(next_index+1)%capacity;
            size++;
            return;

        }
        else{
            cout<<"queue is full"<<endl;
            return;
        }

    }
    int dequeue(){
        if(!isempty()){
            int x=p[first];
            if(size==1){
                first=-1;
                next_index=0;
            }
            else{ 
              first=(first+1)%capacity;
            }
            size--;
            
            return x;


        }
        else{
            cout<<"full queue"<<endl;
            return -1;
        }
    }
    int check_size(){
        return size;
    }
    int display(){
        return p[first];
    }


};
int main(){
    queue_circular q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.enqueue(6);
    cout<< q.display()<<endl;
    cout<< q.dequeue()<<endl;
    cout<< q.dequeue()<<endl;
    cout<< q.dequeue()<<endl;
    cout<< q.dequeue()<<endl;
    cout<< q.dequeue()<<endl;
   cout<< q.check_size()<<endl;
   q.enqueue(1);
   cout<< q.dequeue()<<endl;
   


    


}