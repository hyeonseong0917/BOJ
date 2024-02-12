#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
ll xor_calc(ll fst_num, ll sed_num){
	string fst_str="", sed_str="";
	while(fst_num){
		fst_str+=(fst_num%2)+'0';
		fst_num/=2;
	}
	while(sed_num){
		sed_str+=(sed_num%2)+'0';
		sed_num/=2;
	}
	if(fst_str.size()<sed_str.size()){
		ll diff=sed_str.size()-fst_str.size();
		for(ll i=0;i<diff;++i){
			fst_str+='0';
		}
	}else if(fst_str.size()>sed_str.size()){
		ll diff=fst_str.size()-sed_str.size();
		for(ll i=0;i<diff;++i){
			sed_str+='0';
		}
	}
	// cout<<fst_str<<" "<<sed_str<<endl;
	string calc_str="";
	for(ll i=0;i<fst_str.size();++i){
		if(fst_str[i]!=sed_str[i]){
			calc_str+='1';
		}else{
			calc_str+='0';
		}
	}
	// cout<<calc_str<<endl;
	// reverse(calc_str.begin(),calc_str.end());
	ll calc_num=0;
	for(ll i=0;i<calc_str.size();++i){
		if(calc_str[i]=='1'){
			calc_num+=(ll)pow(2,i);	
		}
		
	}
	return calc_num;
}
int main() {
	
	// your code goes here
	// 1 9 
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int M;
	cin>>M;
	ll sum=0;
	ll xor_sum=0;
	for(int i=0;i<M;++i){
		ll a;
		cin>>a;
		if(a==1 || a==2){
			ll x=0;
			cin>>x;
			xor_sum=xor_calc(xor_sum,x);
			if(a==1){
				sum+=x;
			}else{
				sum-=x;
			}
		}else{
			if(a==3){
				cout<<sum<<"\n";
			}else{
				cout<<xor_sum<<"\n";
			}
		}
	}
	
	

	return 0;
}