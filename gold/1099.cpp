#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 단어가 n개 있음
		// 단어를 공백 없이 붙여쓴것
		// 각 단어는 0번 또는 그 이상
		// 단어에 쓰인 문자의 순서를 바꿔도 됨
		// 원래 단어의 위치와 다른 위치에 있는 문자의 개수

		// abc
		// acb
		// cba
		// bca
		// 문장을 해석하는 비용의 최솟값
		string s;
		cin>>s;
		ll n;
		cin>>n;
		
		vector<string> v;
		for(ll i=0;i<n;++i){
			string k;
			cin>>k;
			v.push_back(k);
		}
		// n<=50
		// i번째 인덱스 까지 봤을때 최솟값?
		// dp[i]-> i번째 원소로부터 역으로 길이 j 갖는 단어 있는지?
		// 있다면 단어 조합 다 같은지?
		// 다 같다면 dp[i]=min(dp[i],dp[i-단어길이]+단어조합이랑 다른 개수)

		// dp[0]=MAX
		// dp[1]=MAX
		// dp[2]=i-단어길이 -> -1이라면 0, 2
		// dp[3]=MAX
		// dp[4]=MAX
		// dp[5]=MAX
		// dp[6]=MAX
		// dp[7]-> i=7, j=5
		ll ss=s.size();
		vector<ll> dp(ss,2023101800);
		for(ll i=0;i<ss;++i){
			for(ll j=1;i-j+1>=0;++j){
				// if i==7, j==5
				string cur_str=s.substr(i-j+1,j);
				vector<ll> check(26,0);
				for(ll k=0;k<j;++k){
					++check[cur_str[k]-'a'];
				}
				for(ll k=0;k<n;++k){
					// cout<<i<<" "<<j<<" "<<k<<"\n";
					string tmp_str=v[k];
					ll ts=tmp_str.size();
					if(ts!=j) continue;
					vector<ll> tmp(26,0);
					for(ll p=0;p<ts;++p){
						++tmp[tmp_str[p]-'a'];
					}
					bool flag=0;
					for(ll p=0;p<26;++p){
						if(tmp[p]!=check[p]){
							flag=1;
							break;
						}
					}
					if(!flag){
						ll cnt=0;
						for(ll p=0;p<j;++p){
							if(cur_str[p]!=tmp_str[p]){
								++cnt;
							}
						}
						ll cur_dp=(i<j)?0:dp[i-j];
						dp[i]=min(dp[i],cur_dp+cnt);
						// cout<<dp[i-1-j]<<endl;
						// cout<<i<<" "<<j<<" "<<cnt<<" "<<dp[i]<<"\n";
					}
				}
			}
		}
		if(dp[ss-1]>=2023101800){
			cout<<-1;
		}else{
			cout<<dp[ss-1];
		}
	}
	return 0;
}