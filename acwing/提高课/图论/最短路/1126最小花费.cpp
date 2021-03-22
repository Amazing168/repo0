
#include<bits/stdc++.h>
using namespace std;
const int N=2100;
double d[N][N];
double dist [N];
bool st[N];
int n,m,A,B;
void di(){
    dist[A]=1;
   
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]<dist[j]))
            t=j;
        }
        st[t]=true;
        for(int i=1;i<=n;i++){
            if(dist[i]<dist[t]*d[t][i])
            dist[i]=dist[t]*d[t][i];
        }
    }
    
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a][b]=d[b][a]=max(d[a][b],(100.0-c)/100);
    }
    cin>>A>>B;
    di();
    printf("%.8lf\n",100/dist[B]);
    return 0;
}