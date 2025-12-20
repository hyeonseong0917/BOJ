#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

string s;
bool comp(string a, string b){
	// a가 b보다 작으면 1
	// a<b
	// 같아도 0. b가 a를 이기지 못한 경우도 포함
	ll as=a.size();
	ll bs=b.size();
	if(as<bs){
		return 1;
	}
	if(as>bs){
		return 0;
	}
	bool fst_flag=0, sed_flag=0;
	for(ll i=0;i<as;++i){
		if(a[i]<b[i]){
			sed_flag=1;
			break;
		}
		if(a[i]>b[i]){
			fst_flag=1;
			break;
		}
	}
	if(fst_flag){
		return 0;
	}
	if(sed_flag){
		return 1;
	}
	return 0;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>s;
		// N보다 큰 수 중에서 팰린드롬수
		// 12345
		// 12421
		// comp(a,b)==1 -> a보다 b가 더 큼
		ll n=s.size();
		if(n==1){
			if(s=="9"){
				cout<<"11";
			}else{
				ll c=(s[0]-'0')+1;
				cout<<c;
			}
			break;
		}
		bool flag=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]!='9'){
				flag=1;
			}
		}
		if(!flag){
			// 9999
			cout<<1;
			for(ll i=0;i<s.size()-1;++i){
				cout<<0;
			}cout<<1;
			break;
		}
		string ans="";
		for(ll i=0;i<51;++i){
			ans+='9';
		}
		
		// 1. i번째 수를 그대로 두고 [i+1,mid]까지 0으로 채운후 뒤집기
		// 2. i번째 수를 +1하고
		if(n%2==0){
			for(ll i=0;i<=n/2-1;++i){
				string fst_str=s.substr(0,i+1);
				string sed_str=fst_str;
				reverse(sed_str.begin(),sed_str.end());
				ll fs=fst_str.size();
				ll zero_cnt=n-fs*2;
				string zero_str="";
				for(ll j=0;j<zero_cnt;++j){
					zero_str+='0';
				}
				string tmp=fst_str+zero_str+sed_str;
				if(comp(s,tmp)){
					// s보다 tmp가 더 큼
					if(comp(tmp,ans)){
						ans=tmp;
					}
				}
				// 1을 더했을 때
				fst_str=s.substr(0,i+1);
				ll c=fst_str[i]-'0';
				++c;
				if(c==10) continue;
				fst_str[i]=(c+'0');
				sed_str=fst_str;
				reverse(sed_str.begin(),sed_str.end());
				fs=fst_str.size();
				zero_cnt=n-fs*2;
				zero_str="";
				for(ll j=0;j<zero_cnt;++j){
					zero_str+='0';
				}
				tmp=fst_str+zero_str+sed_str;
				if(comp(s,tmp)){
					if(comp(tmp,ans)){
						ans=tmp;
					}
				}
			}
		}else{
			for(ll i=0;i<=n/2;++i){
				string fst_str=s.substr(0,i+1);
				string sed_str=fst_str;
				reverse(sed_str.begin(),sed_str.end());
				ll fs=fst_str.size();
				ll zero_cnt=n-fs*2;
				string zero_str="";
				for(ll j=0;j<zero_cnt;++j){
					zero_str+='0';
				}
				// 00000
				for(ll j=0;j<=9;++j){
					char c='0'+j;
					string tmp_zero=zero_str;
					tmp_zero[zero_cnt/2]=c;
					string tmp=fst_str+tmp_zero+sed_str;
					if(comp(s,tmp)){
						if(comp(tmp,ans)){
							ans=tmp;
						}
					}
				}
				
				// 1을 더했을 때
				fst_str=s.substr(0,i+1);
				ll c=fst_str[i]-'0';
				++c;
				if(c==10) continue;
				fst_str[i]=(c+'0');
				sed_str=fst_str;
				reverse(sed_str.begin(),sed_str.end());
				fs=fst_str.size();
				zero_cnt=n-fs*2;
				zero_str="";
				for(ll j=0;j<zero_cnt;++j){
					zero_str+='0';
				}
				string tmp=fst_str+zero_str+sed_str;
				if(comp(s,tmp)){
					if(comp(tmp,ans)){
						ans=tmp;
					}
				}
			}
		}
		cout<<ans;
		
	}
	return 0;
}