/*
排队打水 
磨蹭的先打那么所有人的等待时间就是最短的

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100010;
int n,t[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)  scanf("%d",&t[i]);
    sort(t,t+n);
    LL res=0;
    for(int i=0;i<n;i++) res+=t[i]*(n-i-1);
    printf("%lld\n",res);
    return 0;
}
