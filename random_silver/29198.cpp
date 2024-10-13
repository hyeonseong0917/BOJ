#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m,k;
		cin>>n>>m>>k;
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			sort(s.begin(),s.end());
			v.push_back(s);
		}
		// 각 문자열은 길이 m, n개의 문자열들 중 k개를 선택해야함
		// aacx aaab
		vector<string> ans;
		vector<bool> visited(n,0);
		for(ll i=0;i<k;++i){
			// k개를 선택해서 ans에 넣을거임
			ll min_num=2023101800;
			bool flag=0;
			ll last_idx=-1;
			for(ll j=0;j<m;++j){
				// j번째 인덱스의 가장 작은 문자열은?
				for(ll p=0;p<n;++p){
					if(visited[p]) continue;
					ll c=v[p][j]-'A';
					min_num=min(min_num,c);
				}

				// 가장 작은 문자열이 여러 개인지?
				ll cnt=0;
				ll idx=-1;
				for(ll p=0;p<n;++p){
					if(visited[p]) continue;
					if(v[p][j]-'A'==min_num){
						idx=p;
						last_idx=p;
						++cnt;
					}
				}
				cout<<i<<" "<<j<<" "<<min_num<<endl;
				if(cnt==1){
					// cout<<j<<endl;
					visited[idx]=1;
					flag=1;
					ans.push_back(v[idx]);
					break;
				}
			}
			if(!flag){
				visited[last_idx]=1;
				ans.push_back(v[last_idx]);
			}
		}
		string ans_str="";
		for(ll i=0;i<k;++i){
			ans_str+=ans[i];
		}
		sort(ans_str.begin(),ans_str.end());
		cout<<ans_str;
	}
	return 0;
}