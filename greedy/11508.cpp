#include <iostream>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	priority_queue<int> pq;
	int n=0;
	cin>>n;
	for(int i=0;i<n;++i){
		int a=0;
		cin>>a;
		pq.push(a);
	}
	int sum=0;
	
	while(!pq.empty()){
		if(pq.size()>=3){
			int a=pq.top();
			pq.pop();
			int b=pq.top();
			pq.pop();
			int c=pq.top();
			pq.pop();
			sum+=(a+b);
		}else{
			int a=pq.top();
			pq.pop();
			sum+=a;
		}
	}
	cout<<sum;	
	return 0;
}