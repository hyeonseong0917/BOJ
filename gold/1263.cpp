#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


vector<pair<int,int>> v;
vector<int> c;
bool comp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end(),comp);
	int sum=0;
	int min_num=122232421;
	bool flag=0;
	for(int i=0;i<N;++i){
		sum+=v[i].first;
		if(v[i].second<sum){
			flag=1;
			break;
		}
		min_num=min(min_num,v[i].second-sum);
	}
	if(flag){
		cout<<-1;
	}else{
		cout<<min_num;
	}	
	return 0;
}