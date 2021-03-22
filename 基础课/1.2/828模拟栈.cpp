# include<bits/stdc++.h>
using namespace std;
const int N=100010;
int m;
int skt[N],tt=0;
int main(){
    cin>>m;
    while(m--){
        string op;
        int x;
        cin>>op ;
        if(op=="push") {cin>>x;skt[++tt]=x;}
        else if(op=="pop") tt--;
        else if(op=="empty") cout<<(tt?"NO":"YES")<<endl;
        else cout<<skt[tt]<<endl;
    }
    return 0;
}