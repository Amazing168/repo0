# include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N],q[N];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf ("%d",&a[i]);
    int hh=0,tt=-1;
    for(int i=0;i<n;i++){
        if(hh<=tt&&i-k+1>q[hh]) hh++;//q数组是维护的单调队列，所以它的长度不会超过K，一直维护它
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;//判断队尾的值是否小于即将要插入的元素，根据要求进行维护
        q[++tt] =i;//将下标放到队尾，q数组存的是a数组的下标。
        if(i>=k-1) printf("%d ",a[q[hh]]);
    }
puts("");//换行
hh=0,tt=-1;
for(int i=0;i<n;i++){
    if(hh<=tt&&i-k+1>q[hh])hh++;
    while(hh<=tt&&a[q[tt]]<=a[i])tt--;
    q[++tt]=i;
    if(i>=k-1) printf("%d ",a[q[hh]]);
}
puts("");
    return 0;
}