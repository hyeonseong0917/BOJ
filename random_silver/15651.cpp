#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

int N,M;
vector<int> v;

void dfs(int cur_num){
	if(v.size()==M){
		for(int i=0;i<v.size();++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
		return;
	}
	for(int i=1;i<=N;++i){
		v.push_back(i);
		dfs(i);		
		v.pop_back();
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	dfs(1);
	return 0;
}