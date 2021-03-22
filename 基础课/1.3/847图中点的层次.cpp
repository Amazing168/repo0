# include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m;
int h[N],e[N],ne[N],idx;
int d[N];
void add (int a ,int b){//邻接表储存图
    e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
int bfs(){
    memset(d,-1,sizeof d);
    queue<int >q;//定义队列来进行bfs
    d[1]=0;
    q.push(1);//bfs模板将首元素入队
    while(q.size()){//设置结束的条件，即队中无元素
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){//遍历相应点的邻接表
            int j=e[i];
            if(d[j]==-1){//如果该点还没遍历过就遍历它
                d[j]=d[t]+1;
                q.push(j);//将它入队
            }
        }
    }
    return d[n];
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    cout<<bfs()<<endl;
    return 0;
}