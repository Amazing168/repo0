# include<bits/stdc++.h>
using namespace std;
const int N=2510,M=14000;
int n,m,s,en;
int dist[N],h[N],w[M],e[M],ne[M],idx;
bool st[N];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    
}

int spfa(){
    memset(dist ,0x3f,sizeof dist );
    dist[s]=0;
    queue<int > q;
    q.push(s);
    st[s]=true;
    
    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
                dist [j]=dist [t]+w[i];
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }    
    
    return dist[en];
}
int main(){
    cin>>n>>m>>s>>en;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    cout<<spfa()<<endl;
    
    return 0;
}