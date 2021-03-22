/*
超级源点的一个典型题型

通过设立一个超级源点的方法可以用来求，从任一起点到某一个或者多个终点的方法

*/

# include<bits/stdc++.h>
using  namespace std;

typedef pair<int ,int >PII;

const int N=1010,M=21010,INF=0x3f3f3f3f;

int n,m,s;
int h[N],w[M],ne[M],e[M],idx;
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

/*

堆优化版的dijkstra算法，本质上还是一个dijkstra算法，每个点自始至终都只会入堆一次

*/
void dijkstra(){
    memset (st,0,sizeof st);
    memset (dist ,0x3f,sizeof dist);
    
    dist[0]=0;    
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    heap.push({0,0});

    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        
        int ver=t.second,dis=t.first;
        
        if(st[ver]) continue;
        st[ver]=true;
        
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dis+w[i]){
                dist[j]=dis+w[i];
               heap.push({dist[j],j});
            }   
        }       
    }
}
int main(){
    
    while(scanf("%d%d%d",&n,&m,&s)!=EOF){
        
        memset(h,-1,sizeof h);
        
        while(m--){
            
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }
        int a,b;
        scanf("%d",&a);
        for(int i=0;i<a;i++){
            scanf("%d",&b);
         
            add(0,b,0);
        }
        dijkstra();
        if(dist[s]==0x3f3f3f3f) printf("-1\n");
        else printf("%d\n",dist[s]);
    }
    return 0;
}
