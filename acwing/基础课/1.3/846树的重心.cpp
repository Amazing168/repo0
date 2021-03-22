# include<bits/stdc++.h>
using namespace std;
const int N=10010,M=N*2;
int n,m;
int h[N],e[M],ne[M],idx;
bool st[N];
int ans=N;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++; 
}

//返回以u为根的子树中的点的数量
int dfs(int u){
    st[u]=true;//标记一下，已经被搜索过了
    int sum=1,res=0;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            int s =dfs(j);//求字数的点数
            res=max(res,s);
            sum+=s;        
        }
    }
    res=max(res,n-sum);//取子树中的点数与上面的最大值
    ans = min(ans,res);//可能答案里的最小值
    return sum;
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);        
    }
    dfs(1);
    cout<<ans<<endl;//输出答案。
}