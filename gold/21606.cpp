#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

ll n;
vector<ll> check;
vector<ll> v[200000+1];
bool visited[200000+1];
ll dp[200000+1];
ll cnt=0;
void dfs(ll cur_pos){
	for(ll i=0;i<v[cur_pos].size();++i){
		ll next_num=v[cur_pos][i];
		if(visited[next_num]) continue;
		if(!check[next_num]){
			visited[next_num]=1;
			cnt+=dp[next_num];
			dfs(next_num);
		}

	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1317
		// 실내 - 실외 - 실내 이 경로가 몇 개 있는지??
		// 실외는 0개여도 됨
		cin>>n;
		string s;
		cin>>s;
		for(ll i=0;i<n;++i){
			if(s[i]=='1'){
				check.push_back(1);
			}else{
				check.push_back(0);
			}
			visited[i]=0;
			dp[i]=0;
		}
		// dp[x]: 실외 x(check값이 1)에 연결된 실내의 개수
		ll ans=0;
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			v[a].push_back(b);
			v[b].push_back(a);
			if(check[a] && check[b]){
				ans+=2;
			}
			if(check[a] && !check[b]){
				++dp[b];
			}
			if(!check[a] && check[b]){
				++dp[a];
			}
		}
		// cout<<ans<<"\n";
		for(ll i=0;i<n;++i){
			if(!check[i] && !visited[i]){
				visited[i]=1;
				cnt=dp[i];
				dfs(i);
				ans+=(cnt*(cnt-1));
			}
		}
		cout<<ans;

	}
	return 0;
}