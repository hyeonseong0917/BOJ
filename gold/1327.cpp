#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// N자리의 순열
		// K가 주어짐
		// 그 수부터 오른쪽으로 K개의 수를 뒤집는다.
		ll n,k;
		cin>>n>>k;
		string s="";
		string ans="";
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			s+='0'+a;
			ans+='0'+(i+1);
		}
		queue<pair<string,ll>> q;
		ll min_num=2023101800;
		map<string,ll> visited;
		q.push({s,0});
		visited[s]=1;
		while(!q.empty()){
			string cur_str=q.front().first;
			ll cur_num=q.front().second;
			q.pop();
			if(cur_str.compare(ans)==0){
				min_num=min(min_num,cur_num);
				continue;
			}
			for(ll i=0;i+k<=n;++i){
				string tmp_str=cur_str;
				string tmp=cur_str.substr(i,k);
				reverse(tmp.begin(),tmp.end());
				for(ll j=i;j<i+k;++j){
					tmp_str[j]=tmp[j-i];
				}
				if(!visited[tmp_str]){
					visited[tmp_str]=1;
					q.push({tmp_str,cur_num+1});
				}
			}
		}
		if(min_num==2023101800){
			cout<<-1;
		}else{
			cout<<min_num;
		}

	}
	return 0;
}