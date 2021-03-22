/*
1.Mex运算:
设S表示一个非负整数集合.定义mex(S)为求出不属于集合S的最小非负整数运算,即:
mes(S)=min{x};
例如:S={0,1,2,4},那么mes(S)=3;

2.SG函数
在有向图游戏中,对于每个节点x,设从x出发共有k条有向边,分别到达节点y1,y2,····yk,定义SG(x)的后记节点y1,y2,····
yk的SG函数值构成的集合在执行mex运算的结果,即:
SG(x)=mex({SG(y1),SG(y2)····SG(yk)})
特别地,整个有向图游戏G的SG函数值被定义为有向图游戏起点s的SG函数值,即 SG(G)=SG(s).

3.有向图游戏的和
设G1，G2,····,Gm是m个有向图游戏.定义有向图游戏G,他的行动规则是任选某个有向图游戏Gi,并在Gi上行动一步.G被称为有向图游戏G1,G2,·····,Gm的和.
有向图游戏的和的SG函数值等于它包含的各个子游戏SG函数的异或和,即:
SG(G)=SG(G1)xorSG(G2)xor···xor SG(Gm)

*/

#include<bits/stdc++.h>
using namespace std;
const int N=110,M=10010;
int s[N],f[M];//s数组存的是可以拿去个数的集合，f存的是下标的sg的值
int n,m;
int sg(int x){
    if(f[x]!=-1) return f[x];//记忆化搜素，避免重复的计算sg函数

    unordered_set<int > S;
    for(int i=0;i<m;i++){
        int sum=s[i];
        if(x>=sum) S.insert(sg(x-sum));
    }

    for(int i=0;;i++){
        if(!S.count(i)) return f[x]=i;
    }


}

int main(){
    cin>>m ;
    for(int i=0;i<m;i++) cin>>s[i];
    memset(f,-1,sizeof(f));
    
    cin>>n;
    int res=0;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        res^=(sg(x));
    } 
    if(res)puts("Yes");
    else puts("No");
    return 0;
}