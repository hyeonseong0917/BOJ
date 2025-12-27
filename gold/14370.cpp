#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		v.push_back("zero");
		v.push_back("one");
		v.push_back("two");
		v.push_back("three");
		v.push_back("four");
		v.push_back("five");
		v.push_back("six");
		v.push_back("seven");
		v.push_back("eight");
		v.push_back("nine");
		ll n;
		cin>>n;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			vector<ll> check(26,0);
			for(ll j=0;j<s.size();++j){
				++check[s[j]-'A'];
			}
			vector<ll> cnt(10,0);
			// 1. eight의 개수
			if(check['G'-'A']){
				ll cur_cnt=check['G'-'A'];
				cnt[8]+=cur_cnt;
				check['E'-'A']-=cur_cnt;
				check['I'-'A']-=cur_cnt;
				check['G'-'A']-=cur_cnt;
				check['H'-'A']-=cur_cnt;
				check['T'-'A']-=cur_cnt;
			}
			// 2. six의 개수
			if(check['X'-'A']){
				ll cur_cnt=check['X'-'A'];
				cnt[6]+=cur_cnt;
				check['S'-'A']-=cur_cnt;
				check['I'-'A']-=cur_cnt;
				check['X'-'A']-=cur_cnt;
			}
			// 3. zero의 개수
			if(check['Z'-'A']){
				ll cur_cnt=check['Z'-'A'];
				cnt[0]+=cur_cnt;
				check['Z'-'A']-=cur_cnt;
				check['E'-'A']-=cur_cnt;
				check['R'-'A']-=cur_cnt;
				check['O'-'A']-=cur_cnt;
			}
			// 4. two의 개수
			if(check['W'-'A']){
				ll cur_cnt=check['W'-'A'];
				cnt[2]+=cur_cnt;
				check['T'-'A']-=cur_cnt;
				check['W'-'A']-=cur_cnt;
				check['O'-'A']-=cur_cnt;
			}
			// 5. three의 개수
			if(check['T'-'A']){
				ll cur_cnt=check['T'-'A'];
				cnt[3]+=cur_cnt;
				check['T'-'A']-=cur_cnt;
				check['H'-'A']-=cur_cnt;
				check['R'-'A']-=cur_cnt;
				check['E'-'A']-=cur_cnt;
				check['E'-'A']-=cur_cnt;
			}
			// 6. seven의 개수
			if(check['S'-'A']){
				ll cur_cnt=check['S'-'A'];
				cnt[7]+=cur_cnt;
				check['S'-'A']-=cur_cnt;
				check['E'-'A']-=cur_cnt;
				check['V'-'A']-=cur_cnt;
				check['E'-'A']-=cur_cnt;
				check['N'-'A']-=cur_cnt;
			}
			// 7. five의 개수
			if(check['V'-'A']){
				ll cur_cnt=check['V'-'A'];
				cnt[5]+=cur_cnt;
				check['F'-'A']-=cur_cnt;
				check['I'-'A']-=cur_cnt;
				check['V'-'A']-=cur_cnt;
				check['E'-'A']-=cur_cnt;
			}
			// 8. four의 개수
			if(check['F'-'A']){
				ll cur_cnt=check['F'-'A'];
				cnt[4]+=cur_cnt;
				check['F'-'A']-=cur_cnt;
				check['O'-'A']-=cur_cnt;
				check['U'-'A']-=cur_cnt;
				check['R'-'A']-=cur_cnt;
			}
			// 9. nine의 개수
			if(check['I'-'A']){
				ll cur_cnt=check['I'-'A'];
				cnt[9]+=cur_cnt;
				check['N'-'A']-=cur_cnt;
				check['I'-'A']-=cur_cnt;
				check['N'-'A']-=cur_cnt;
				check['E'-'A']-=cur_cnt;
			}
			// 9. one의 개수
			if(check['O'-'A']){
				ll cur_cnt=check['O'-'A'];
				cnt[1]+=cur_cnt;
				check['O'-'A']-=cur_cnt;
				check['N'-'A']-=cur_cnt;
				check['E'-'A']-=cur_cnt;
			}
			string ans="";
			for(ll i=0;i<10;++i){
				ll cur_cnt=cnt[i];
				if(!cur_cnt) continue;
				for(ll j=0;j<cur_cnt;++j){
					ans+='0'+i;
				}
			}
			cout<<"Case #"<<i+1<<": "<<ans<<"\n";
		}
	}
	return 0;
}