/*
卢卡斯定理
C(a,b)=C(a%p,b%p)*C(a/p,b/p)%p
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int p;
int qmi(int a,int k){
    int res=1;
    while(k){
        if(k&1) res=(LL)res*a%p;
        k>>=1;
        a=(LL)a*a%p;
    }
    return res;
}
int C(int a,int b){
    int res=1;
    for(int i=1,j=a;i<=b;i++,j--){
        res=(LL)res*j%p;
        res=(LL)res*qmi(i,p-2)%p;
    }
    return res;
}

int lucas(LL a,LL b){
    if(a<p&&b<p) return C(a,b);
    return (LL)C(a%p,b%p)*lucas(a/p,b/p)%p;
}
int  main(){
        int n;
        cin>>n;
        while(n--){
            LL a,b;
            cin>>a>>b>>p;
            cout<<lucas(a,b)<<endl;
        }

    return 0;
}