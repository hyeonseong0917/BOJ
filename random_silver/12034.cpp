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
        ll c=1;
        ll t;
        cin>>t;
        while(c<=t){
          ll n;
          cin>>n;
          vector<ll> v(n*2,0);
          map<ll,ll> check;
          for(ll i=0;i<n*2;++i){
            cin>>v[i];
            ++check[v[i]];
          }
          vector<ll> tmp;
          for(ll i=0;i<n*2;++i){
            if(!check[v[i]]) continue;
            if(v[i]%3==0){
              tmp.push_back(v[i]);
              --check[v[i]];
              --check[(v[i]/3)*4];
            }
          }

          cout<<"Case #"<<c<<": ";
          for(ll i=0;i<tmp.size();++i){
              cout<<tmp[i];
              if(i!=tmp.size()-1){
                cout<<" ";
              }
          }
          cout<<"\n";
          ++c;
        }
	} 
	return 0;
}