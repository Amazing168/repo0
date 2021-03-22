# include<bits/stdc++.h>
using namespace std;
const int N=10;
int n;
int path[N];//储存的路径上的值
bool st[N];

void dfs(int u){
    if(u==n){//边界条件
        for(int i=0;i<n;i++) printf("%d ",path[i]);
        puts("");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            path[u]=i;
            st[i]=true;
            dfs(u+1);
            st[i]=false;//恢复现场
        }
    }
}
int main(){

    cin>>n;
    dfs(0);
    return 0;
}