#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

ll n;
vector<ll> tmp,v;
bool visited[8+1];
ll ans=-2023101800;
void dfs(){
	if(tmp.size()==n){
		ll sum=0;
		for(ll i=0;i<n-1;++i){
			sum+=abs(tmp[i]-tmp[i+1]);
		}
		ans=max(ans,sum);
		return;
	}
	
	for(ll i=0;i<n;++i){
		if(!visited[i]){
			visited[i]=1;
			tmp.push_back(v[i]);
			dfs();
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
	while(o--){
		cin>>n;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			v.push_back(a);
		}
		dfs();
		cout<<ans;
	}
	return 0;
}