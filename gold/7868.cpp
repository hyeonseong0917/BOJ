#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
ll dp[61][61][61];

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		vector<ll> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(),v.end());
		a=v[0];
		b=v[1];
		c=v[2];
		priority_queue<ll> pq;
		pq.push(-1);
		ll cnt=-1;
		ll ans=0;
		map<ll,ll> check;
		while(!pq.empty()){
			ll cur_num=pq.top()*-1;
			pq.pop();
			++cnt;
			if(cnt==d){
				ans=cur_num;
				break;
			}
			if(!check[cur_num*a]){
				++check[cur_num*a];
				pq.push(cur_num*a*-1);
			}
			if(!check[cur_num*b]){
				++check[cur_num*b];
				pq.push(cur_num*b*-1);	
			}
			if(!check[cur_num*c]){
				++check[cur_num*c];
				pq.push(cur_num*c*-1);	
			}
		}
		cout<<ans;

	}
	return 0;
}
