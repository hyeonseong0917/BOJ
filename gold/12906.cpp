#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
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
		vector<string> v;
		for(ll i=0;i<3;++i){
			ll a;
			cin>>a;
			if(a){
				string s;
				cin>>s;
				v.push_back(s);
			}else{
				v.push_back("");
			}
			
		}
		queue<pair<pair<string,string>,pair<string,ll>>> q;
		// 0번째 str, 1번째 str, 2번째 str, 현재 횟수
		q.push({{v[0],v[1]},{v[2],0}});
		ll ans=2023101800;
		map<pair<pair<string,string>,string>,ll> check;
		while(!q.empty()){
			string fst_str=q.front().first.first;
			string sed_str=q.front().first.second;
			string trd_str=q.front().second.first;
			ll cur_cnt=q.front().second.second;
			q.pop();
			vector<string> tmp;
			tmp.push_back(fst_str);
			tmp.push_back(sed_str);
			tmp.push_back(trd_str);
			bool flag=0;
			for(ll i=0;i<3;++i){
				char c='A'+i;
				for(ll j=0;j<tmp[i].size();++j){
					if(tmp[i][j]!=c){
						flag=1;
						break;
					}
				}
			}
			if(!flag){
				ans=min(ans,cur_cnt);
				continue;
			}
			// tmp의 i번째 문자열 끝에서 j번째 문자열 끝으로 이동
			for(ll i=0;i<3;++i){
				for(ll j=0;j<3;++j){
					if(i==j) continue;
					if(tmp[i]=="") continue;
					// i,j에서 
					ll ts=tmp[i].size();
					char c=tmp[i][ts-1];
					pair<pair<string,string>,string> p;
					string i_tmp=tmp[i];
					string j_tmp=tmp[j];

					tmp[i]=tmp[i].substr(0,ts-1);
					tmp[j]+=c;
					p.first.first=tmp[0];
					p.first.second=tmp[1];
					p.second=tmp[2];
					if(!check[p]){
						++check[p];
						q.push({{tmp[0],tmp[1]},{tmp[2],cur_cnt+1}});
					}
					tmp[i]=i_tmp;
					tmp[j]=j_tmp;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}