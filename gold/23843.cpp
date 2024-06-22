#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		int n,m;
		cin>>n>>m;
		vector<int> v(n,0);
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		priority_queue<int> pq;
		int ans=0;
		for(int i=0;i<n;++i){
			if(pq.empty() || pq.size()<m){
				pq.push(v[i]*-1);
				continue;
			}
			if(pq.size()==m){
				int cur_time=pq.top()*-1;
				ans+=cur_time;
				pq.pop();
				priority_queue<int> tmp;
				while(!pq.empty()){
					int cur_num=pq.top();
					pq.pop();
					tmp.push(cur_num*-1-cur_time);
				}
				pq.push(v[i]*-1);
				while(!tmp.empty()){
					int cur_num=tmp.top();
					tmp.pop();
					pq.push(cur_num*-1);
				}
			}
		}
		int max_num=0;
		while(!pq.empty()){
			int cur_num=pq.top()*-1;
			max_num=max(max_num,cur_num);
			pq.pop();
		}
		cout<<ans+max_num;
		// cout<<ans;
	}

	return 0;
}