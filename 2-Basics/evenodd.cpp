#include<iostream>
using namespace std;

int main(){
    
    int n,ans=1;
    cin>>n;
    int a[n];
    a[0]=-1;
    for(int i=1;i<=n;i++){
        if((a[i]==0 | a[i]==1 | a[i]==2) && (a[i+1]>=0 && a[i+1]<=6)  ){
          ans*=2;
        }
    }
    cout<<ans-1<<endl;
return 0;
}