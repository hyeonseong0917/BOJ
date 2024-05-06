#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
const int MAX=32000+1;
vector<int> v[MAX];
vector<int> check(MAX,0);
void Input(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		++check[b];
	}
}

void solve(){
	priority_queue<int> pq;
	for(int i=1;i<=N;++i){
		if(!check[i]){
			pq.push(i*-1);
		}
	}
	while(!pq.empty()){
		int cur_num=pq.top()*-1;
		cout<<cur_num<<" ";
		pq.pop();
		for(int i=0;i<v[cur_num].size();++i){
			--check[v[cur_num][i]];
			if(check[v[cur_num][i]]==0){
				pq.push(v[cur_num][i]*-1);	
			}
		}
	}
	
}

int main() {
	Input();
	solve();
	return 0;
}