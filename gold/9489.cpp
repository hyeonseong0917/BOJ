#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

vector<ll> parent(1000000+1);
vector<ll> h[1000+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		while(1){
			ll n,k;
			cin>>n>>k;
			if(n==0 && k==0){
				break;
			}
			vector<ll> v(n,0);
			for(ll i=0;i<n;++i){
				cin>>v[i];
			}
			
			for(ll i=0;i<1000000+1;++i){
				parent[i]=0;
			}
			
			vector<vector<ll>> splited;
			ll pre_num=-1;
			vector<ll> tmp;
			tmp.push_back(v[0]);
			splited.push_back(tmp);
			tmp.clear();
			pre_num=v[0];
			for(ll i=1;i<n;++i){
				if(pre_num+1!=v[i] && !tmp.empty()){
					splited.push_back(tmp);
					tmp.clear();
					tmp.push_back(v[i]);
					pre_num=v[i];
				}else{
					tmp.push_back(v[i]);
					pre_num=v[i];
				}
			}
			if(!tmp.empty()) splited.push_back(tmp);
			ll root_node=splited[0][0];
			ll idx=0;
			vector<ll> node;
			node.push_back(root_node);
			ll last_node=root_node;
			if(k==root_node){
				cout<<0<<"\n";
			}else{
				for(ll i=1;i<splited.size();++i){
					for(ll j=0;j<splited[i].size();++j){
						parent[splited[i][j]]=node[idx];
						node.push_back(splited[i][j]);
					}
					++idx;
				}
				ll parent_node=parent[k];
				ll grand_node=parent[parent[k]];
				if(parent_node==0 || grand_node==0){
					cout<<0<<"\n";
					continue;
				}
				ll ans=0;
				for(ll i=1;i<=v[n-1];++i){
					ll cur_parent=parent[i];
					ll cur_grand=parent[cur_parent];
					if(cur_grand==grand_node && parent_node!=cur_parent){
						++ans;
					}
				}
				cout<<ans<<"\n";
			}
			
			
		}
	}
	return 0;
}