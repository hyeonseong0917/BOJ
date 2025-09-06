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
		ll ws,ss;
		cin>>ws>>ss;
		string w,s;
		cin>>w;
		cin>>s;
		vector<ll> check(52,0);
		for(ll i=0;i<ws;++i){
			if('A'<=w[i] && w[i]<='Z'){
				++check[26+(w[i]-'A')];
			}else{
				++check[(w[i]-'a')];
			}
		}
		ll L=0, R=ws-1;
		vector<ll> tmp(52,0);
		// 가장 처음에 set
		for(ll i=L;i<=R;++i){
			if('A'<=s[i] && s[i]<='Z'){
				++tmp[26+(s[i]-'A')];
			}else{
				++tmp[(s[i]-'a')];
			}
		}
		ll ans=0;
		while(R<ss){
			// 만족하는지 계산
			bool flag=0;
			for(ll i=0;i<52;++i){
				if(tmp[i]!=check[i]){
					flag=1;
					break;
				}
			}
			if(!flag){
				++ans;
			}
			if('A'<=s[L] && s[L]<='Z'){
				--tmp[26+(s[L]-'A')];
			}else{
				--tmp[(s[L]-'a')];
			}
			++L;
			if(R+1==ss){
				break;
			}
			++R;
			if('A'<=s[R] && s[R]<='Z'){
				++tmp[26+(s[R]-'A')];
			}else{
				++tmp[(s[R]-'a')];
			}
		}
		cout<<ans;
	}
	return 0;
}