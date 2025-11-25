#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		string s;
		cin>>s;
		// k_cnt: k로 끝나는 개구리의 수
		// p_cnt: p로 끝나는 개구리의 수
		ll k_cnt=0, p_cnt=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]=='K'){
				if(!p_cnt){
					++k_cnt;
				}else{
					++k_cnt;
					--p_cnt;
				}
			}else{
				if(!k_cnt){
					++p_cnt;
				}else{
					++p_cnt;
					--k_cnt;
				}
			}
			// cout<<i<<" "<<k_cnt<<" "<<p_cnt<<endl;
		}
		cout<<p_cnt+k_cnt;
	} 
	return 0;
}