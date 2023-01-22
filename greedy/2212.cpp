#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int N,K;
int arr[10000+1];
int diff[10000+1];

priority_queue<int> pq;

void Input(){
	cin>>N;
	cin>>K;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	sort(arr,arr+N);
	for(int i=0;i<N-1;++i){
		diff[i]=arr[i+1]-arr[i];
		pq.push(diff[i]);
	}
}

int solve(){
	if(N==1){
		return 0;
	}
	if(K==1){
		int sum=0;
		for(int i=0;i<N-1;++i){
			sum+=diff[i];
			
		}
		return sum;
	}
	for(int i=0;i<K-1;++i){
		pq.pop();
	}
	int result=0;
	while(!pq.empty()){
		result+=pq.top();
		pq.pop();
	}
	
	return result;
}

int main() {
	// your code goes here
	Input();
	cout<<solve();
	return 0;
}