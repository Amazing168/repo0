/*
注意理解好q数组的含义
q[i]的含义是长度为i的子序列的末尾最小的数。

*/
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
int a[N];
int q[N];//初始化一个记录长度的数组，q[i]代表长度为i的子序列的最小的末尾元素。


int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    int len=0;
    q[0]=-2e9;//设置一个哨兵
    for(int i=0;i<n;i++){
        int l=0,r=len;
        while(l<r){//二分找到相应的添加位置最小的那个数，应为前面大的那个数并没有什么用哈哈哈。
            int mid=l+r+1>>1;
            if(q[mid]<a[i]) l=mid;
            else r=mid-1;
        }
        len =max(len,r+1);
        q[r+1]=a[i];
  //      cout<<len<<' '<<q[len]<<endl;

    }
    printf("%d\n",len);

    return 0;
}