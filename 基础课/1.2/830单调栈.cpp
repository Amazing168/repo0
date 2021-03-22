# include <bits/stdc++.h>
using namespace std;

const int N=100010;
int stk[N],tt;
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        scanf("%d",&x);
        while(tt&&stk[tt]>=x) tt--;//构造单调栈，将不符合条件的值，弹出
        if(!tt) printf("-1 ");
        else printf("%d ",stk[tt]);
        stk[++tt]=x;//将当前的值入栈
    }
    return 0;
}