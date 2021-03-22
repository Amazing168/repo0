/*
spfa算法
适用于无负权回路的情况
bellman_ford的优化版本
即将被缩短距离的点入队，来进行更新，只遍历距离变短的点
正权边也能用，被卡就换堆优化的dijkstra算法
O(m) 最坏O(nm)

*/

# include <bits/stdc++.h>
using namespace std;

const int N=100010;
int n,m;
int h[N],ne[N],e[N],w[N],idx;
int dist[N];
bool st[N];
void add(int a,int b,int c){
    
    
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int spfa(){
    memset(dist ,0x3f,sizeof dist);//初始化
    dist[1]=0;
    queue<int> q;
    q.push(1);
    st[1]=true;//记录是否在队列里，避免重复入队
    while(q.size()){
        int t= q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){//更新，wi代表的是t点到与t点邻接的i点距离，深刻理解w数组dist数组的意义！
                dist[j]=dist[t]+w[i];
                if(!st[j]){//判断是否入队
                    q.push(j);
                    st[j]=true;
                    
                }
            }

        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];

}



int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,w ;
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w);
    }
    int t=spfa ();
    if(t==-1) puts("impossible");
    else printf("%d\n",t);
    return 0;
}



