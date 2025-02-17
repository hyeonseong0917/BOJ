#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	ll cnt=1;
	while(o--){
		ll n;
		cin>>n;

		cout<<"Case #"<<cnt<<": ";
		++cnt;
		ll ans=-1;
		vector<ll> check(10,0);
		for(ll i=1;i<=100;++i){
			ll cur_num=n*i;
			string cur_str=to_string(cur_num);
			for(ll j=0;j<cur_str.size();++j){
				++check[cur_str[j]-'0'];
			}
			bool flag=0;
			for(ll j=0;j<10;++j){
				if(!check[j]){
					flag=1;
					break;
				}
			}
			if(!flag){
				ans=cur_num;
				break;
			}
		}
		if(ans==-1){
			cout<<"INSOMNIA"<<"\n";
		}else{
			cout<<ans<<"\n";
		}

	}
	return 0;
}