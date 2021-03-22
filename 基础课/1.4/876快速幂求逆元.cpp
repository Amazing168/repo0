#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL qmi(int a,int k,int p){
    LL res =1 ;
    while(k ){
        if(k&1) res=res*a%p;
        k >>=1;
        a=(LL)a*a%p;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,p;
        scanf("%d%d",&a,&p);
        if(a%p==0) puts("impossible");
        else printf("%lld\n",qmi(a,p-2,p));
    }

    return 0;
}