#include<bits/stdc++.h>
using namespace std;

const int N=220;
int t;
int a[N];
int main()
{
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
        sort(a,a+n);
        int res=0;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]) res++;
            int l=0,st ;
            if(a[i]==a[i-1]){
                   st=i;
                   l++;
                while(a[i]==a[i-1]) {
                    l++;
                    i++;
                }
           if (a[i]>a[i-1]){
               if(st==1) res++;
               else res+=l;
            } 
               
        }
        cout<<res<<endl;

    }
  
    

    return 0;
}