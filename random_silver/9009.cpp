#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

vector<ll> v;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	v.push_back(1);
	v.push_back(2);
	while(1){
		ll fst_num=v[v.size()-1];
		ll sed_num=v[v.size()-2];
		ll cur_num=fst_num+sed_num;
		if(cur_num<=1000000000){
			v.push_back(cur_num);
		}else{
			break;
		}
	}
	// cout<<v.size()<<" "<<v[v.size()-1];
	while(t--){
		ll N;
		cin>>N;
		vector<int> ans;
		while(N){
			ll L=0, R=v.size()-1;
			ll num=0;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<N){
					num=max(num,mid);
					L=mid+1;
				}else if(v[mid]>N){
					R=mid-1;
				}else{
					num=mid;
					break;
				}
			}
			N-=v[num];
			ans.push_back(v[num]);
		}
		reverse(ans.begin(),ans.end());
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";

	}
	
	return 0;
}