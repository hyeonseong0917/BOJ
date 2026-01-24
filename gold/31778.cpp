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
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		// 1<=i<j<k<=n
		// s[i]==s[j]==p
		// s[k]==c
		// ppc문자열의 최대 개수?
		// 할 수 있는 연산 -> swap연산
		// ccpcppcp
		// 가장 앞의 c를 가장 뒤의 p와 교환하면 되지않나?
		// 첫 개수 계산
		// 중간 p에 대해 idx이전의 p의 개수 * idx이후의 c의 개수
		ll L=0, R=n-1;
		while(k && L<=R){
			if(s[R]=='C'){
				--R;
				continue;
			}
			if(s[L]=='P'){
				++L;
				continue;
			}
			char c=s[R];
			s[R]=s[L];
			s[L]=c;
			--k;
		}
		// cout<<s<<endl;
		ll ans=0;
		vector<ll> left_pcnt(n,0), right_pcnt(n,0), left_ccnt(n,0),right_ccnt(n,0);
		if(s[0]=='P'){
			++left_pcnt[0];
		}else{
			++left_ccnt[0];
		}
		if(s[n-1]=='P'){
			++right_pcnt[n-1];
		}else{
			++right_ccnt[n-1];
		}
		for(ll i=1;i<n;++i){
			left_pcnt[i]=left_pcnt[i-1];
			left_ccnt[i]=left_ccnt[i-1];
			if(s[i]=='P'){
				++left_pcnt[i];
			}else{
				++left_ccnt[i];
			}
		}
		for(ll i=n-2;i>=0;--i){
			right_pcnt[i]=right_pcnt[i+1];
			right_ccnt[i]=right_ccnt[i+1];
			if(s[i]=='P'){
				++right_pcnt[i];
			}else{
				++right_ccnt[i];
			}
		}
		for(ll i=1;i<n-1;++i){
			if(s[i]=='P'){
				ll left_p=left_pcnt[i-1];
				ll right_c=right_ccnt[i+1];
				ans+=left_p*right_c;
			}
		}
		cout<<ans;
	}
	return 0;
}