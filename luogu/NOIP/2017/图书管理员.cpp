//P3955
#include <bits/stdc++.h>
using namespace std;

int n,q;//n图书数量、q读者数量
const int N = 1010;
int id[N],len,b;//b为编码    
int main(){

    cin >> n >> q;
    for(int i=0;i<n;i++) cin>>id[i];
    
    sort(id,id+n);
    
    for(int i=1;i<=q;i++){
        bool flag = 0;
        cin>>len>>b;

        int t =pow(10,len);
    
        for(int j=0;j<n;j++)
            if(id[j]%t==b){
                
                flag=1;
                cout<<id[j]<<endl;
                break;
            }
    
        if(!flag){
            cout<<-1<<endl;
        }
    }
    
    return 0;
}