/*
这题主要在分析题意，

(SPFA) O(n+km)O(n+km)
先求出：

从 1 走到 i 的过程中，买入水晶球的最低价格 dmin[i]；
从 i 走到 n 的过程中，卖出水晶球的最高价格 dmax[i]；
然后枚举每个城市作为买卖的中间城市，求出 dmax[i] - dmin[i] 的最大值即可。

求 dmin[i] 和dmax[i]时，由于不是拓扑图，状态的更新可能存在环，因此不能使用动态规划，只能使用求最短路的方式。
另外，我们考虑能否使用 dijkstra 算法，如果当前 dmin[i] 最小的点是 5，那么有可能存在边 5-> 6, 6-> 7, 7-> 5，假设当前 dmin[5] = 10，
则有可能存在 6 的价格是11， 但 7 的价格是3，那么 dmin[5] 的值就应该被更新成3，因此当前最小值也不一定是最终最小值，
所以dijkstra算法并不适用，
我们只能采用 spfa 算法。

时间复杂度
瓶颈是SPFA，SPFA 算法的时间复杂度是 O(km)，其中 k 一般情况下是个很小的常数，最坏情况下是 n,n 表示总点数，m 表示总边数。
因此总时间复杂度是 O(km)。


*/

#include<bits/stdc++.h>
using namespace std;

const int N=100010,M=2000010,INF=0x3f3f3f;

int n,m;
int w[N];
int hs[N],ht[N],e[M],ne[M],idx;
int dmin[N],dmax[N];
bool st[N];

void add(int h[],int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}


void spfa(int *h,int *dist,int type){
    queue<int >q;
    memset(st,0,sizeof st);
    if(type==0){ 
        memset(dmin,0x3f,sizeof dmin);
        q.push(1);
        dist[1]=w[1];
    }
    else{ 
        memset (dmax,-0x3f,sizeof dmax);
        q.push(n);
        dist[n]=w[n];
    }
    
    
    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=false;
        
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(type==0&&dist[j]>min(dist[t],w[j])||type==1&&dist[j]<max(dist[t],w[j])){
                 if(type==0) dist[j]=min(dist[t],w[j]);
                 else dist[j]=max(dist[t],w[j]);
                 if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    
    memset(hs,-1,sizeof hs);
    memset(ht,-1,sizeof ht);
    
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(hs,a,b),add(ht,b,a);
        if(c==2)add(hs,b,a),add(ht,a,b);
        
    }
    
    spfa(hs,dmin,0);
    spfa(ht,dmax,1);
    
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dmax[i]-dmin[i]);
    
    printf("%d\n",res);
}

