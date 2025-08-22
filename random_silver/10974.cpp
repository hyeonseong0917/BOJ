#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long

ll n;
vector<ll> v;
vector<ll> tmp;
vector<ll> visited;
void pick(ll idx){
	ll ts=tmp.size();
	if(ts==n){
		for(ll i=0;i<ts;++i){
			cout<<tmp[i]<<" ";
		}cout<<"\n";
		return;
	}
	for(ll i=1;i<=n;++i){
		if(visited[i]) continue;
		visited[i]=1;
		tmp.push_back(i);
		pick(idx+1);
		tmp.pop_back();
		visited[i]=0;
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;	
		for(ll i=0;i<=n;++i){
			visited.push_back(0);
		}
		pick(1);
	}
	return 0;
}