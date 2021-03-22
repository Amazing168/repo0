#include<bits/stdc++.h>
using namespace std;
const int N=6;
char g[N][N],backup[N][N];
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,1,-1};

void turn(int x,int y){
    for(int i=0;i<5;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a>=0&&a<5&&b>=0&&b<5){
            g[a][b]^=1;
        }
    }
}

int work(){
    int ans=10;
    for(int k=0;k<32;k++){//枚举第一行的32种状态
        int res=0;
        memcpy(backup,g,sizeof g);
        for(int j=0;j<5;j++){
            if(k>>j&1){
                res++;
                turn(0,j);
            }
        }
        for(int i=0;i<4;i++){//为了将i行变亮去调整i+1行
            for(int j=0;j<5;j++){
                if(g[i][j]=='0'){
                    res++;
                    turn(i+1,j);
                }
            }
        }

        bool is_success=true;
        for(int j=0;j<5;j++){//判断最后一行全亮了没
            if(g[4][j]=='0'){
                is_success=false;
                break;
            }
        }
        if(is_success)ans=min(ans,res);
        memcpy(g,backup,sizeof g);
    }
    if(ans>6) return -1;
    else return ans ;

}

int main(){
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<5;i++)cin>>g[i];
        cout<<work()<<endl;

    }
    return 0;
}