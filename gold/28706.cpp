#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	while(o--){
		// 초기에 K=1
		// 1<=v<=9인 v에 대해 
		// 1. K를 K+v로 바꾸거나
		// 2. K를 K*v로 바꿈
		// K가 7의 배수가 되도록 할 수 있는지?
		ll n;
		cin>>n;
		vector<pair<string,string>> v;
		for(ll i=0;i<n;++i){
			string k;
			pair<string,string> a;
			string p;
			cin>>k;
			cin>>p;

			string kk;
			string pp;
			cin>>kk;
			cin>>pp;
			v.push_back({k+p,kk+pp});
		}
		ll K=1;
		ll dp[n][7];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<7;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=0;i<n;++i){
			string fst_str=v[i].first;
			string sed_str=v[i].second;
			if(i==0){
				char fst_oper=fst_str[0];
				char fst_num=fst_str[1];
				if(fst_oper=='+'){
					ll c=fst_num-'0';
					ll cur_num=(K+c)%7;
					dp[0][cur_num]=1;
				}else{
					ll c=fst_num-'0';
					ll cur_num=(K*c)%7;
					dp[0][cur_num]=1;
				}

				char sed_oper=sed_str[0];
				char sed_num=sed_str[1];
				if(sed_oper=='+'){
					ll c=sed_num-'0';
					ll cur_num=(K+c)%7;
					dp[0][cur_num]=1;
				}else{
					ll c=sed_num-'0';
					ll cur_num=(K*c)%7;
					dp[0][cur_num]=1;
				}
			}else{
				for(ll j=0;j<7;++j){
					if(dp[i-1][j]){
						char fst_oper=fst_str[0];
						char fst_num=fst_str[1];
						if(fst_oper=='+'){
							ll c=fst_num-'0';
							ll cur_num=(j+c)%7;
							dp[i][cur_num]=1;
						}else{
							ll c=fst_num-'0';
							ll cur_num=(j*c)%7;
							dp[i][cur_num]=1;
						}

						char sed_oper=sed_str[0];
						char sed_num=sed_str[1];
						if(sed_oper=='+'){
							ll c=sed_num-'0';
							ll cur_num=(j+c)%7;
							dp[i][cur_num]=1;
						}else{
							ll c=sed_num-'0';
							ll cur_num=(j*c)%7;
							dp[i][cur_num]=1;
						}
					}
				}
			}
		}
		if(dp[n-1][0]){
			cout<<"LUCKY"<<"\n";
		}else{
			cout<<"UNLUCKY"<<"\n";
		}
	}
	return 0;
}