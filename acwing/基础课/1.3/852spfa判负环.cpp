//增加一个记录走了几条边的数组cnt
# include <bits/stdc++.h>
using namespace std;

const int N=100010;
int n,m;
int h[N],ne[N],e[N],w[N],idx;
int dist[N];
bool st[N];
int cnt[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int spfa(){
  queue<int>q;
  memset(dist,0x3f,sizeof dist);//不管dist数组的初值是多少，都是可以的。
  for(int i=1;i<=n;i++){//因为只要有负环存在，就必然有某些点的距离是负无穷，
      st[i]=true;//所以不管距离被初始化成何值，都一定严格大于负无穷，所以一定会被无限更新。
      q.push(i);
  }
    while(q.size()){
        int t= q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j);     
                    st[j]=true;
                }
            }

        }
    }
    return false;

}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,w ;
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w);
    }
    if(spfa ())puts("Yes");
    else puts("No");
    return 0;
}
