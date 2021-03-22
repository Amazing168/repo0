/*
以递归的形式进行的dp

记忆化搜索

该类题型的关键还是如何定义数组的代表的含义

该题的f[i][j]代表即是从i,j 开始滑的路径长度。


*/
#include<bits/stdc++.h>
using namespace std;
const int N=320;
int n,m;
int h[N][N];
int f[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

int dp(int x,int y){
    if(f[x][y]!=-1) return f[x][y];

    f[x][y]=1;
    for(int i=0;i<4;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a>=1&&a<=n&&b>=1&&b<=m&&h[a][b]<h[x][y])
            f[x][y]=max(f[x][y],dp(a,b)+1);
    }
    return f[x][y];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&h[i][j]);
    
    memset (f,-1,sizeof f);//初始化

    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            res=max(res,dp(i,j));
    cout<<res<<endl;
    return 0;
}