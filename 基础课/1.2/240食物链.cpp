# include<bits/stdc++.h>
using namespace std;
const int N=50010;
int n,m;
int p[N],d[N];
int find(int x){
    if(p[x]!=x){//并查集，维护有一个到根节点的量，通过同一集合中到根节点距离的区别来标记每个节点间的关系。三种故模3
        int t= find(p[x]);
        d[x]+=d[p[x]];
        p[x]=t;
    }
    return p[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) p[i]=i;//初始化集合
    int res=0;
    while(m--){
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        if(x>n||y>n) res++;
        else {
            int px=find(x),py=find(y);//先求根节点
            if(k==1){
                if(px==py&&(d[x]-d[y])%3) res++;//根节点一样即二者已经在一个集合里了，通过d数组（到根节点的距离）来判断真假
                else if(px!=py){//根节点不一致，则根据节点间的关系，将二者放到一起
                    p[px]=py;
                    d[px]=d[y]-d[x];//模3同余，画图理解更直观
                }
            }
        else {
            if(px==py&&(d[x]-d[y]-1)%3) res++;
            else if (px!=py){
                p[px]=py;
                d[px]=d[y]-d[x]+1;//加入表示吃与被吃的关系，绘图更直观。
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}