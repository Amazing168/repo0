# include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
    int n;
    cin>>n;
    unordered_map<int ,int>primes;
    while(n--){
        int x;
        cin>>x;
        for(int i=2;i<=x/i;i++){
            while(x%i==0){
                x/=i;
                primes[i]++;
            }
        }
        if(x>1) primes[x]++;
    }
    long long res=1;
    for(auto t:primes){
        int p=t.first,a=t.second;
        long long x=1;
        while(a--){x=(x*p+1)%mod;}
        res=res*x%mod; 
    }
    cout<<res<<endl;
    return 0;
}