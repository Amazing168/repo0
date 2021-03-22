# include<bits/stdc++.h>
using namespace std;
const int N=200003,null=0x3f3f3f3f;

int h[N+10];
int find(int x){//开放地址法，该find函数返回的是x在散列表中的下标
    int k=((x%N)+N)%N;
    while(h[k]!=null&&h[k]!=x) {
        k++;
        if(k==N)k=0;
    }
    return k;
}

int main(){
    int n;
    scanf("%d",&n);
    memset(h,0x3f,sizeof h);
    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(*op=='I') {
            h[find(x)]=x;
        }
        else{
            if(h[find(x)]==null)cout<<"No"<<endl;
            else cout<<"Yes"<<endl; 
        }
    }
    return 0;
}