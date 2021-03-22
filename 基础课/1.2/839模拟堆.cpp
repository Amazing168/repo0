# include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int h[N];
int ph[N];
int hp[N];
int sz;
//因为题目中要求操作第k个插入的数，所以需要构建两个互相映射的数组hp，ph；
//这个交换过程其实有那么些绕 但关键是理解 如果hp[u]=k 则ph[k]=u 的映射关系
//之所以要进行这样的操作是因为 经过一系列操作 堆中的元素并不会保持原有的插入顺序
//从而我们需要对应到原先第K个堆中元素
//如果理解这个原理 那么就能明白其实三步交换的顺序是可以互换 
//h,hp,ph之间两两存在映射关系 所以交换顺序的不同对结果并不会产生影响
void heap_swap(int u,int v){//新的交换函数
    swap(h[u],h[v]);
    swap(hp[u],hp[v]);
    swap(ph[hp[u]],ph[hp[v]]);
}

void down(int u){
    int t=u;
    if(u*2<=sz&&h[u*2]<h[t]) t=2*u;
    if(u*2+1<=sz&&h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t){
        heap_swap(u,t);
        down (t);
    }
}
void up(int u){
    if(u/2>0&&h[u/2]>h[u]){
        heap_swap(u,u/2);
        up(u/2);
    }
}
int main(){
    int n;
    cin>>n;
    int m=0;
    while(n--){
        string op;
        cin>>op;
        int k,x;
        if(op=="I"){
            cin>>x;
            m++;
            h[++sz]=x;
            ph[m]=sz;
            hp[sz]=m;
            up(sz);
        }
        else if(op=="PM") cout<<h[1]<<endl;
        else if(op=="DM") {
            heap_swap(1,sz);
            sz--;
            down (1);
        }
        else if(op=="D"){
            cin>>k ;
            int u=ph[k];      //这里一定要用u=ph[k]保存第k个插入点的下标，因为在交换函数之后ph【k】的值已经发生了变化
            heap_swap(u,sz);
            sz--;
            up(u);//up,down 两个函数只会执行一个
            down(u);
        }
        else if(op=="C"){
            cin>>k>>x;
            h[ph[k]]=x;
            down(ph[k]);
            up(ph[k]);
        }
    }
return 0;
}