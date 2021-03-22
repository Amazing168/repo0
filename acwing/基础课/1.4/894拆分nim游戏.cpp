/*
相比于集合-Nim，这里的每一堆可以变成不大于原来那堆的任意大小的两堆
即a[i]a[i]可以拆分成(b[i],b[j])(b[i],b[j]),为了避免重复规定b[i]>=b[j]b[i]>=b[j],即：a[i]>=b[i]>=b[j]a[i]>=b[i]>=b[j]
相当于一个局面拆分成了两个局面，由SG函数理论，多个独立局面的SGSG值，等于这些局面SGSG值的异或和。
因此需要存储的状态就是sg(b[i])sg(b[i])^sg(b[j])sg(b[j])（与集合-Nim的唯一区别）

一定读清题意，不是分成两堆，而是放入两堆新的小于原来数量的就行

*/


#include<bits/stdc++.h>
using namespace std;
const int N=110;
int f[N];
int n;
int sg(int x){
    if(f[x]!=-1) return f[x];

    unordered_set<int > S;
    for(int i=0;i<x;i++)
        for(int j=0;j<=i;j++)
            S.insert(sg(i)^sg(j));

    for(int i=0;;i++) 
        if(!S.count(i)) return f[x]=i;

}

int main(){
    int n;
    cin>>n;
    memset(f,-1,sizeof f);
    int res=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        res^=sg(x);
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}