/*
按照分析步骤一步一步分析状态如何转移
理解好状态数组代表啥意思
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n;
int a[N],f[N];
int main(){ 
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i]=1;//f[i]表示的是以第i个数结尾的上升子序列,初始化为1！！ 
       for(int j=1;j<i;j++)
            if(a[j]<a[i]) 
                f[i]=max(f[i],f[j]+1);                
    }

    int res=0;
    for(int i=1;i<=n;i++) res=max(res,f[i]);
    cout<<res<<endl;
    return 0;
}