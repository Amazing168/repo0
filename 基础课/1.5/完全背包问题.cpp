/*

将集合的逻辑思路进行下面的整理

//我们列举一下更新次序的内部关系
f[i , j ] = max( f[i-1,j] , f[i-1,j-v]+w ,  f[i-1,j-2*v]+2*w , f[i-1,j-3*v]+3*w , .....)
f[i , j-v]= max(            f[i-1,j-v]   ,  f[i-1,j-2*v] + w , f[i-1,j-2*v]+2*w , .....)
由上两式，可得出如下递推关系： 
                        f[i][j]=max(f[i,j-v]+w , f[i-1][j]) 

for(int i = 1 ; i <=n ;i++)
for(int j = 0 ; j <=m ;j++)
{
    f[i][j] = f[i-1][j];
    if((j-v[i]>=0)
        f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
}


注意与01背包区分

for(int i = 1 ; i<=n ;i++)
    for(int j = v[i] ; j<=m ;j++)//注意了，这里的j是从小到大枚举，和01背包不一样
    {
            f[j] = max(f[j],f[j-v[i]]+w[i]);
    }


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
        for(int j=v[i];j<=m;j++)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    }

    cout<<f[m]<<endl;
    return 0;
}