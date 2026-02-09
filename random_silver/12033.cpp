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
  cin>>o;
  ll idx=1;
	while(o--){
    ll n;
    cin>>n;
    ll ans=0;
    vector<ll> v(n*2,0);
    map<ll,ll> check;
    for(ll i=0;i<n*2;++i){
      cin>>v[i];
      ++check[v[i]];
    }
    vector<ll> tmp;
    for(ll i=0;i<n*2;++i){
      if(check[v[i]]==0) continue;
      // v[i]가 4분의 3된 가격인지?
      if(v[i]%3==0){
        // v[i]는 4분의3 x
        if(!check[(v[i]/3)*4]) continue;
        --check[(v[i]/3)*4];
        --check[v[i]];
        tmp.push_back(v[i]);
      }
    }
    cout<<"Case #"<<idx<<": ";
    for(ll i=0;i<n;++i){
      cout<<tmp[i];
      if(i!=n-1) cout<<" ";
    }
    cout<<"\n";
    ++idx;
	} 
	return 0;
}