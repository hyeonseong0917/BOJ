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
	cin>>o;
	while(o--){
		map<char,ll> check;
		check['I']=1;
		check['V']=5;
		check['X']=10;
		check['L']=50;
		check['C']=100;
		check['D']=500;
		check['M']=1000;
		// 1->I
		// 5->V
		// 10->X
		// 50->L
		// 100->C
		// 500->D
		// 1000->M
		string s;
		cin>>s;
		char c=s[0];
		if('A'<=c && c<='Z'){
			ll ans=0;
			ll n=s.size();
			if(n==1){
				cout<<check[s[0]]<<"\n";
			}else{
				ll idx=0;
				while(idx<n-1){
					if(check[s[idx]]<check[s[idx+1]]){
						ans-=check[s[idx]];
						ans+=check[s[idx+1]];
						idx+=2;
					}else{
						ans+=check[s[idx]];
						++idx;
					}
				}
				if(idx==n-1){
					ans+=check[s[idx]];
				}
				cout<<ans<<"\n";
			}
		}else{
			// 숫자임
			ll cur_num=stoll(s);
			ll cs=s.size()-1;
			// 999 ->CM XC IX
			// 900 + 90 + 9
			// 1->I
			// 5->V
			// 10->X
			// 50->L
			// 100->C
			// 500->D
			// 1000->M
			string cur_str="";
			while(cs>=0){
				ll cur_pow=1;
				for(ll i=0;i<cs;++i){
					cur_pow*=10;
				}
				ll tmp_num=cur_num/cur_pow;
				cur_num%=cur_pow;
				if(tmp_num==0){
					--cs;
					continue;
				}
				if(tmp_num==1){
					if(cur_pow==1000){
						cur_str+='M';
					}else if(cur_pow==100){
						cur_str+='C';
					}else if(cur_pow==10){
						cur_str+='X';
					}else{
						cur_str+='I';
					}
				}else if(tmp_num==2 || tmp_num==3){
					for(ll i=0;i<tmp_num;++i){
						if(cur_pow==1000){
							cur_str+='M';
						}else if(cur_pow==100){
							cur_str+='C';
						}else if(cur_pow==10){
							cur_str+='X';
						}else{
							cur_str+='I';
						}	
					}
				}else if(tmp_num==4){
					if(cur_pow==1000){
						
					}else if(cur_pow==100){
						cur_str+="CD";
					}else if(cur_pow==10){
						cur_str+="XL";
					}else{
						cur_str+="IV";
					}
				}else if(tmp_num==4 || tmp_num==5 || tmp_num==6 || tmp_num==7 || tmp_num==8){
					if(cur_pow==1000){
						
					}else if(cur_pow==100){
						cur_str+="D";
					}else if(cur_pow==10){
						cur_str+="L";
					}else{
						cur_str+="V";
					}
					tmp_num-=5;
					for(ll i=0;i<tmp_num;++i){
						if(cur_pow==1000){
							cur_str+='M';
						}else if(cur_pow==100){
							cur_str+='C';
						}else if(cur_pow==10){
							cur_str+='X';
						}else{
							cur_str+='I';
						}	
					}
				}else if(tmp_num==9){
					if(cur_pow==1000){

					}else if(cur_pow==100){
						cur_str+="CM";
					}else if(cur_pow==10){
						cur_str+="XC";
					}else{
						cur_str+="IX";
					}
				}
				--cs;
			}
			cout<<cur_str<<"\n";
		}
	}
	return 0;
}