#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		priority_queue<ll> pq;
		ll sum=0;
		ll cnt=0;
		ll idx=0;
		while(idx<n){
			pq.push(v[idx]);
			sum+=v[idx];
			if(sum>=m){
				ll c=pq.top();
				pq.pop();
				sum-=c*2;
				++cnt;
			}
			++idx;
			// cout<<sum<<" "<<idx<<" "<<cnt<<endl;
		}
		cout<<cnt;
	}
	return 0;
}