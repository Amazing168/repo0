/*
分析得到状态转移方程即可 
二维 f[i][j]=max(f[i-1][j],f[i-1][j-v[i][k]+w[i][k]])//[i][k]代表i组第k个背包

一维
 f[j]= max(f[j],f[j-v[i][k]]+w[i][k])

*/


#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int v[N][N],w[N][N],s[N];
int f[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<s[i];j++){
            cin>>v[i][j]>>w[i][j];
        }
    }
    for(int i=1;i<=n;i++)//枚举背包种类
        for(int j=m;j>=0;j--){//枚举背包容量
            for(int k=0;k<s[i];k++)//枚举每组内的背包
            if(v[i][k]<=j)
                f[j]=max(f[j],f[j-v[i][k]]+w[i][k]); 
        }
    cout<<f[m]<<endl;

    return 0;
}