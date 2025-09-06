	#include <iostream>
	#include <algorithm>
	#include <vector>
	#include <cstring>
	#include <map>
	#include <queue>
	#include <cmath>
	using namespace std;

	#define ll long long

	char calc(char c){
		if(c=='R'){
			return 'G';
		}else if(c=='G'){
			return 'B';
		}
		return 'R';
	}

	int main() {
		ios_base :: sync_with_stdio(false); 
		cin.tie(NULL); 
		cout.tie(NULL);
		ll o=1;
		// cin>>o;
		while(o--){
			ll n;
			cin>>n;
			string s;
			cin>>s;
			bool flag=0;
			for(ll i=0;i<s.size();++i){
				if(s[i]!=s[0]){
					flag=1;
					break;
				}
			}
			if(!flag){
				cout<<0;
				break;
			}
			ll fst_cnt=0, sed_cnt=0, trd_cnt=0;
			// 1. R로 만들어보기		
			string fst_str=s;
			for(ll i=0;i<s.size()-2;++i){
				while(fst_str[i]!='R'){
					fst_str[i]=calc(fst_str[i]);
					fst_str[i+1]=calc(fst_str[i+1]);
					fst_str[i+2]=calc(fst_str[i+2]);
					++fst_cnt;
				}
			}
			// 2. G로 만들어보기
			string sed_str=s;
			for(ll i=0;i<s.size()-2;++i){
				while(sed_str[i]!='G'){
					sed_str[i]=calc(sed_str[i]);
					sed_str[i+1]=calc(sed_str[i+1]);
					sed_str[i+2]=calc(sed_str[i+2]);
					++sed_cnt;
				}
			}
			// 3. B로 만들어보기
			string trd_str=s;
			for(ll i=0;i<s.size()-2;++i){
				while(trd_str[i]!='B'){
					trd_str[i]=calc(trd_str[i]);
					trd_str[i+1]=calc(trd_str[i+1]);
					trd_str[i+2]=calc(trd_str[i+2]);
					++trd_cnt;
				}
			}
			vector<ll> tmp;
			bool fst_flag=0, sed_flag=0, trd_flag=0;
			for(ll i=0;i<n;++i){
				if(fst_str[i]!='R'){
					fst_flag=1;
				}
				if(sed_str[i]!='G'){
					sed_flag=1;
				}
				if(trd_str[i]!='B'){
					trd_flag=1;
				}
			}
			if(!fst_flag){
				tmp.push_back(fst_cnt);
			}
			if(!sed_flag){
				tmp.push_back(sed_cnt);
			}
			if(!trd_flag){
				tmp.push_back(trd_cnt);
			}
			if(tmp.empty()){
				cout<<-1;
			}else{
				sort(tmp.begin(),tmp.end());
				cout<<tmp[0];
			}

		}
		return 0;
	}