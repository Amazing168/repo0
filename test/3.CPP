#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[555];
    int n;
    scanf("%d",&n);
    int cnt=0;
    while (n--){
        int x;
        cin>>x;
        if(x%2==1){ a[cnt]=x,cnt++;}
    }
    sort(a,a+cnt);
    cout<<a[0];
    for(int i=1;i<cnt;i++)printf(",%d",a[i]);

}