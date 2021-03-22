//堆优化版的dijkstra算法适合稀疏图，点和边的数量差不多
//O（ｍｌｏｇｎ）
#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,int > PII;
const int N=1000010;
int n,m;
int h[N],ne[N],e[N],w[N],idx;//稀疏图，用邻接表来存
int dist[N];
bool st[N];

void add(int a ,int b,int c){//增加记录权重的数组w
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;

}
int dijkstra(){
    memset(dist,0x3f,sizeof dist);// dist数组存储的即由源点到各个点的距离
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;//小根堆的定义，
    heap.push({0,1});//代表的是点1，距离源点的距离是0
    while(heap.size()){
        auto t=heap.top();//直接取出距离源点最小的st数组外的点
        heap.pop();//弹出
        int ver=t.second,distance=t.first;//开始用它更新dist数组
        if(st[ver]) continue;//冗余备份，为真说明已经用它更新过dist数组，直接跳过
        st[ver]=true;
        for(int i=h[ver];i!=-1;i=ne[i]){//遍历邻接表
            int j=e[i];
            if(dist[j]>distance+w[i]){
                dist[j]=distance+w[i];
                heap.push({dist[j],j});//向堆中加入点


                
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    printf("%d\n",dijkstra());

    return 0;
}