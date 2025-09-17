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
		string s;
		cin>>s;
		ll fst_cnt=0, sed_cnt=0, trd_cnt=0;
		char c[3]={'K','S','A'};
		ll n=s.size();
		string fst_str=s;
		string sed_str="K"+s;
		string trd_str="KS"+s;
		ll fst_idx=0, sed_idx=0, trd_idx=0;
		for(ll i=0;i<n;++i){
			if(fst_str[i]==c[fst_idx%3]){
				++fst_idx;
			}else{
				++fst_cnt;
			}
		}
		ll fs=fst_str.size();
		ll ss=sed_str.size();
		ll ts=trd_str.size();
		for(ll i=0;i<ss;++i){
			if(sed_str[i]==c[sed_idx%3]){
				++sed_idx;
			}else{
				++sed_cnt;
			}
		}
		for(ll i=0;i<ts;++i){
			if(trd_str[i]==c[trd_idx%3]){
				++trd_idx;
			}else{
				++trd_cnt;
			}
		}
		fst_cnt+=abs(fst_idx-n);
		// fst_cnt*=2;
		sed_cnt+=abs(sed_idx-n);
		// sed_cnt*=2;
		trd_cnt+=abs(trd_idx-n);
		// trd_cnt*=2;
		sed_cnt+=1;
		trd_cnt+=2;
		ll ans=min(fst_cnt,min(sed_cnt,trd_cnt));
		cout<<ans;
	}
	return 0;
}