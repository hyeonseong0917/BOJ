#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> ans(5,0);
		ll q=n/60;
		ans[0]+=q;
		n-=60*q;
		if(n>35){
			++ans[0];
			n-=60;
		}
		if(n<0){
			n*=-1;
			q=n/10;
			ans[2]+=q;
			n-=q*10;
			if(n>5){
				++ans[2];
				n=10-n;
				ans[3]+=n;
			}else{
				ans[4]+=n;
			}
		}else{
			q=n/10;
			ans[1]+=q;
			n-=q*10;
			if(n>5){
				++ans[1];
				n=10-n;
				ans[4]+=n;
			}else{
				ans[3]+=n;
			}
		}
		for(ll i=0;i<5;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}

	return 0;
}