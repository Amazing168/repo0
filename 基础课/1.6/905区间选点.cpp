/*
贪心的经典题型
证明的话，可以参考a=b的证明方式
将右端点排序，然后从左向右进行遍历记录符合题意的区间或者点

*/



#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
struct Range{
    int l,r;
    bool operator < (const Range &W) const 
    {
        return r<W.r;
    }
}range[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        range[i]={l,r};
    }
    sort (range,range+n);
    int res=0,ed=-2e9;
    for(int i=0;i<n;i++){
        if(range[i].l>ed){
            res++;
            ed=range[i].r;
        }
    }
    printf("%d\n",res);

}
