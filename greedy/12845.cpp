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
	int target=pq.top();
	pq.pop();
	while(!pq.empty()){
		sum+=(target+pq.top());
		pq.pop();
	}
	cout<<sum;	
	return 0;
}