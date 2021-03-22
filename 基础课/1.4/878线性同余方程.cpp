#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d,x1,y1;
    d=exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return d;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,m,x,y;
        scanf("%d%d%d",&a,&b,&m);//灵活应用公式一定要会推呀！！
        int d=exgcd(a,m,x,y);//d即是求的a,m的gcd
        if(b%d) puts("impossible");
        else printf("%d\n",(long long )x*(b/d)%m );
    }
    return 0;
}