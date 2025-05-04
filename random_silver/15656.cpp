#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

ll n,m;
vector<ll> tmp;
vector<ll> v;
bool visited[10+1];
void pick(){
    if(tmp.size()==m){
        for(ll i=0;i<tmp.size();++i){
            cout<<tmp[i]<<" ";
        }cout<<"\n";
        return;
    }
    for(ll i=0;i<n;++i){
        tmp.push_back(v[i]);
        pick();
        tmp.pop_back();
    }
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		
        cin>>n>>m;
        
        for(ll i=0;i<n;++i){
            ll a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        pick();
        return 0;
	} 
	return 0;
}