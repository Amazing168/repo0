#include<bits/stdc++.h>
using namespace std;
int s[111][111],cnt[111];
int main(){
    int T;
    cin>>T;
    while(T--){
        int a,k;
        cin>>a>>k;
        while(k--){
            int x;
            cin>>x;
            s[x][a]=1;
            cnt[x]++;
        }
    }
    int max=1;
    for(int i=1;i<111;i++){
        if(cnt[i]>cnt[max])max=i;
    }
    cout<<max<<endl;
    for(int i=0;i<111;i++) {
        if(s[max][i])
            cout<<i<<" ";}
    return 0;
}