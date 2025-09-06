#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
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
		ll n;
		cin>>n;
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			v.push_back(s);
		}
		map<string,ll> prefix_check, check, same_check;
		for(ll i=0;i<n;++i){
			string s=v[i];
			string ans="";
			// s에 대해서
			bool flag=0;
			for(ll j=1;j<=s.size();++j){
				string tmp=s.substr(0,j);
				// tmp는 현재 접두사
				if(prefix_check[tmp]) continue;
				if(check[tmp]) continue;
				flag=1;
				ans=tmp;
				++check[tmp];
				break;
			}
			++same_check[s];
			if(!flag){
				// 선택할 수 있는 접두사가 없음
				ll x=same_check[s];
				ans=s;
				if(x>=2){
					string sx=to_string(x);
					ans+=sx;
				}
			}
			// 다 완료한 후에는
			for(ll j=1;j<=s.size();++j){
				string tmp=s.substr(0,j);
				++prefix_check[tmp];
			}
			// 현재 문자열 그대로 넣기
			
			cout<<ans<<"\n";
		}
	}
	return 0;
}