#include<bits/stdc++.h>
using namespace std;
const int N=810,M=3000;
const int INF=0x3f3f3f3f;
int n,m,cc,id[N];
int dist[N];
bool st[N];
int h[N],w[M],ne[M],e[M],idx;


void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int spfa(int s){
    memset(dist ,0x3f,sizeof dist);
    dist[s]=0;
    queue<int>q;
    q.push(s);
    st[s]=true;
    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist [j]>dist [t]+w[i]){
                dist[j]=dist[t]+w[i];
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<cc;i++){
        int j=id[i];
        if(dist[j]==INF)return INF;
        sum+=dist[j];
    }
    return sum;
}
int main(){
    cin>>cc>>n>>m;
    for(int i=0;i<cc;i++)cin>>id[i];
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    
    int res=INF;
    for(int i=1;i<=n;i++){
     res=min(res,spfa(i));   
    }
    
    cout<<res<<endl;
    return 0;
}

