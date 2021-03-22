# include<bits/stdc++.h>
using namespace std;
const int N=20;
int n;
char g[N][N];
bool col[N],dg[N],udg[N];//因为是按行的每一位搜索所以只有col一个存列的数组，对角线 dg[u+i]，反对角线udg[n−u+i]中的下标 u+i和 n−u+i 表示的是截距
void dfs(int u){
    if(u==n){   //按行搜索，回溯条件
        for(int i=0;i<n;i++) puts(g[i]);
        puts("");
        return;
    }
    for(int i=0;i<n;i++){
        //剪枝，不符合条件的不在继续搜索
        if(!col[i]&&!dg[i+u]&&!udg[n-u+i]){
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i]=false;//恢复现场，切莫忘记恢复'.'!!!
            g[u][i]='.';
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            g[i][j]='.';
    dfs(0);

    return 0;
}