#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int x1,y1,gcd;
    gcd = exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return gcd;
}
int main(){
    int n,a,b,x,y;
    cin>>n;
    while(n--){
        cin>>a>>b;
        exgcd(a,b,x,y);
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}