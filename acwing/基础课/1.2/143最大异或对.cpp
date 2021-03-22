# include<bits/stdc++.h>
using namespace std;
const int N=100010,M=31*N;
int a[N],son[M][2],idx;

void insert (int x){ //插入，即写索引，son数组不为空就是有值
    int p=0;
    for(int i =30;i>=0;i--){
        int u=x>>i&1;
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
}
int query(int x){//查询
    int p=0,res=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(son[p][!u]){//如果有相反的值存在，即异或之后的数会更大所以选择这个方向。
            p=son[p][!u];
            res=res*2+!u;
            }
        else{
            p=son[p][u];
            res =res*2+u;      
        } 
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int res=0;
    for(int i=0;i<n;i++) {
        insert(a[i]);//不要忘记初始化索引
        res=max(res,a[i]^query(a[i]));}//查询是从已经初始化好的trie树中进行的，所以放在一重循环里即可
    printf("%d\n",res);
    return 0;
}
