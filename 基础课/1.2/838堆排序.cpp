# include<bits/stdc++.h>
using namespace std;

const int N=100010;
int n,m;
int h[N],sz;

void down(int u){
    int t=u;
    if(u*2<=sz&&h[u*2]<h[t]) t=2*u;
    if(u*2+1<=sz&&h[u*2+1]<h[t]) t=2*u+1;
    if(u!=t){
        swap(h[t],h[u]);
        down(t);
    }

}
int main(){
    	scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    	sz =n;
        for(int i=n/2;i>0;i--)down(i);//用oN的方法快速的建立一个小根堆、
        while(m--){
            printf("%d ",h [1]);
            h[1]=h[sz];
            sz --;
            down(1);
        }
    return 0;
}
//堆的五种操作 熟悉up还有down