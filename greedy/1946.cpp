#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	return a.first>b.first;
}
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
}

int main() {
	// your code goes here
	int t=0;
	int N=0;
	cin>>t;
	while(t--){
		cin>>N;
		vector<pair<int,int>> v;
		vector<pair<int,int>> second_rank;
		vector<bool> visited(100001,0);
		for(int i=0;i<N;++i){
			int a,b=0;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(), v.end(), comp);
		for(int i=0;i<N;++i){
			second_rank.push_back({v[i].second,i});
		}
		sort(second_rank.begin(),second_rank.end(),cmp);
		int idx=0;
		int cnt=1;
		for(int i=0;i<N-1;++i){
			if(v[i].second>second_rank[idx].first){
				continue;
			}else{
				++idx;
				while(idx<N-1){
					if(second_rank[idx].second<i){
						++idx;
					}else{
						break;
					}
				}
				if(v[i].second<second_rank[idx].first){
					++cnt;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}