/*
01背包问题
j从大到小遍历
二维数组+动规
状态转移方程：
定义f[i][j]:前 ii 个物品，背包容量 jj 下的最优解

1）当前背包容量不够（j < w[i]），为前 i−1 个物品最优解：f[i][j] = f[i-1][j]
2）当前背包容量够，判断选与不选第 ii 个物品
选：f[i][j] = f[i-1][j-w[i]] + v[i]
不选：f[i][j] = f[i-1][j]

(动规+一维数组)滚动数组的原理
状态转移方程为：f[j] = max(f[j], f[j-w[i]] + v

*/


#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int f[N];
int v[N],w[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    }

    cout<<f[m]<<endl;
    return 0;
