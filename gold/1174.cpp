#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

#define ll long long

ll n;
vector<string> v;

string tmp;
void dfs(ll max_len){
	ll ts=tmp.size();
	if(ts==max_len){
		v.push_back(tmp);
		return;
	}
	if(ts==0){
		string tmp_copy=tmp;
		for(ll i=0;i<10;++i){
			tmp+=i+'0';
			dfs(max_len);
			tmp=tmp_copy;
		}
	}else{
		string tmp_copy=tmp;
		for(ll i=0;i<10;++i){
			ll last_num=tmp[ts-1]-'0';
			if(last_num<=i) continue;
			tmp+=i+'0';
			dfs(max_len);
			tmp=tmp_copy;
		}
	}
	
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;
		--n;
		for(ll i=0;i<10;++i){
			char c=i+'0';
			string s="";
			s+=c;
			v.push_back(s);
		}
		// n번째로 줄어드는 수?
		// 9876543210	
		for(ll i=2;i<=10;++i){
			// 길이가 i인 줄어드는 수를
			tmp="";
			dfs(i);
		}
		ll vs=v.size();
		if(vs<n+1){
			cout<<-1;
		}else{
			cout<<v[n];
		}

	}
	return 0;
}