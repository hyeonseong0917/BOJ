#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int N=0;
bool comp(pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
}
vector<pair<int,int>> pos;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		pos.push_back({a,i});
	}
	sort(pos.begin(),pos.end(),comp);
}
void solve(){
	//모두 0인경우
	map<int,int> m;
	int preNum=-1000000000-1;
	int cnt=0;
	for(int i=0;i<N;++i){
		int num=pos[i].first;
		int idx=pos[i].second;
		if(preNum<num){
			m[idx]=cnt;
			preNum=num;
			++cnt;
		}else{
			//같은 경우

			m[idx]=cnt-1;
		}
	}
	for(int i=0;i<N;++i){
		cout<<m[i]<<" ";
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