/*
Kruskal算法求最小生成树
O(mlogm)
适用于稀疏图

先按边权排序，然后从小枚举边，
判断两点是否在一个连通块中，不断加入集合，
最后通过集合里的点数判断是否存在最小生成树
*/

#include <bits/stdc++.h>
using namespace std;

const int N=100010;

int n,m,p[N];
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
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[i]={a,b,c};
    }

    sort(edge,edge+m);
    for(int i=1;i<=n;i++)p[i]=i;
    int res=0,cnt=0;
    for(int i=0;i<m;i++){
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        a=find (a),b=find(b);
        if(a!=b){
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    if(cnt==n-1) printf("%d\n",res);
    else puts("impossible");  
}
