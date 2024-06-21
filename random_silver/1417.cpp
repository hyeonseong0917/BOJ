#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		int n;
		cin>>n;
		vector<int> v(n,0);
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		priority_queue<int> pq;
		int fst_num=v[0];
		for(int i=1;i<n;++i){
			pq.push(v[i]);
		}
		int ans=0;
		while(!pq.empty()){
			int cur_num=pq.top();
			if(cur_num<fst_num){
				break;
			}else{
				pq.pop();
				++ans;
				++fst_num;
				pq.push(cur_num-1);
				// cout<<ans<<endl;
			}
		}
		cout<<ans;
	}
	return 0;
}