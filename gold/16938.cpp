#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll n,l,r,x;
vector<ll> v;
vector<ll> tmp;
bool visited[15+1];
ll ans=0;
void pick(ll idx){
	if(tmp.size()>=2){
		ll sum=0;
		for(ll i=0;i<tmp.size();++i){
			sum+=tmp[i];
		}
		if(sum>=l && sum<=r && tmp[tmp.size()-1]-tmp[0]>=x){
			++ans;
		}
	}
	if(tmp.size()==n){
		return;
	}
	for(ll i=idx;i<n;++i){
		if(!visited[i]){
			visited[i]=1;
			tmp.push_back(v[i]);
			pick(i+1);
			tmp.pop_back();
			visited[i]=0;
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		cin>>n>>l>>r>>x;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		pick(0);
		cout<<ans;
	}	
	return 0;
}