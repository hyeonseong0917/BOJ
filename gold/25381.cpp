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
	while(o--){
		string s;
		cin>>s;
		ll n=s.size();
		vector<bool> check(n,0);
		vector<ll> A,B,C;
		for(ll i=0;i<s.size();++i){
			if(s[i]=='A'){
				A.push_back(i);
			}else if(s[i]=='B'){
				B.push_back(i);
			}else{
				C.push_back(i);
			}
		}
		ll BL=0, CL=0;
		ll as=A.size();
		ll bs=B.size();
		ll cs=C.size();
		ll ans=0;
		while(BL<bs && CL<cs){
			if(B[BL]<C[CL]){
				++ans;
				check[B[BL]]=1;
				check[C[CL]]=1;
				++BL;
				++CL;
			}else{
				++CL;
			}
		}
		vector<ll> tmp;
		for(ll i=0;i<bs;++i){
			if(!check[B[i]]){
				tmp.push_back(B[i]);
			}
		}
		ll AL=0;
		BL=0;
		ll ts=tmp.size();
		while(AL<as && BL<ts){
			if(A[AL]<tmp[BL]){
				++ans;
				++AL;
				++BL;
			}else{
				++BL;
			}
		}
		cout<<ans;

	}
	return 0;
}