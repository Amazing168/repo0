/*

边权是0和1 可以使用双端队列进行宽搜
与平时的迷宫问题相比，增加了钥匙
增加相应的状态

*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef  pair<int ,int>PII;
const int N=11,M=N*N,E=400,P=1<<10;

int h[M],e[E],ne[E],w[E],idx;
int g[N][N],key[M];
int dist[M][P];
int n,m,p,k;
bool st[M][P];
set<PII> edges;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int bfs(){
    memset(dist,0x3f,sizeof dist);
    dist[1][0]=0;
    
    deque<PII> q;
    q.push_back({1,0});
    
    while(q.size()){
        auto t=q.front();
        q.pop_front();
        
        if(st[t.x][t.y]) continue;
        st[t.x][t.y]=true;
        
        if(t.x==n*m) return dist[t.x][t.y];
        
        if(key[t.x]){
            int state=t.y | key[t.x];
            if(dist[t.x][state]>dist[t.x][t.y]){
                dist[t.x][state]=dist[t.x][t.y];
                q.push_front({t.x,state});
            }
        }
        
        for(int i=h[t.x];~i;i=ne[i]){
            int j=e[i];
            if(w[i]&&!(t.y>>w[i]-1&1))continue;
            if(dist[j][t.y]>dist[t.x][t.y]+1){
                dist[j][t.y]=dist[t.x][t.y]+1;
                q.push_back({j,t.y});
            }
            
        }
    }
    return -1;
}


void build(){
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int u=0;u<4;u++){
                int x=i+dx[u],y=j+dy[u];
                if(!x||!y||x>n||y>m)continue;
                int a=g[i][j],b=g[x][y];
                if(edges.count({a,b})==0) add(a,b,0);
            }
}

int main(){
    cin>>n>>m>>p>>k;
    for(int i=1,t=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            g[i][j]=t++;
    memset(h,-1,sizeof h);
    while(k--){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        int a=g[x1][y1],b=g[x2][y2];
        edges.insert({a,b}),edges.insert({b,a});
        if(c) add(a,b,c),add(b,a,c);
    }
    
    build(); 
    
    int s;
    cin>>s;
    
    while(s--){
        int a,b,id;
        cin>>a>>b>>id;
        key[g[a][b]]|=1<<id-1;
    }    
    
      
        
    cout<<bfs()<<endl;
    
    return 0;
}