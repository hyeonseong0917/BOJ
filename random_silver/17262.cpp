#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second){
		a.first>b.first;
	}
	return a.second<b.second;
}


bool comp2(pair<int,int> a, pair<int,int> b){
	return a.first>b.first;
}

int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	vector<pair<int,int>> v;
	int max_start=0;
	int min_end=122232421;
	for(int i=0;i<N;++i){
		int s,e;
		cin>>s>>e;
		max_start=max(max_start,s);
		min_end=min(min_end,e);
		v.push_back({s,e});
	}
	if(min_end>max_start){
		cout<<0;
	}else{
		cout<<max_start-min_end;	
	}

	// 가장 큰 스타트 시간 - 가장 빨리 시작한 
	// 가장 작은 스타트 시간 가장 작은 엔딩 시간에서 시작
	
	return 0;
}