#include <iostream>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	priority_queue<double> pq;
	int n=0;
	cin>>n;
	for(int i=0;i<n;++i){
		double a=0;
		cin>>a;
		pq.push(a);
	}
	double sum=0;
	sum+=pq.top();
	pq.pop();
	while(!pq.empty()){
		double a=pq.top();
		sum+=(a/2);
		pq.pop();
	}
	cout<<sum;	
	return 0;
}