#include<bits/stdc++.h>
using namespace std;

const int N=15,INF=0x3f3f3f3f;


int n,f,p;
bool vis[N];
struct node{
    int len;
    int a[N];
    bool flag;
} lou[11];
int jishu;
int main(){
    while(scanf("%d%d%d",&n,&f,&p)){
        if(n==0&&f==0&&p==0) break;
        for(int i=0;i<n;i++){
            int len1;
            cin>>len1;
            lou[i].len=len1;
            for(int j=0;j<len1;j++)cin>>lou[i].a[j];
            char c;
            cin>>c;
            if(c=='Y') lou[i].flag=true;
            else lou[i].flag=false;
        }
        int ans=INF;
        for(int i=1;i<=f;i++){
            for(int j=f;j<=n;j++){
                memset(vis,0,sizeof(vis));
                bool f1=false,f2=true;
                for(int k=i;k<=j;k++){
                    if(lou[k].flag) f1=true;
                    for(int l=0;l<lou[k].len;l++){
                        vis[lou[k].a[l]]=true;
                    }
                }
                for(int k=1;k<=p;k++)
                    if(!vis[k]) f2=false;
                if(f1&&f2)
                    ans=min(ans,(j-i)*2);
            }
        }
        if(ans==INF) printf("Test case #%d: Impossible\n",++jishu);
        else printf("Test case #%d: %d\n",++jishu,ans);
        puts("");
    }
    return 0;
}