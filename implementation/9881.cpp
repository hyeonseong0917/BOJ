#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N=0;
	vector<int> hill;
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		hill.push_back(a);
	}
	// sort(hill.begin(),hill.end());
	int cost=122232421;
	for(int i=0;i<=83;++i){
		int cur_cost=0;
		for(int j=0;j<hill.size();++j){
			if(hill[j]<i){
				cur_cost+=(i-hill[j])*(i-hill[j]);
			}
			if(hill[j]>(i+17)){
				cur_cost+=(i+17-hill[j])*(i+17-hill[j]);
			}
		}
		cost=min(cur_cost,cost);
	}
	cout<<cost;
	return 0;
}