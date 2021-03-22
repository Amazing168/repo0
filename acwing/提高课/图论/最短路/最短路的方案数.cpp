/*

必须是在拓扑上才可以用dp的思想
有dij和bfs产生的最短路符合这一个条件
spfa不行

但如果图中存在负权边只能用该算法做，也能做但是比较麻烦
先跑一遍spfa找到每个点的最短距离,把最短路拓扑树建立出来，
看哪一条边dist[j] == dist[t] + w[i],然后更新它。

*/


#include<bits/stdc++.h>
using namespace std;

const int N=100010,M=400040,mod=100003;

int n,m;
int h[N],e[M],ne[M],idx;
int dist[N],cnt[N];


void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}


void bfs(){
    
    memset(dist,0x3f,sizeof dist );
    dist[1]=0,cnt[1]=1;
    queue<int > q;
    q.push(1);
    while(q.size()){
        int t=q.front();
        q.pop();
        
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+1){
                dist[j]=dist[t]+1;
                cnt[j]=cnt[t];
                q.push(j);
            }
            else if(dist[j]==dist[t]+1){
                cnt[j]=(cnt[j]+cnt[t])%mod;
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    bfs();
    for(int i=1;i<=n;i++) printf("%d\n",cnt[i]);
    return 0;
}