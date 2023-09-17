#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n;
	vector<ll> v;
	vector<ll> army_num;
	cin>>n;
	while(n--)	{
		map<ll,ll> m;
		v.clear();
		army_num.clear();
		int vs=0;
		cin>>vs;
		for(int i=0;i<vs;++i){
			ll a=0;
			cin>>a;
			if(!m[a]){
				army_num.push_back(a);
			}
			++m[a];
			v.push_back(a);
		}
		ll mid_num=vs/2;
		ll cnt=0;
		ll army=-1;
		for(int i=0;i<army_num.size();++i){
			ll cur_army=army_num[i];
			ll cur_army_num=m[cur_army];
			//과반수를 초과하지 않는지
			if(cur_army_num>mid_num){
				++cnt;
				army=cur_army;
			}
		}
		if(cnt==1){
			cout<<army<<"\n";
		}else{
			cout<<"SYJKGW"<<"\n";
		}

	}
	return 0;
}