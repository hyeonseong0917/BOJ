#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N=0;
vector<long long> price;
vector<long long> dist;
void Input(){
	cin>>N;
	for(int i=0;i<N-1;++i){
		long long a=0;
		cin>>a;
		dist.push_back(a);
	}
	for(int i=0;i<N-1;++i){
		long long a=0;
		cin>>a;
		price.push_back(a);
	}
	
}
long long res=0;
void solve(){
	int idx=0;
	while(1){
		if(idx>=N-1){
			break;
		}
		if(price[idx+1]<price[idx]){
			long long cur_num=price[idx]*dist[idx];
			res+=cur_num;
			++idx;
		}else{
			long long total_dist=0;
			int init_idx=idx;
			bool flag=0;
			while(1){
				if(idx==N-1){
					break;
				}
				total_dist+=dist[idx];
				// cout<<total_dist<<"idx"<<endl;
				if(price[idx+1]<price[init_idx]){
					
					flag=1;
					break;
				}
				++idx;
				
			}
			// cout<<idx<<endl;
			long long cur_num=total_dist*price[init_idx];
			res+=cur_num;
			++idx;
			
			
		}
		// cout<<res<<" "<<idx<<endl;
	}
	cout<<res;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}