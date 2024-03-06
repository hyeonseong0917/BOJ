#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int N,L;
	cin>>N>>L;
	vector<pair<int,pair<int,int>>> v;
	for(int i=0;i<N;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,{b,c}});
	}
	int ans=v[0].first;
	for(int i=0;i<N;++i){
		int cur_diff;
		if(i==N-1){
			cur_diff=L-v[i].first;
		}else{
			cur_diff=v[i+1].first-v[i].first;
		}
		if(ans%(v[i].second.first+v[i].second.second)<v[i].second.first){
			ans+=(v[i].second.first-ans%(v[i].second.first+v[i].second.second));
		}
		ans+=cur_diff;
	}
	cout<<ans;
	return 0;
}