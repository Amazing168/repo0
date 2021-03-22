
#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int d[N][N];
int main(){

    cin>>n>>m;
    memset(d,0x3f,sizeof d);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b]=d[b][a]=min(d[a][b],c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int res=0;
    for(int i=2;i<=n;i++){
        if(d[1][i]==0x3f3f3f3f){
            res=-1;
            break;
        }
        res=max(res,d[1][i]);
    }
    cout<<res<<endl;
    return 0;
}