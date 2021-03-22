//一维优化+二进制优化
/*
二进制优化即将多重背包分为若干组，在按照01背包处理
分的时候按照二进制的原则来分，保证可以通过不同堆之间的组合，得到原来背包的任意数量
*/

#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int f[N];
int n,m;

struct good{
    int v,w ;
};
int main(){
    cin>>n>>m;
    vector<good> S;
    while(n--){
        int v,w ,s;
        cin>>v>>w>>s;
        for(int k=1;k<=s;k*=2){
            s-=k;
            S.push_back({k*v,k*w});
        }
        if(s>0)S.push_back({s*v,s*w});
    }
    for(auto t:S){
        for(int j=m;j>=t.v;j--)
            f[j]=max(f[j],f[j-t.v]+t.w);
    }
    cout<<f[m]<<endl;
    return 0;
}