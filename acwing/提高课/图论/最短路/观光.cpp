/*
求最短路和次短路及其方案数的一道典型例题

将最短路和次短路看作是两个点来进行操作

*/

#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=20010;

int n,m,S,T;
int dist[N][2],cnt[N][2];
int h[N],e[M],ne[M],w[M],idx;
bool st[N][2];

struct ver{
    int id,type,dis;
    bool operator >(const ver & W) const{
        return dis>W.dis;
    } 
};

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);

    priority_queue<ver,vector<ver>,greater<ver> > heap;
    dist[S][0]=0,cnt[S][0]=1;
    heap.push({S,0,0});
    
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        int ver=t.id,type=t.type,distence=t.dis,count=cnt[ver][type];
        
        if(st[ver][type]) continue;
        st[ver][type]=true;
        
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dist[j][0]>distence+w[i]){//此时最短路变成了次短路
                dist[j][1]=dist[j][0],cnt[j][1]=cnt[j][0];
                heap.push({j,1,dist[j][1]});
                
                dist[j][0]=distence+w[i],cnt[j][0]=count;
                heap.push({j,0,dist[j][0]});
            }
            
            else if(dist[j][0]==distence+w[i])    cnt[j][0]+=count;
            
            else if(dist[j][1]>distence+w[i]){
            
                dist[j][1]=distence+w[i],cnt[j][1]=count;
                heap.push({j,1,dist[j][1]});
                
            }
            else if(dist[j][1]==distence+w[i])    cnt[j][1]+=count;
            
        }
    }
    int res=cnt[T][0];
    if((dist[T][0]+1)==dist[T][1])res+=cnt[T][1];
    return res;
}

int main(){
    int dd;
    scanf("%d",&dd);
    while(dd--){
        scanf("%d%d",&n,&m);
        memset(h,-1,sizeof h);
        idx=0;  
        
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }
        
        scanf("%d%d",&S,&T);

        printf("%d\n",dijkstra());
    }
    
    return 0;
}