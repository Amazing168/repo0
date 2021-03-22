# include<bits/stdc++.h>
using namespace std;
const int N=100010;
int son[N][27],cnt[N],idx;//首先一定要理解好idx的含义：即节点标号（所以每个节点的idx都是唯一的），代表着在链式存储中的每个节点的标志
char str[N];                //son存储即每个节点的儿子节点的idx，cnt数组存储就是每个节点的数量（即每个串的数量）
void insert(char *str){
    int p=0;//p即初始的root节点
    for(int i=0;str[i];i++){
        int  u=str[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;//下标是0的节点既是根节点，又是空节点
        p=son[p][u];
    }
    cnt[p]++;
}
int query(char *str){
    int p=0;
    for(int i=0;str[i];i++) {
        int u=str[i]-'a';
        if(!son[p][u]) return 0;
        p=son[p][u];
    }
    return cnt[p];
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char op[2];
        scanf("%s%s",op,str);
        if(op[0]=='I') insert(str);
        else printf("%d\n",query(str));
        }
    return 0;
}