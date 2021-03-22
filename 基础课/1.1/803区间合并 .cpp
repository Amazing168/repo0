# include<bits/stdc++.h>
using namespace std;

const int N=100010;
pair <int,int > a[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    int cnt=n;
    for(int i=1;i<n;i++){
        if(a[i].second>=a[i+1].first) cnt--;
        a[i+1].first=a[i].first;
        a[i+1].second=max(a[i].second,a[i+1].second);
    }
    cout<<cnt;
    return 0;
}