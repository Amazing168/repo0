#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int n,m;
int h[N],ne[N],e[N],idx;
int q[N],d[N];
void add (int a, int b){// 背邻接表存图的模板
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool topsort(){
    int hh=0,tt=-1;//。初始化队列
    for(int i=1;i<n;i++){//将入读为0的点入队
        if(d[i]==0)q[++tt]=i;
    }
    while(hh<=tt){//开始bfs的模板
        int t=q[hh++];//取队首
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            d[j]--;//将入度减一，若入度变为了0，则将它入队
            if(!d[j]){
                q[++tt]=j;
            }

        }
    }
 return tt==n-1;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        d[b]++;
    }
    
    if(topsort()){//因为用的数组模拟的队列，
    
        for(int i=0;i<n;i++) printf("%d ",q[i]);
        puts("");
    }
    else puts("-1");


    return 0;
}