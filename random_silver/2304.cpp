#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


bool comp(pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
}
#define ll long long
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	// 위치 L, 높이 H
	vector<pair<int,int>> v;
	int max_height=0;
	int max_height_idx=0;
	for(int i=0;i<N;++i){
		int L,H;
		cin>>L>>H;
		// max_height=max(max_height,H);
		
		v.push_back({L,H});
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<N;++i){
		if(max_height<=v[i].second){
			max_height=v[i].second;
			max_height_idx=i;
		}
	}
	int sum=0;
	// 0번 기둥에서 더 높은 기둥들만을 지붕으로.. 제일 높은 기둥 다음에는 그 인덱스 이후에 있는 높은 기둥들을 지붕으로
	int idx=0;
	int pre_idx=0;
	bool flag=0;
	if(N==1){
		cout<<max_height;
		return 0;
	}
	while(1){
		if(idx==N-1){
			break;
		}
		if(!flag){
			++idx;
			if(v[pre_idx].second<=v[idx].second){
				sum+=(v[pre_idx].second*(v[idx].first-v[pre_idx].first));
				pre_idx=idx;
			}	
			// cout<<idx<<" "<<v[idx].second<<" "<<max_height<<endl;
			// if(v[idx].second==max_height){
			// 	sum+=v[idx].second;
			// }
			if(idx==max_height_idx){
				sum+=max_height;
				// cout<<sum<<" "<<idx<<endl;
				flag=1;
			}
		}else{
			// idx이후의 가장 큰 값
			// cout<<idx<<endl;
			int cur_max_num=0;
			int cur_max_idx=idx;
			int cur_max_pos=0;
			for(int i=idx+1;i<N;++i){
				if(cur_max_num<v[i].second){
					cur_max_num=v[i].second;
					cur_max_idx=i;
					cur_max_pos=v[i].first;
				}
			}
			// cout<<cur_max_num<<endl;
			// cout<<v[cur_max_idx].first<<" "<<v[idx].first<<endl;
			sum+=(v[cur_max_idx].second*(v[cur_max_idx].first-v[idx].first));
			idx=cur_max_idx;
		}
	}
	cout<<sum;


	return 0;
}