#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int N,M;
vector<int> picked;
const int MAX=9+1;
bool visited[MAX];
void Input(){
	cin>>N>>M;
}
void pick(int cur_num){
	if(picked.size()==M){
		for(int i=0;i<M;++i){
			cout<<picked[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=1;i<=N;++i){
		if(!visited[i]){
			visited[i]=1;
			picked.push_back(i);
			pick(i);
			picked.pop_back();
			visited[i]=0;
		}
	}
}
void solve(){
	pick(1);
}


int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}