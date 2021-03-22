
//朴素的dijkstra算法，适合稠密图，点少边多
//O（n2）
#include <bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
int g[N][N];

int dist[N];
bool st[N];
int dijkstra(){
    memset(dist,0x3f,sizeof dist);// dist数组存储的即由源点到各个点的距离
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])) t=j;        
        }//找到没有进入st数组的距离最小的点
         st[t]=true;//标记进入st数组
         for(int j=1;j<=n;j++)//更新dist数组
                dist[j]=min(dist[j] ,dist[t]+g[t][j]);
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}
int main(){
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=min(g[a][b],c);//因为该题是个稠密图，两点之间存在多个路径，取最小
    }
    printf("%d\n",dijkstra());

    return 0;
}