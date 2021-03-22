#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1000010;
int p[N],cnt;
int phi[N];
bool st [N];
LL get_eulers(int n){
   phi[1]=1;
   for(int i=2;i<=n;i++){
       if(!st[i]){
           p[cnt++] =i;
           phi[i]=i-1;
       }
        for(int j=0;p[j]<=n/i;j++){
            st[p[j]*i]=true ;
            if(i%p[j]==0){
                phi[p[j]*i] =phi[i]*p[j];
                break;
            }
            phi[p[j]*i] =phi[i]*(p[j]-1);
        }
   }
   LL res=0;
   for(int i=1;i<=n;i++)res+=phi[i];
   return res; 
} 
int main(){
    int n;
    cin>>n;
    cout<<get_eulers(n)<<endl;
    return 0;
}