#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;	
	} 
	return a.first>b.first;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		vector<pair<int,int>> v;
		for(int i=0;i<8;++i){
			int a=0;
			cin>>a;
			v.push_back({a,i+1});
		}
		sort(v.begin(),v.end(),comp);
		vector<int> ans;
		int sum=0;
		for(int i=0;i<5;++i){
			sum+=v[i].first;
			ans.push_back(v[i].second);
		}
		cout<<sum<<"\n";
		sort(ans.begin(),ans.end());
		for(int i=0;i<5;++i){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}