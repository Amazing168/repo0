#include<bits/stdc++.h>
int i,j,k,m,n,l,sum=0;
int a[10001],q,z;
using namespace std;
    int main(){  
    cin>>l>>m;
    for(i=1;i<=m;i++){ 
        cin>>q>>z; 	 
        for(j=q;j<=z;j++) a[j]++; 
        } 
    for(i=0;i<=l;i++){
        if(a[i]==0)sum++;
    }
    cout<<sum<<endl;
    return 0;
}