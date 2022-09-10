#include<iostream>
#include<cstdlib>
using namespace std;
void display(int arr[],int size){ 
    printf("\nArray\n");
    for(int i=0;i<size;i++){
      printf("%d\n",arr[i]);
    }
}
int insertion(int arr[],int size,int capacity,int index, int element){  
    
    if(size>=capacity){
        printf("Array Overflow!");
    }
    else{ 
        
    for(int j=size-1;j>=index;j--){
        arr[j+1]=arr[j];
    } 
    arr[index]=element;  
    
    } 
    return 0;
} 
int deletion(int arr[],int size,int index){
     if(size<=0){
        printf("Array underflow!");
    } 
    
    for(int k=index;k<=size-1;k++){
        arr[k]=arr[k+1];
    }  
    return 0;
} 
int linearsearch(int arr[],int size,int element){
    
    for(int i=0;i<size;i++) 
    if(arr[i]==element){
        return i;
    } 
    return -1;
} 
int binarysearch(int arr[],int size,int element){
    int low=0,mid,high=size-1; 
  
    for(int j=0;j<size;j++){
        mid=(low+mid)/2;
        if(arr[mid]==element){
            return mid;}
            else if(arr[mid]<element) {
              low=mid+1;

            }  
            else{
                high=mid-1;
            }
                 }
     
    return -1;
} 
int main(){ 
    int capacity,size,choice;
    printf("WELCOME TO ARRAY AND ITS OPERATIONS\n");
     printf("Enter the maximum capacity of the Array:\n");  
     cin>>capacity; 
     int arr[capacity];
    printf("Enter the size of the Array:\n"); 
    cin>>size;
     
     for(int i=0;i<size;i++){  
         printf("Enter the element %d of the Array:\n",i+1);
         cin>>arr[i];
     }  
     top:
    printf("-------------------------Menu-------------------------\n"); 
    printf("1.insert an element\n"); 
    printf("2.delete an element\n");  
    printf("3.find the element\n"); 
    printf("4.display an array\n");   
       int index,element,res; 
       cin>>choice;
    switch(choice){
        case 1:    
     
        size+=1;
        printf("Enter the element to be inserted:\n");    
        cin>>element;
        printf("Enter the index to be inserted:\n");   
        cin>>index;
        insertion(arr,size,capacity,index,element);  
        display(arr,size);  
        break;
        case 2: 
        size-=1;
        printf("Enter the index to be deleted:\n");   
        cin>>index; 
        deletion(arr,size,index);  
        display(arr,size);
        break; 
        case 3:
        printf("Enter the element to be searched:\n");  
        cin>>element;  
        res=linearsearch(arr,size,element);
        printf("index of the element is: %d\n",res); 
        break;
        case 4:
        display(arr,size);  
        break;
        default :
        printf("Invalid input\n");  
        goto top; 
        break;
    }
    return 0;
}