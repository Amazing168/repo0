/*
朴素版的prim算法，适用于稠密图
时间复杂度 O(n^2)
集合即为最小生成树的点集
每次找到距离集合最近的点将它加入到集合中并用它更新其他点到集合的距离

*/

# include<bits/stdc++.h>
using namespace std;

const int N=510,INF=0x3f3f3f3f;
int n,m;
int g[N][N];
int dist[N];//表示每个点到答案点集的距离
bool st[N];
int prim(){
    memset(dist ,0x3f,sizeof dist);
    int res=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!st[j]&&(t==-1||dist[t]>dist[j])) t=j;
            //找到距离集合距离最小的点
        if(i&&dist[t]==INF) return INF; //存在连通块，i不为0即非第一个点。
        if(i) res+=dist[t];//i不为0即非第一个点，更新结果
        for(int j=1;j<=n;j++)  dist[j]=min(dist[j],g[t][j]);
        st[t]=true;
    }
    return res;
}

int main(){

    memset(g,0x3f,sizeof g);
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    int t=prim();
    if(t==INF) puts("impossible");
    else printf("%d\n",t);
    return 0;
}