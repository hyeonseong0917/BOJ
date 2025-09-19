#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long

string s;
string v[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
vector<ll> check(26,0);
vector<string> tmp;
ll n;
vector<string> ans;
void pick(){
	if(!ans.empty()){
		return;
	}
	if(!tmp.empty()){
		ll sum=0;
		ll ts=tmp.size();
		for(ll i=0;i<ts;++i){
			ll cs=tmp[i].size();
			sum+=cs;
		}
		if(sum>n){
			return;
		}
		if(sum==n){
			// cout<<"he"<<endl;
			// cout<<ts<<endl;
			vector<ll> tmp_check(26,0);
			// for(ll i=0;i<ts;++i){
			// 	cout<<tmp[i]<<" ";
			// }cout<<endl;
			for(ll i=0;i<ts;++i){
				ll cs=tmp[i].size();
				for(ll j=0;j<cs;++j){
					++tmp_check[tmp[i][j]-'A'];
				}
			}
			bool flag=0;
			for(ll i=0;i<26;++i){
				if(tmp_check[i]!=check[i]){
					flag=1;
					break;
				}
			}
			if(!flag){
				ans=tmp;
			}
			return;
		}
	}
	for(ll i=0;i<10;++i){
		tmp.push_back(v[i]);
		pick();
		tmp.pop_back();
	}
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	ll cnt=1;
	while(o--){
		tmp.clear();
		ans.clear();
		check=vector<ll>(26,0);
		cin>>s;
		n=s.size();
		for(ll i=0;i<n;++i){
			++check[s[i]-'A'];
		}
		pick();
		string tel_num="";
		for(ll i=0;i<ans.size();++i){
			for(ll j=0;j<10;++j){
				if(v[j]==ans[i]){
					tel_num+=(j+'0');
				}
			}
		}
		cout<<"Case #"<<cnt<<": "<<tel_num<<"\n";
		++cnt;
	}
	return 0;
}