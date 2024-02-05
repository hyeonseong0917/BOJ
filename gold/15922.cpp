#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

vector<pair<ll,ll>> v;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll N;
	cin>>N;
	for(ll i=0;i<N;++i){
		ll x, y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	ll L=v[0].first, R=v[0].second;
	ll sum=0;
	bool flag=0;
	for(ll i=1;i<v.size();++i){
		ll x=v[i].first;
		ll y=v[i].second;
		if(R<x){
			sum+=(R-L);
			L=x;
			R=y;
			flag=0;
		}else{
			R=max(R,y);
		}
		// cout<<i<<" "<<sum<<endl;
	}
	sum+=(R-L);
	
	cout<<sum;

	return 0;
}