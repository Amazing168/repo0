#include<bits/stdc++.h>
//#include<sstream>
using namespace std;
const int N=510;
int n,m;
bool g[N][N];
int stop[N];
int dist [N];

void bfs(){
    memset(dist,0x3f,sizeof dist );
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(g[t][i]&&dist[i]>dist[t]+1){
                dist[i]=dist[t]+1;
                q.push(i);
            }
        }
    }
}
int main(){
    cin>>m>>n;
   
    string line;
    getline(cin,line);
    while(m--){
        getline(cin,line);
        stringstream ssin (line);
        int cnt=0,p;
        while(ssin>>p) stop[cnt++]=p;
        for(int j=0;j<cnt;j++){
            for(int k=j+1;k<cnt;k++) 
            g[stop[j]][stop[k]]=true;
        }
          
    }
    bfs();
    
    if(dist [n]==0x3f3f3f3f) puts("NO");
    else cout<<max(dist[n]-1,0)<<endl;
    
    return 0;
}