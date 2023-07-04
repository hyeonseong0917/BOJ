#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n,w,L;
const int MAX=1000+1;
int truck[MAX];
int truck_time[MAX];
int cur_time=0, weight=0;
vector<pair<int,int>> bridge;
void Input(){
	cin>>n>>w>>L;
	for(int i=0;i<MAX;++i){
		truck[i]=0;
		truck_time[i]=0;
	}
	for(int i=0;i<n;++i){
		cin>>truck[i];
	}
	
}

void solve(){
	// cout<<bridge.size();
	vector<pair<int,int>> tmp;
	int idx=0;
	while(1){
		if(idx==n){
			if(bridge.size()){
				cur_time+=w;	
			}
			
			break;
		}
		//시간 먼저 가기
		for(int i=0;i<bridge.size();++i){
			++truck_time[bridge[i].first];
		}
		tmp.clear();
		for(int i=0;i<bridge.size();++i){
			if(truck_time[bridge[i].first]==w){
				bridge[i].second=0;
				truck_time[bridge[i].first]=0;
				weight-=truck[bridge[i].first];
			}else{
				tmp.push_back(bridge[i]);
			}
		}
		bridge.clear();
		bridge=tmp;
		// for(int i=0;i<bridge.size();++i){
		// 	++truck_time[bridge[i].first];
		// }
		++cur_time;
		if(weight+truck[idx]<=L && bridge.size()<w){
			// cout<<"he";
			weight+=truck[idx];
			bridge.push_back({idx,1});
			++idx;
		}
		// cout<<cur_time<<" "<<idx<<" "<<weight<<endl;
	}
	cout<<cur_time;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}