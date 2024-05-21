#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> tmp[30+1];
		for(int i=0;i<n;++i){
			int k;
			cin>>k;
			for(int j=0;j<k;++j){
				int u=0;
				cin>>u;
				tmp[i].push_back(u);
			}
			int cur_num;
			cin>>cur_num;
			tmp[i].push_back(cur_num);
		}
		vector<int> cnt;
		for(int i=0;i<m;++i){
			int u=0;
			cin>>u;
			cnt.push_back(u);
		}
		// cnt[i]=i+1번 스티커 개수
		int ans=0;
		for(int i=0;i<n;++i){
			int min_num=1222232421;
			if(tmp[i].empty()) continue;
			for(int j=0;j<tmp[i].size()-1;++j){
				min_num=min(min_num,cnt[tmp[i][j]-1]);
			}
			ans+=min_num*tmp[i][tmp[i].size()-1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}