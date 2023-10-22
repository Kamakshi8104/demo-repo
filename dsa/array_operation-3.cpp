##include<iostream>
using namespace std;
void input_array(int arr[],int size)
{
    
    for(int i=0;i<size;i++){
        cout<<"enter element "<<i<<" of array"<<endl;
        cin>>arr[i];

    }
    
}
void display_array(int array[],int size){
 for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
 }

}
void find_element(int arr[],int size){
    int no;
    int check=0;
    cout<<"enter number to be found"<<endl;
    cin>>no;
    for(int i=0;i<size;i++){

        if(arr[i]==no){
            cout<<"the number is found at "<<i<<" index"<<endl;
            check=0;
            break;
        }
        else{
          check=1;
        }
    }
    if(check==1){
        cout<<"element not present"<<endl;
    }
}
void sort_array(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
}
void delete_array(int arr[],int & size){
    int index=0;
    cout<<"enter index at which you want to delete"<<endl;
    cin>>index;
    for(int i=index+1;i<size;i++){
        arr[i-1]=arr[i];
    }
    size=size-1;

}
void insert_array(int arr[],int & size){
    int index=0;
    cout<<"enter index at which you want to insert"<<endl;
    cin>>index;
    size=size+1;
    //int end=size-1;
    for(int i=size-1;i>index;i--){
        arr[i]=arr[i-1];
    }
    cout<<"enter the no to be added"<<endl;
    cin>>arr[index];
}

int main(){
    int size;
    cout<<"enter size of array to be created"<<endl;
    cin>>size;
    int array[size]={0};
    input_array(array,size);
    display_array(array,size);
    find_element(array,size);
    sort_array(array,size);
    display_array(array,size);
    delete_array(array,size);
    display_array(array,size);
    insert_array(array,size);
    display_array(array,size);
    return 0;
}