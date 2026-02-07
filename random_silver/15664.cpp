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

ll n,m;
vector<ll> v;
vector<ll> tmp;
bool visited[8+1];
void dfs(ll idx){
  if(tmp.size()==m){
    for(ll i=0;i<tmp.size();++i){
      cout<<v[tmp[i]];
      if(i!=tmp.size()-1){
        cout<<" ";
      }
    }cout<<"\n";
    return;
  }
  ll prev=-1;
  for(ll i=idx;i<n;++i){
    if(prev==v[i]) continue;
    if(!visited[i]){
      visited[i]=1;
      tmp.push_back(i);
      prev=v[i];
      dfs(i+1);
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
    cin>>n>>m;
    for(ll i=0;i<n;++i){
      ll a;
      cin>>a;
      v.push_back(a);
      visited[i]=0;
    }
    sort(v.begin(),v.end());
    dfs(0);
	} 
	return 0;
}