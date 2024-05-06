#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long


int n;
priority_queue<int> pq;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		int a;
		cin>>a;
		if(a==0){
			if(pq.empty()){
				cout<<-1<<"\n";
			}else{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}else{
			for(int j=0;j<a;++j){
				int k=0;
				cin>>k;
				pq.push(k);
			}
		}
	}
	return 0;
}