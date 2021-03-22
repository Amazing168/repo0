# include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,p[N],size0[N];//增加一个记录点个数的数组。
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        p[i]=i;
        size0[i]=1;
        
    }
    while(m--){
        char op[3];
        int a,b;
        scanf("%s",op);
        if(op[0]=='C') {

            scanf("%d%d",&a,&b);
            if(find(a)==find(b)) continue;//进行集合合并的时候先判断一下两个元素是否在同一集合里。防止计数加倍
            size0[find(b)]+=size0[find(a)];
            p[find(a)]=find(b);//合并
        }
        else if(op[1]=='1') {
            scanf("%d%d",&a,&b);
            if(find(a)==find(b)) printf("Yes\n");
            else printf("No\n");
        }
        else {
            scanf("%d",&a);
            printf("%d\n",size0[find(a)]);
        }
    } 
    return 0;
}