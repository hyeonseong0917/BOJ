#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}

int main() {
	// your code goes here
	int o=1;
	while(o--){
		int n;
		cin>>n;
		vector<pair<int,int>> v;
		for(int i=0;i<n;++i){
			int a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),comp);
		priority_queue<int> pq;
		pq.push(v[0].second*-1);
		for(int i=1;i<n;++i){
			int cur_num=pq.top()*-1;
			if(cur_num<=v[i].first){
				pq.pop();
			}
			pq.push(v[i].second*-1);
		}
		int ps=pq.size();
		cout<<ps;
	}

	return 0;
}