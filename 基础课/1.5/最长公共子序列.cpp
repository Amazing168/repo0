/*
f[i][j]表示在第一个序列的第i个字母中出现
且在在第二个序列中的出现的第j个字母中出现的子序列。
当两个串的字母相同时，进行f数组的更新。

*/

#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
char a[N],b[N];
int f[N][N];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s%s",a+1,b+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
              f[i][j]=max(f[i-1][j],f[i][j-1]);
              if((a[i]==b[j])) f[i][j]=max(f[i][j],f[i-1][j-1]+1);  
        }
    printf("%d\n",f[n][m]);
    return 0;
}