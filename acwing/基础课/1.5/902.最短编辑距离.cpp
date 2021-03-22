/*
f[i][j]是代表着的集合是将[1~i]变为[1~j]的方案数里最小操作数的那一种。
状态计算的时候，分情况讨论一步一步的分析

*/

#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
char a[N],b[N];
int f[N][N];
int main(){
    scanf("%d%s",&n,a+1);
    scanf("%d%s",&m,b+1);
    for(int i=0;i<=m;i++) f[0][i]=i;
    for(int i=0;i<=n;i++) f[i][0]=i;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        f[i][j]=min(f[i][j-1]+1,f[i-1][j]+1);
        if(a[i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
        else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
    }
    printf("%d\n",f[n][m]);
    return 0;
}