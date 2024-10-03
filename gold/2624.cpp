#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

ll dp[10000+1][100+1];

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll t,k;
		cin>>t>>k;
		vector<pair<ll,ll>> q;
		vector<ll> cnt(1000+1,0);
		for(ll i=0;i<10000+1;++i){
			for(ll j=0;j<100+1;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=0;i<k;++i){
			ll a,b;
			cin>>a>>b;
			q.push_back({a,b});
		}
		vector<ll> v;
		sort(q.begin(),q.end());
		for(ll i=0;i<k;++i){
			// i번째 인덱스의 개수
			cnt[i]=q[i].second;
			v.push_back(q[i].first);
		}
		// cnt[i]: i번째 인덱스가 몇 개 있는지
		for(ll i=1;i<=cnt[0];++i){
			dp[i*v[0]][0]=1;
		}
		for(ll i=1;i<=t;++i){
			for(ll j=1;j<k;++j){
				for(ll p=0;p<=cnt[j];++p){
					if(i>=p*v[j]){
						if(i==p*v[j]){
							++dp[i][j];
							break;
						}else{
							// i>p*v[j]
							dp[i][j]+=dp[i-p*v[j]][j-1];
						}
					}else{
						break;
					}
					
				}
			}
		}
		cout<<dp[t][k-1];
	}
	return 0;
}