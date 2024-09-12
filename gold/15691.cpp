#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,d,k,c;
		cin>>n>>d>>k>>c;
		ll m[3000+1];
		for(ll i=1;i<=3000;++i){
			m[i]=0;
		}
		queue<ll> q;
		queue<ll> tmp;
		queue<ll> p;
		ll ans=0;
		ll max_num=0;
		if(!m[c]){
			++ans;
		}
		++m[c];
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			if(tmp.empty() || tmp.size()<k){
				if(!m[a]){
					++ans;
				}
				++m[a];
				tmp.push(a);
				q.push(a);
			}else{
				q.push(a);
				if(!m[a]){
					++ans;
				}
				++m[a];
				--m[q.front()];
				if(!m[q.front()]){
					--ans;
				}
				q.pop();
			}
			max_num=max(max_num,ans);
		}
		while(!tmp.empty()){
			ll fst_num=tmp.front();
			ll sed_num=q.front();
			--m[sed_num];
			if(!m[sed_num]){
				--ans;
			}
			if(!m[fst_num]){
				++ans;
			}
			++m[fst_num];
			tmp.pop();
			q.pop();
			max_num=max(max_num,ans);
		}
		
		
		cout<<max_num;
	}
	return 0;
}