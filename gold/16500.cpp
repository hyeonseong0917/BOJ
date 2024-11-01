#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

string s;
ll n;
ll ss;
vector<string> v;
ll d[100+1];

ll dp(ll idx){
	if(d[idx]!=-1) return d[idx];
	if(idx==ss) return 1;
	d[idx]=0;
	for(ll i=0;i<n;++i){
		string cur_str=v[i];
		ll cs=cur_str.size();
		if(idx+cs>ss) continue;
		if(s.substr(idx,cs).compare(cur_str)==0){
			d[idx]=d[idx]|dp(idx+cs);
		}
	}
	return d[idx];
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>s;
		ss=s.size();
		cin>>n;
		for(ll i=0;i<n;++i){
			string t;
			cin>>t;
			v.push_back(t);
		}
		for(ll i=0;i<100+1;++i){
			d[i]=-1;
		}
		cout<<dp(0);
	}

	return 0;
}