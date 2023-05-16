#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool comp(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b){
	if(a.first.second==b.first.second){
		if(a.second.first==b.second.first){
			return a.second.second>b.second.second;
		}
		return a.second.first>b.second.first;
	}
	return a.first.second>b.first.second;
}
int main() {
	// your code goes here
	int N,K;
	cin>>N>>K;
	vector<pair<pair<int,int>,pair<int,int>>> v; //{{국가이름, 금},{은,동}}
	for(int i=0;i<N;++i){
		int a,b,c,d=0;
		cin>>a>>b>>c>>d;
		v.push_back({{a,b},{c,d}});
	}
	int cnt=0;
	sort(v.begin(),v.end(),comp);
	map<pair<pair<int,int>,int>,int> m;
	int rank[1000+1]={0,};
	for(int i=0;i<N;++i){
		pair<pair<int,int>,int> p={{v[i].first.second,v[i].second.first},v[i].second.second};
		if(m[p]==0){
			++cnt;
			int cur_cnt=cnt;
			rank[v[i].first.first]=cur_cnt;
			for(int j=0;j<N;++j){
				if(i!=j){
					pair<pair<int,int>,int> q={{v[j].first.second,v[j].second.first},v[j].second.second};
					if(p==q){
						m[p]=1;
						rank[v[j].first.first]=cur_cnt;
						++cnt;
					}
				}
			}
		}
	}
	cout<<rank[K];
	return 0;
}