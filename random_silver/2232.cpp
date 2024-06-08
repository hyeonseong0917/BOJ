#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first>b.first;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n,0);
		vector<pair<int,int>> p;
		for(int i=0;i<n;++i){
			cin>>v[i];
			p.push_back({v[i],i});
		}
		sort(p.begin(),p.end(),comp);
		vector<bool> visited(n,0);
		vector<int> ans;
		for(int i=0;i<n;++i){
			int cur_power=p[i].first;
			int cur_idx=p[i].second;
			if(visited[cur_idx]) continue;
			visited[cur_idx]=1;
			int L=cur_idx-1;
			int R=cur_idx+1;
			// cout<<"HE"<<L<<" "<<R<<endl;
			ans.push_back(cur_idx+1);
			for(int j=L;j>=0;--j){
				if(!visited[j] && v[j]<cur_power){
					visited[j]=1;
					cur_power=v[j];
				}else{
					break;
				}
			}
			cur_power=p[i].first;
			for(int j=R;j<n;++j){
				if(!visited[j] && v[j]<cur_power){
					visited[j]=1;
					cur_power=v[j];
				}else{
					break;
				}	
			}
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<"\n";
		}
	}
	return 0;
}