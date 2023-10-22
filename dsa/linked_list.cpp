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
    void info( struct node *p){
      int d;
      cout<<"enter data"<<endl;
      cin>>d;
      p->data=d;

    }
    struct node * get_node(){
      node *x;
      return x;
    }
    void create (int n ){
      start=NULL;
      node *p;
      node *q;
      for (int i=0;i<n;i++){
        p=(node*)malloc(sizeof(node)); //has to be in loop
        
        
        info(p);
        if(start== NULL){
            start=p;
            p->next=NULL;
        }
        else{
            q=start;
            while(q->next!=NULL){
                q=q->next;
            }
            q->next=p;
            p->next=NULL;
        }

      }
      
    


   }

   void get_info(int n){
        node *p;
        
        p=(node*)malloc(sizeof(node));
        p=start;
        if(p==NULL){
          cout<<"empty"<<endl;
        }
        else{
          for(int i=0;i<n-1;i++){
          p=p->next;
          if(p==NULL){
            break;
          }
          }
          if(p==NULL){
            cout<<"no node"<<endl;
          }
          else{
            cout<<p->data<<endl;
          }
        }
   }

   void insert_beg(){
      
      node *p;
      p=(node*)malloc(sizeof(node));
      info(p);
      p->next=start;
      start=p;



    }
    void insert_end(){
      
      node *p;
      p=(node*)malloc(sizeof(node));
      
      info(p);
      p->next=NULL;
      node *q;
      q=(node*)malloc(sizeof(node));
      
      q=start;
      if(q==NULL){
         cout<<"list is empty"<<endl;
         start=p;
      }
      else{
        while(q->next!=NULL){
          q=q->next;


        }
    
        q->next=p;
      }

    }
    void insert_random(int n){
     
     node *p;
     node *q;
     p=(node*)malloc(sizeof(node)); 
     cout<<" value to be inserted at "<<n<<endl;
     info(p);
     q=start;
     for(int i=0;i<n-2;i++){
       q=q->next;

       
     }
     p->next=q->next;
     q->next=p;


    }
    void delete_at_end(){
      node *p;
      node *q;
      p=start;
      q=NULL;
      while(p->next!=NULL){
        q=p;
        p=p->next;
      }
      q->next=NULL;
      free(p);

    }
    void delete_at_start(){
      node *p=start;
      
      start=p->next;
      free(p);
    }
    void delete_random(int n){
      node *p;
      p=start;
      node *q;
      q=NULL;
      for(int i=0;i<n-1;i++){
        q=p;
        p=p->next;

      } 
      q->next=p->next;
      free(p);
      

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
    void rem_nth_last(int n){
      node *p;
      int count=0;
      p=start;
      while(p!=NULL){
        count++;
        p=p=p->next;
        
      }
      //cout<<"COUNT IS"<<count<<endl;
      p=start;
      if(n>count){
        cout<<"not sufficient nodes"<<endl;
        return;
      }
      if(count==0){
        cout<<"empty"<<endl;
        return;
      }
      else{
        int x=count-n;
        node *q;
        for(int i=0;i<x;i++){
          q=p;
          p=p->next;

        }
        q->next=p->next;
        free(p);

        
      }



    }
   /* void sort_bubble(){
      node *p;
      int count=1;
      while(p->next!=NULL){
        count++;
        p=p=p->next;
        
      }
      node *q;
      p=start;
      q=p;
      p=p->next;
      
      while(count-1>0){
        int loops=count;
        while(loops-1>0){
          if(p->data<q->data){
           q->next=p->next;
           p->next=q;
           p=q->next;

          }
          else{
          q->next=p->next;
          p=p->next;
          } 
          loops--;
        }
      }

    }*/
void reverse(){
      node *prev;
      node *curr;
      node *next;
      prev=NULL;
      curr=start;
      next=curr->next;
      while(next!=NULL){
        curr->next=prev;
        prev=curr;
        curr=next;
        next=curr->next;
      }
      curr->next=prev;
      prev=curr;
      start=prev;
      
    }
   


    
    void insert_in_order(){
      cout<<"data is to be inserted in order"<<endl;
      node *p=get_node();
      p=(node*)malloc(sizeof(node));
      info(p);
      node *second;
     // p=(node*)malloc(sizeof(node));
      node *first;
      //p=(node*)malloc(sizeof(node));
      second=start;
      while(second->next!=NULL){
        first=second;
        second=second->next;
        if(second->data>p->data && first->data<=p->data){
          first->next=p;
          p->next=second;
        }
        if(second->next==NULL && second->data<=p->data){
          second->next=p;
          p->next=NULL;
        }
        if(start->data>p->data){
          p->next=start;
          start=p;
        }
      }

    }


};

int main(){
    link_list1 link;
    link.create(5);
    /*link.insert_in_order();
    link.display_list();
    //link.sort_bubble();
    link.display_list();
    link.get_info(10);
    link.insert_beg();
    link.display_list();
    link.insert_end();
    link.display_list();
    link.insert_random(3);
    link.display_list();
    link.delete_at_end();
    link.display_list();
    link.delete_at_start();
    link.display_list();
    link.delete_random(3);
    link.display_list();
    link.rem_nth_last(10);*/
    link.reverse();
    link.display_list();
    
    
     
}

