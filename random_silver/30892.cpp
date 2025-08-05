#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>t;
	while(o--){
		// 1234
		ll n,k,t;
		cin>>n>>k>>t;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		// n k t
		// 5 3 10

		// 1 5 10 15 24
		// 매 라운드마다 t보다 작은 최대의 값을 먹는게 이득
		priority_queue<ll> pq;
		for(ll i=0;i<n && k;++i){
			if(v[i]>=t){
				while(!pq.empty() && k){
					t+=pq.top();
					pq.pop();
					--k;
					if(t>v[i]){
						pq.push(v[i]);
						break;
					}
				}
			}else{
				pq.push(v[i]);
			}
		}
		while(k && !pq.empty()){
			k--;
			t+=pq.top();
			pq.pop();
		}
		cout<<t;
	} 
	return 0;
}