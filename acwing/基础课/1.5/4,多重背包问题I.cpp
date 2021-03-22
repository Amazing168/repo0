
//最暴力的多重背包问题

#include<bits/stdc++.h>
using namespace std;
const int N=110;

int n,m;
int v[N],w[N],s[N];
int f[N][N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=s[i]&&k*v[i]<=j;k++)
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);// 这里不能写成max(f[i-1][j],...),因为这样的话每次k++都会被重新赋值

    cout<<f[n][m]<<endl;

    return 0;
}

//一维版本
#include<bits/stdc++.h>
using namespace std;
const int N=110;

int n,m;
int v[N],w[N],s[N];
int f[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            for(int k=0;k<=s[i]&&k*v[i]<=j;k++)
                f[j] =max(f[j],f[j-k*v[i]]+w[i]*k);// 这里不能写成max(f[i-1][j],...),因为这样的话每次k++都会被重新赋值

    cout<<f[m]<<endl;

    return 0;
}


//saber代码

