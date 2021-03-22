# include <bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=1000010;
int ne[N];
int n,m;
char s[M],p[N];
int main(){
    cin>>n>>p+1>>m>>s+1;//让字符串的下标从1开始
    for(int i=2,j=0;i<=n;i++){//初始化ne数组，ne【j】数组存的是到下标为j的子串后缀，
        while(j&&p[i]!=p[j+1]) j=ne[j];//与前缀相同的最大长度
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }
    for(int i=1,j=0;i<=m;i++){//开始匹配
        while(j&&s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==n){
            printf("%d ",i-n);//匹配成功输出起始位置
            j=ne[j];
        } 
    }
    
    return 0;
}