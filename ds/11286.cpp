#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N=0;
	cin>>N;
	priority_queue<pair<int,int>> pq;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		if(a==0){
			if(pq.empty()){
				cout<<0<<"\n";
			}else{
				if(pq.top().second==1){
					cout<<pq.top().first<<"\n";
				}else{
					cout<<pq.top().first*-1<<"\n";
				}
				
				pq.pop();
			}
		}else{
			if(a<0){
				pq.push({a,1});
			}else{
				pq.push({-a,0});
			}
		}
	}

	return 0;
}