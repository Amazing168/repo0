/*
bellman_ford算法
处理带负权边的最短路问题
可以存在负权回路
k表示走只走k条边所得到的源点到各点的距离最小值
O(nm)
*/


# include<bits/stdc++.h>
using namespace std;
const int  N=510,M=10010;
struct Edge{
    int a,b,w ;
}edge [M];

int n,m,k;
int dist[N],backup[N];

int bellman_ford(){
    memset(dist ,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++){//k：限制边数
        memcpy(backup,dist,sizeof dist);//backup数组，用来防止串联错误，因为要控制只走k条边的限制。
        for(int j=0;j<m;j++){
            int a=edge[j].a, b=edge[j].b, w=edge[j].w;
            dist[b]=min(dist[b],backup[a]+w );
        }
            }
    if(dist[n]>0x3f3f3f3f/2) return  -1;///2的原因是因为负权边可能会将INF减小
    return dist[n];
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b,w ;
        scanf("%d%d%d",&a,&b,&w);
        edge[i]={a,b,w };
    }
    int t=bellman_ford();
    if(t==-1) puts("impossible");
    else printf("%d\n",t);
    return 0;
}