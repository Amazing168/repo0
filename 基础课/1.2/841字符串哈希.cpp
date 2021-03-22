/*
字符哈希串的意思 其实就是将字符串的前缀转换为数来存值
由于每位的权值是不一样的 所以每个前缀值都对应着唯一的一种字符串
所以相减后的值也应该是唯一的 从而利用相减后的值可以判断字符串的区间段是否相等
当然具体还有很多细节需要注意
请看以下代码*/
# include<bits/stdc++.h>
using namespace std;
const int N=100010,P=131;//P为经验值权重 131或13331
typedef unsigned long long ULL;//mod2^64即溢出自然取模
int n,m;
char str[N];
ULL h[N],p[N];//h存放的是前缀值，p存放的是P权重下的各位的权值
ULL get (int l,int r){
    return h[r]-h[l-1]*p[r-l+1];//相当于让二者的数量级相同之后在进行运算
}
int main(){
    scanf("%d%d%s",&n,&m,str+1);
    p[0]=1;
    for(int i=1;i<=n;i++){//预处理权值和前缀值
        p[i]=p[i-1]*P ;
        h[i]=h[i-1]*P +str[i];
    }
    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)==get(l2,r2)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}