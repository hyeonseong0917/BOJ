#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N=0;
vector<pair<int,pair<int,int>>> v; //과제유무,{점수,시간};

void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0,b=0,c=0;
		cin>>a;
		if(a==1){
			cin>>b>>c;
		}
		v.push_back({a,{b,c}});
	}
	
}
void solve(){
	int sum=0;
	int lastIdx=-1;
	stack<int> hw;
	for(int i=0;i<v.size();++i){
		if(v[i].first==1){
			hw.push(i);
			int curIdx=hw.top();
			--v[curIdx].second.second;
		}else{
			if(hw.size()){
				int curIdx=hw.top();
				--v[curIdx].second.second;
			}
		}
		if(hw.size()){
			int curIdx=hw.top();
			if(v[curIdx].second.second==0){
				sum+=v[curIdx].second.first;
				hw.pop();
			}
		}
	}
	cout<<sum;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}