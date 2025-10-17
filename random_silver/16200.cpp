#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		int n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.rbegin(),v.rend());
		ll ans=2023101800;
		ll L=1, R=n;
		while(L<=R){
			ll mid=(L+R)/2;
			// mid개로 가능한지?
			priority_queue<ll> pq;
			// pq는 최솟값(현재 가장 적은 사람 수를 가지고 있는 팀의 현재 사람 수)
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(i==0){
					pq.push(-1);
				}else{
					ll pt=pq.top()*-1;
					if(pt+1>v[i]){
						pq.push(-1);
					}else{
						pq.pop();
						pq.push((pt+1)*-1);
					}
				}
			}
			ll ps=pq.size();
			if(ps>mid){
				L=mid+1;
			}else{
				ans=min(ans,mid);
				R=mid-1;
			}
		}
		cout<<ans;
	}
	return 0;
}