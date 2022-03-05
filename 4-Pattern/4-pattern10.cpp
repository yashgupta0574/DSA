#include<iostream>
using namespace std;
int main() {

    int n; 
    cin>>n;
    
    for(int i=1;i<=n;i++){
        int emptyspace=2*n-2*i;
    for(int j=1;j<=i;j++){
           cout<<"*";
           }
           for (int j=1;j<=emptyspace;j++){
               cout<<" ";
           }
           for(int j=1;j<=i;j++){
               cout<<"*";
           }
       cout<<endl;

    }

    
    for(int i=n;i>=1;i--){
        int emptyspace=2*n-2*i;
    for(int j=1;j<=i;j++){
           cout<<"*";
    }
           for (int j=1;j<=emptyspace;j++){
               cout<<" ";
           }
           for(int j=1;j<=i;j++){
               cout<<"*";
           }
       cout<<endl;

    }
       
    
    return 0;
}