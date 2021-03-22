/*
绝对值不等式的应用，
将货仓建在中间的时候最短
证明的话就从前到后每两个一组，利用两点之间的距离表示


若是二维的话就用三分
多维的话就得使用模拟退火来进行操作了。

*/
# include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
int q[N];

int main(){
    int res=0;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&q[i]);
    sort(q,q+n);

    for(int i=0;i<n;i++) res+=abs(q[i]-q[n/2]); 

    printf("%d\n",res);
    return 0;
}