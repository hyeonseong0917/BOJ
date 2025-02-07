#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1122
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		// 0 1 2 3 4 5
		// 2 2 3 4 9 10
		ll ans=2023101800;
		ll num=v[0];
		for(ll i=0;i<n;++i){
			// i번째를 기준으로
			// [i+1,n-1]은 해당구간 psum-개수*v[i]
			// [0,i-1]은 v[i]*개수 - psum[i-1]
			ll cur_sum=0;
			if(i+1<n){
				ll cur_len=n-1-(i+1)+1;
				cur_sum+=(psum[n-1]-psum[i+1]+v[i+1])-cur_len*v[i];
			}
			if(i-1>=0){
				ll cur_len=i;
				cur_sum+=v[i]*cur_len-psum[i-1];
			}
			// cout<<i<<" "<<cur_sum<<"\n";
			if(ans>cur_sum){
				ans=cur_sum;
				num=v[i];
			}
		}
		cout<<num<<"\n";
	}
	return 0;
}