/*
状压DP的经典入门题

f[i][j] i是通过状压来存储经过的点的情况的数，j是当前所在的点。

集合划分的话，就是通过枚举能够到达就j的点k来更新数组

f[i][j]=min(f[i][j],f[i^(1<<j)][k]+weight[k][j]
*/

#include <bits/stdc++.h>
using namespace std;
const int N=20,M=1<<N;

int n;
int w[N][N];
int f[M][N];

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>w[i][j];

    memset (f,0x3f,sizeof f);
    f[1][0]=0;
    for(int i=0;i<1<<n;i++)//i代表着是一个方案集合，其中每一个位置1和0，代表着这个点经过还是没有经过
        for(int j=0;j<n;j++)//枚举当前到了哪一个点
            if(i>>j&1){//如果i集合中第j位是1，也就是到达过这个点
                for(int k=0;k<n;k++) //枚举到达j的点k
                    if(i-(1<<j)>>k&1)//f[i][j]=min(f[i][j],f[i^(1<<j)][k]+weight[k][j]
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
            }
    cout<<f[(1<<n)-1][n-1]<<endl;

return 0;

}