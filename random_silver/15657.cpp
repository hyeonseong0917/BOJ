#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

int N,M;
vector<int> v;
void Input(){
	cin>>N>>M;
	v=vector<int>(N,0);
	for(int i=0;i<N;++i){
		cin>>v[i];
	}
}
// 크기가 M
vector<int> tmp;
vector<vector<int>> ans;
map<vector<int>,int> m;
void pick(){
	// cout<<1<<endl;
	int t=tmp.size();
	if(t==M){
		ans.push_back(tmp);
		// cout<<1<<endl;
		return;
	}
	for(int i=0;i<N;++i){
		if(tmp.empty()){
			tmp.push_back(v[i]);	
			if(!m[tmp]){
				// cout<<1<<endl;
				m[tmp]=1;
				pick();	
			}
			tmp.pop_back();
		}else{
			int ts=tmp.size();
			if(tmp[ts-1]<=v[i] && ts<M){
				tmp.push_back(v[i]);
				if(!m[tmp]){
					// cout<<1<<endl;
					// for(int i=0;i<tmp.size();++i){
					// 	cout<<tmp[i]<<" ";
					// }cout<<endl;
					m[tmp]=1;
					pick();
				}
				tmp.pop_back();
			}
		}
		

	}
}
void solve(){
	sort(v.begin(),v.end());
	pick();
	for(int i=0;i<ans.size();++i){
		for(int j=0;j<M;++j){
			cout<<ans[i][j];
			if(j!=M-1){
				cout<<" ";
			}
		}cout<<"\n";
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();	
	return 0;
}