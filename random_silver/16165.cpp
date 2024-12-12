#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;	
	while(o--){
		ll n,m;
		cin>>n>>m;
		map<string,vector<string>> idol; // idol[s]=t: 팀 s의 구성원들은 t
		map<string,string> member; //member[t]=s: 멤버 t의 팀은 s
		for(ll i=0;i<n;++i){
			string team_str;
			cin>>team_str;
			ll k;
			cin>>k;
			for(ll j=0;j<k;++j){
				string t;
				cin>>t;
				member[t]=team_str;
				idol[team_str].push_back(t);
			}
			sort(idol[team_str].begin(),idol[team_str].end());
		}
		for(ll i=0;i<m;++i){
			string t;
			ll idx;
			cin>>t;
			cin>>idx;
			if(idx==0){
				for(ll j=0;j<idol[t].size();++j){
					cout<<idol[t][j]<<"\n";
				}
			}else{
				cout<<member[t]<<"\n";
			}

		}

	}
	return 0;
}