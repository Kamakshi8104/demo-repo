#include <iostream>
using namespace std;
class linkedlist{
    private:
     int quantum;
     struct node{
         int pid;
         int execution;
         struct node* next;
     };
     node* start;
     int total;
    public:
     linkedlist(){
         start=NULL;
         quantum=4;
         total=0;
     }
     void add_process(int id,int t){
         node *p;
         p=(node*)malloc(sizeof(node));
         p->pid=id;
         p->execution=t;
         
         if(start==NULL){
             start=p;
             p->next=start;
             return;
         }
         else{
             //cout<<start->pid<<endl;
             node *q=start;
             while(q->next!=start){
                 q=q->next;
                 
             }
             //cout<<q->pid<<endl;
             q->next=p;
             p->next=start;
         }
         //cout<<start->pid<<endl;
         
     }
     void robin_round(){
         node *p;
         p=start;
         
         while(p!=NULL){
             if(p->execution>quantum){
                 int t=quantum;
                 total=total+quantum;
                 //p=(node*)malloc(sizeof(node));
                 p->execution=p->execution-quantum;
                 cout<<"process: "<<p->pid<<" for: "<<t<<"total time: "<<total<<endl;
                 p=p->next;
                 continue;
                 
             }
             else{
                 if(p==start && p->next==start){
                     total=total+p->execution;
                     cout<<"process: "<<p->pid<<" for: "<<p->execution<<"total time: "<<total<<endl;
                     p=NULL;
                     return;


                     
                 }
                 else if(p==start && p->next!=start){
                     total=total+p->execution;
                     cout<<"process: "<<p->pid<<" for: "<<p->execution<<"total time: "<<total<<endl;
                     node *q=start;
                     while(q->next!=start){
                       q=q->next;
                         
                     }
                     start=p->next;
                     q->next=start;
                     p=p->next;
                     
                 }
                 else{
                     total=total+p->execution;
                     cout<<"process: "<<p->pid<<" for: "<<p->execution<<"total time: "<<total<<endl;
                     node *q=start;
                     while(q->next!=p){
                         q=q->next;
                     }
                     q->next=p->next;
                     p=p->next;
                     
                     
                 }
                 
                 
                 
             }
             
         }
     }
};

int main() {
    // Write C++ code here
   linkedlist list;
   list.add_process(1,12);
   list.add_process(2,8);
   list.add_process(3,18);
   list.add_process(4,23);
   list.robin_round();
   

    return 0;
}
