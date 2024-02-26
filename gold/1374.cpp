#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll N;
priority_queue<ll> pq;
vector<pair<ll,ll>> v;
int main() {
	// your code goes here
	cin>>N;
	for(ll i=0;i<N;++i){
		ll a,b,c;
		cin>>a>>b>>c;
		v.push_back({b,c});
	}
	sort(v.begin(),v.end());
	int cnt=0;
	for(ll i=0;i<N;++i){
		if(!pq.empty() && v[i].first>=pq.top()*-1){
			pq.pop();
		}
		pq.push(v[i].second*-1);
	}
	cout<<pq.size();
	return 0;
}