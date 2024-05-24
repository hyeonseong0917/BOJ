#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		int N,M;
		cin>>N>>M;
		priority_queue<int> pq;
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			pq.push(a);
		}
		vector<int> v(M,0);
		for(int i=0;i<M;++i){
			cin>>v[i];
		}
		bool flag=0;
		for(int i=0;i<M;++i){
			if(pq.top()>=v[i]){
				int s=pq.top();
				pq.pop();
				s-=v[i];
				if(s>0){
					pq.push(s);	
				}
				
			}else{
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<0;
		}else{
			cout<<1;
		}
	}

	return 0;
}