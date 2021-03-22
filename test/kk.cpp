
#include <bits/stdc++.h>
using namespace std;

const int N=100010;

int n,m,p[N],path[N];
int sa[N];
struct Edge{

    int a,b,w;
    bool operator <(const Edge &W) const{//重载运算符
        return w<W.w;
    }
}edge[2*N+10];
int find(int x){//并查集的find函数
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int main(){
int T;
cin>>T;
while(T--){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[i]={a,b,c};
    }

    sort(edge,edge+m);
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<m;i++) {
        if(edge[i].w==edge[i-1].w) {sa[i]=1;sa[i-1]=1;}
    }
    int res=0,cnt=0;
    for(int i=0;i<m;i++){
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        a=find (a),b=find(b);
        if(a!=b){
            p[a]=b;
            res+=w;
            path[cnt++]=i;
        }
    }
    
    
    int flag=1;
    for(int i=1;i<=m;i++) if(sa[path[i]]) flag=0;
    if(flag) printf("%d\n",res);
    else {
        int flag0=0;
        
        
        for(int j=0;j<cnt;j++){
            if(sa[path[j]]) {
                sa[path[j]] =2;
                
                for(int i=1;i<=n;i++) p[i]=i;
                int res0=0,cnt0=0;
            //     for(int i=0;i<m;i++) cout<<sa[i]<<" ";
            //    puts("");
                 
                for(int i=0;i<m;i++){
                    if(sa[i]==2) continue;
                    int a=edge[i].a,b=edge[i].b,w=edge[i].w;
                    a=find (a),b=find(b);
                   //  cout<<a<<" "<<b<<endl;
                    if(a!=b){
                      
                        p[a]=b;
                        res0+=w;
                        cnt0++;
                    }
                    
                }
                if(cnt0==n-1) {flag0=1;break;}
            }
            sa[path[j]]==1;   
        }

        if(flag0)puts("Not Unique");
        else printf("%d\n",res);
    }


    for(int i=0;i<=m;i++)edge[i].a=0,edge[i].b=0,edge[i].w=0;
    for(int i=0;i<=m;i++) sa[i] =0;
}
return 0;
}
