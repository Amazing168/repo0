/*
这题没做过是真的想不到呀，
从小到大排序一定存在相邻和i+1有wi+si>wi+1+si+1
会使得
两只牛交换后危险值不会变大
max(交换前)≥max(交换后)所有风险的最大值起码不会变大
即只要wi+si不是严格递增,则我们可以把他们变成递增的并且所有风险的最大值不会变大


*/
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
const int N=50010;
 
typedef pair<int ,int > PII;
int n;
PII a[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int w,s;
        scanf("%d%d",&w,&s);
        a[i]={w+s,w };
    } 

    sort(a,a+n);
    int res=-1e9;
    for(int i=0,sum=0;i<n;i++){
        int w=a[i].y,s=a[i].x-w;
        res=max(res,sum-s);//风险 = 上面的重量-当前的承受
        sum+=w;
    }
    cout<<res<<endl;
    return 0;
}
