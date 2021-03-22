/*
匈牙利算法
O(mn)实际远小于nm
月老渣男配对法以求最大化

先预定女孩，在判断她有没有男朋友及她男朋友可不可以找下家，来进行匹配
*/

#include <bits/stdc++.h>
using namespace std;
const int N=510,M=100010;
int n1,n2,m,h[N],e[M],ne[M],idx;
int match[N];//表示与N配对的点是多少
bool st[N];//st[]数组我称为临时预定数组，
            //st[j]=a表示一轮模拟匹配中，女孩j可以男孩a预定了。
void add(int a ,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int x){
    for(int i=h[x];i!=-1;i=ne[i]){
        //遍历自己喜欢的女孩

        int j=e[i];
        if(!st[j]) {//如果在这一轮模拟匹配中,这个女孩尚未被预定
            st[j]=true; //那x就预定这个女孩了
                
            if(match[j]==0||find(match[j])){ //如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。
                                             //配对成功,更新match
                match[j]=x;
                return true ;
            }            
        }
    }//自己中意的全部都被匹配了。配对失败
    return false;
}


int main(){
    scanf("%d%d%d",&n1,&n2,&m);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }

    int res=0;//记录最大匹配
    for(int i=1;i<=n1;i++){

        //因为每次模拟匹配的预定情况都是不一样的所以每轮模拟都要初始化
        memset(st ,false ,sizeof st);
        if(find(i)) res++;
    }
    cout<<res<<endl;
    return 0;
}