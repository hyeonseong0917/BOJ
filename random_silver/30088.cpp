#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;++i){
      ll a;
      cin>>a;
      ll b=0;
      while(a--){
        ll c;
        cin>>c;
        b+=c;
      }
      v.push_back(b);
    }
    sort(v.begin(),v.end());
    vector<ll> psum(n,0);
    psum[0]=v[0];
    ll ans=0;
    for(ll i=1;i<v.size();++i){
      psum[i]=psum[i-1]+v[i];
    }
    for(ll i=0;i<n;++i){
      ans+=psum[i];
    }
    cout<<ans<<"\n";
	} 
	return 0;
}