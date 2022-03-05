#include<iostream>
using namespace std;
int main() {

    int n; 
    cin>>n;
    
    for(int i=1;i<=n;i++){
        int emptyspace=2*n-2*i;
        int j;
    for(int j=1;j<=i;j++){
     if(j==1||j==i){
           cout<<"*";
           }else
           {
             cout<<" ";  
           }
    }
           for (j=1;j<=emptyspace;j++){
               cout<<" ";
           }
           for(j=1;j<=i;j++){
               if(j==1||j==i){
               cout<<"*";
           }else{
               cout<<" ";
           }
           }


       cout<<endl;

    }

    
    for(int i=n;i>=1;i--){
        int emptyspace=2*n-2*i;
      int j;
    for(int j=1;j<=i;j++){
     if(j==1||j==i){
           cout<<"*";
           }else
           {
             cout<<" ";  
           }
    }
           for (j=1;j<=emptyspace;j++){
               cout<<" ";
           }
           for(j=1;j<=i;j++){
               if(j==1||j==i){
               cout<<"*";
           }else{
               cout<<" ";
           }
           }
       cout<<endl;

    }


   
    
    return 0;
}