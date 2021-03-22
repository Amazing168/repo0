#include<iostream>
using namespace std;
int k;
long long ans;
int main(){
	cin>>k;
	int day=0;
	for(int n=1;;n++){
			ans+=n*n;
			day+=n;
			if(day>=k){
				ans-=(day-k)*n;
				break;
			}
	}
	cout<<ans<<endl;
	return 0;
} 