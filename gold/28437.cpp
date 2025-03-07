#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// 막대의 길이 a1,a2,a3..an
		// 0번이상 막대를 늘림
		// 2이상 정수 k를 설정해서 늘리면 kx됨
		// 1438
		// Q개의 길이 각각에 대해 L[i]를 마드는 방법의 수
		// 처음 선택하 막대 다름? 정수 k의 수열 다름?
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> check(100000+1);
		for(ll i=0;i<n;++i){
			                                                                  cin>>v[i];
			++check[v[i]];
		}
		sort(v.begin(),v.end());
		ll q;
		cin>>q;
		vector<ll> l(q,0);
		for(ll i=0;i<q;++i){
			cin>>l[i];
		}
		for(ll i=1;i<=100000;++i){
			if(!check[i]) continue;
			for(ll j=i+i;j<=100000;j+=i){
				check[j]+=check[i];
			}
		}
		// cout<<dp[4]<<endl;
		for(ll i=0;i<q;++i){
			ll cur_len=l[i];
			cout<<check[cur_len]<<" ";
		}
	}
	return 0;
}