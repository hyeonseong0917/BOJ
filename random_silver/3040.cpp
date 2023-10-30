#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

vector<int> v;
bool visited[9+1];
void Input(){
	for(int i=0;i<9;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
		visited[i]=0;
	}
}
vector<int> ans;
vector<int> tmp;
void pick(int idx){
	if(tmp.size()==7){
		// cout<<idx<<"\n";
		int sum=0;
		for(int i=0;i<tmp.size();++i){
			sum+=tmp[i];
		}
		if(sum==100){
			ans=tmp;
		}
		return;
	}
	if(idx==9){
		return;
	}
	pick(idx+1);
	tmp.push_back(v[idx]);
	pick(idx+1);
	tmp.pop_back();
}
void solve(){
	pick(0);
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<"\n";
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