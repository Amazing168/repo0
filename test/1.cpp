#include <stdio.h>

const int N=1001;
int a[N][9999];
int cnt[N];

int main(){
    a[0][0]=1;
    cnt[0]=1;
    for(int i=1;i<N;i++){
        int t=0;
        int num=0;
        for(int j=0;j<cnt[i-1];j++){
            t=a[i-1][j]*i+t;
            a[i][num++]=(t%10);
            t/=10;
        }
        while(t){
            a[i][num++]=(t%10);
            t/=10;
        }
        cnt[i]=num;
    }

    int T;
    int n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        printf("%d\n",a[n][m-1]);
    }
    return 0;
}