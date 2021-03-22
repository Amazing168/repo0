/*
最短路问题之后一律使用对优化半的dijkstra算法

*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int >PII;
const int N=110,M=10010,INF=0x3f3f3f3f;
int n,m;
int dist[N];
bool st[N];
int level[N];
int h[N], w[M],e[M],ne[M],idx;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int  di(int down,int up){
    memset (dist,0x3f,sizeof dist);
    memset (st ,0,sizeof st);
    dist[0]=0;//初始化的是源点的距离
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    heap.push({0,0});//加入堆的点距离源点的距离，以及点
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        int ver=t.second,dis=t.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dis+w[i]&&level[j]>=down&&level[j]<=up){
                dist[j]=dis+w[i];
                heap.push({dist[j],j});
            }
        }
    }
return dist [1];
}

int main(){
    
    cin>>m>>n;
    
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int price,le,cnt;
        cin>>price>>le>>cnt;
        level[i]=le;
        add(0,i,price);
        while(cnt--){
            int id,p;
            cin>>id>>p;
            add(id,i,p);
        }
    }
    int res=INF;
    
    for(int i=level[1]-m;i<=level[1];i++) res=min(res,di(i,i+m));
    //遍历
    cout<<res<<endl;
    
    return 0;
}
