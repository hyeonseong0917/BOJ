#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

vector<string> ans;
vector<pair<ll,ll>> v;
ll vs;
vector<ll> tmp_idx;
ll n;
string s;
map<string,ll> check;
void pick(ll max_pick, ll idx){
	if(tmp_idx.size()==max_pick){
		map<ll,ll> m;
		for(ll i=0;i<max_pick;++i){
			ll fst_idx=v[tmp_idx[i]].first;
			ll sed_idx=v[tmp_idx[i]].second;
			m[fst_idx]=1;
			m[sed_idx]=1;
		}
		string tmp="";
		for(ll i=0;i<n;++i){
			if(m[i]) continue;
			tmp+=s[i];
		}
		// cout<<tmp<<endl;
		if(!check[tmp]){
			check[tmp]=1;
			// tmp가 올바른 괄호 쌍인지?
			stack<ll> st;
			bool flag=0;
			for(ll i=0;i<tmp.size();++i){
				if(tmp[i]=='('){
					st.push(i);
				}else if(tmp[i]==')'){
					if(st.empty()){
						flag=1;
						break;
					}else{
						st.pop();
					}
				}
			}
			if(!flag && st.empty()){
				ans.push_back(tmp);
			}
		}
		return;
	}
	if(idx==vs){
		return;
	}
	tmp_idx.push_back(idx);
	pick(max_pick, idx+1);
	tmp_idx.pop_back();
	pick(max_pick, idx+1);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		
		cin>>s;
		n=s.size();
		stack<ll> st;
		for(ll i=0;i<n;++i){
			if(s[i]=='('){
				st.push(i);
			}else if(s[i]==')'){
				v.push_back({st.top(),i});
				st.pop();
			}
		}
		
		vs=v.size();
		for(ll i=1;i<=vs;++i){
			tmp_idx.clear();
			pick(i,0);
		}
		sort(ans.begin(),ans.end());
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<"\n";
		}

	}
	return 0;
}