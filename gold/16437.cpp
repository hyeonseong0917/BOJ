#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define ll long long



int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n; 
		vector<ll> v[n+1];
		vector<ll> parent(n+1,0);
		vector<ll> s(n+1,0);
		vector<ll> w(n+1,0);
		for(ll i=0;i<n-1;++i){
			ll cur_num=i+2;
			char c;
			cin>>c;
			ll cnt;
			cin>>cnt;
			ll next_num;
			cin>>next_num;
			v[next_num].push_back(cur_num);
			parent[cur_num]=next_num;
			if(c=='S'){
				s[cur_num]=cnt;
			}else{
				w[cur_num]=cnt;
			}
		}
		queue<ll> q;
		ll root=1;
		for(ll i=2;i<=n;++i){
			if(v[i].empty()){
				// cout<<i<<endl;
				q.push(i);
			}
		}
		vector<ll> check(n+1,0);
		while(!q.empty()){
			ll cur_num=q.front();
			q.pop();
			if(cur_num==1){
				continue;
			}
			ll next_num=parent[cur_num];
			s[next_num]+=s[cur_num];
			bool flag=0;
			if(s[cur_num]) flag=1;
			s[cur_num]=0;
			if(flag){
				if(s[next_num]>=w[next_num]){
					s[next_num]-=w[next_num];
					w[next_num]=0;
				}else{
					w[next_num]-=s[next_num];
					s[next_num]=0;
				}
			}
			++check[next_num];
			if(check[next_num]==v[next_num].size()){
				q.push(next_num);
			}
			
		}
		cout<<s[1];

	}
	return 0;
}
