#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v;
vector<int> tmp;
vector<int> ans;
bool visited[9+1];

void pick(int idx){
	if(tmp.size()==7){
		int cur_sum=0;
		for(int i=0;i<7;++i){
			cur_sum+=v[tmp[i]];
		}
		if(cur_sum==100 && ans.empty()){
			for(int i=0;i<7;++i){
				ans.push_back(v[tmp[i]]);
			}
		}
		return;
	}
	for(int i=idx;i<9;++i){
		if(!visited[i]){
			visited[i]=1;
			tmp.push_back(i);
			pick(i);
			tmp.pop_back();
			visited[i]=0;
		}
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	for(int i=0;i<9;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	pick(0);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<"\n";
	}
	return 0;
}