/*
用floyd算法求出任意两点之间的最短距离
求maxd[i] 表示和i连通的且距离i最远的距离
结果  ：
    情况1：所有max[i]的最大值
    情况2：枚举那两个点之间没有边，即满足d[i][j]=INF， dist[i][j]+maxd[i]+maxd[j];

    最后的答案就是两种情况的最大值
*/
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int N=150;
const double INF=1e20;

typedef pair<int ,int > PII;

int n;
PII q[N];
char g[N][N];
double dist[N][N],maxd[N];

double getd(PII a,PII b){
    double dx=a.x-b.x,dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>q[i].x>>q[i].y;
    for(int i=0;i<n;i++) cin>>g[i];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j){
                if(g[i][j]=='1') dist[i][j]=getd(q[i],q[j]);
                else dist[i][j]=INF;
            }
            
    
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            
        
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(dist[i][j]<INF)
                maxd[i]=max(maxd[i],dist[i][j]);
        
    double res1=0;
    for(int i=0;i<n;i++) res1=max(res1,maxd[i]);
    
    
    double res2=INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==INF)
                res2=min(res2,getd(q[i],q[j])+maxd[i]+maxd[j]);
        }
    }
    
    printf("%lf\n",max(res1,res2));
    return 0;
}