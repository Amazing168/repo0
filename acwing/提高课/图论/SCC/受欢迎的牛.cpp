/*
tarjan算法的裸题应用
背熟模板

*/


#include<bits/stdc++.h>
using namespace std;

const int N=10001,M=50010;

int n,m;
int h[N],e[M],ne[M],idx;
int dfn[N],low[N],timetamp;
int stk[N],top;
bool in_stk[N];
int id[N],scc_cnt,size_[N];
int dout[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void tarjan(int u){
    dfn[u]=low[u]=++timetamp;
    stk[++top]=u,in_stk[u]=true;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }
        else if(in_stk[j])low[u]=min(low[u],low[j]);
    }
    
    if(dfn[u]==low[u]){
        ++scc_cnt;
        int y;
        do{
            y=stk[top--];
            in_stk[y]=false;
            id[y]=scc_cnt;
            size_[scc_cnt]++;
        }while(y!=u);
    }
    
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }    
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
            
    for(int i=1;i<=n;i++)
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int a=id[i],b=id[k];
            if(a!=b) dout[a]++;
        }
        
    int zeros=0,sum=0;
    for(int i=1;i<=scc_cnt;i++){
        if(!dout[i]){
            zeros++;
            sum+=size_[i];
            if(zeros>1){
                sum=0;
                break;
            }
        }
    }
    
    printf("%d\n",sum);
    
    return 0;
}