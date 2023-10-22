#include <iostream>
using namespace std;
class link_list1{
  private:
    struct node{
     int data;
     struct node *next;
    };

    node *start;

    public:
      link_list1(){
        start=NULL;

      }
      
      
     
     
     void display_list(){
      node *p=start;
      //p=(node*)malloc(sizeof(node));
      if(p==NULL){
        cout<<"list empty"<<endl;
      }
      else{
       while(p!=NULL){
         cout<<p->data<<endl;
         p=p->next;
       }
     }
    }
    void insert(int x)
    {
        node *p;
        p=(node*)malloc(sizeof(node));

        
        p->data=x;
        if(start==NULL){
            start=p;
            p->next=NULL;
        }
        else{
            node *q;
            node *r;
            q=start;
           
            if(start->data<p->data){
                p->next=start;
                start=p;
            }
            else{
            while(q->data>p->data){
                r=q->next;
                if(q->next==NULL){
                    
                    break;
                }
                
                

                
                if(r->data<q->data){
                    break;
                }
                else{
                    
                    q=q->next;
                }
                

            }
            p->next=r;
            q->next=p;
        }
     }
    }
    int extract_max(){
        
        if(start==NULL){
            cout<<"empty queue"<<endl;
            return -1;
        }
         node *p=start;
         int x=start->data;
         start=start->next;
         free(p);
         return x;

    }
    void max(){
        if(start==NULL){
            cout<<"empty queue"<<endl;
            return;
        }
        cout<<start->data<<endl;
    }
    


};
int main(){
    link_list1 list;
    list.max();
    list.extract_max();
    
    list.insert(1);
    list.display_list();

    list.insert(2);
    list.display_list();
    list.insert(5);
    
    list.insert(3);
    list.insert(3);
    list.display_list();

    list.max();
    cout<<list.extract_max()<<endl;
    list.max();
    list.display_list();
    cout<<list.extract_max()<<endl;
    cout<<list.extract_max()<<endl;
    cout<<list.extract_max()<<endl;

    
    
}