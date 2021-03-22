#include<bits/stdc++.h>
using namespace std;
const int N=1010,mod=1e9+7;
int n;
/*int f[N];

完全背包解法


f[i][j]表示只从1~i中选，且总和等于j的方案数

f[i][j] = f[i - 1][j] + f[i][j - i];

int main(){
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)
            f[j]=(f[j]+f[j-i])%mod;
    }
    cout<<f[n]<<endl;
    return 0;
}
*/


/*
另一种解法，
f[i][j]代表着总和为n，使用了j个数的方案数

状态转移方程的划分的时候将其划分为最小的数是不是1
是1的话，减掉一个1，j--
不是1的话，那就所有的j个数都减掉一个1，即i-=j
由此得 状态转移方程，

f[i][j] = f[i - 1][j - 1] + f[i - j][j];
*/
int f[N][N];

int main(){
     cin>>n;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i][j]=(f[i-1][j-1]+f[i-j][j])%mod;
    
    int res=0;
    for(int i=1;i<=n;i++) res=(res+f[n][i])%mod;
    cout<<res<<endl;

    return 0;
}
