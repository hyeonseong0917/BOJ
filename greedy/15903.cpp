#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M;
priority_queue<long long> pq;
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		long long a=0;
		cin>>a;
		pq.push(a*-1);
	}
}
void solve(){
	for(int i=0;i<M;++i){
		long long first_num=pq.top()*-1;
		pq.pop();
		long long second_num=pq.top()*-1;
		pq.pop();
		pq.push((first_num+second_num)*-1);
		pq.push((first_num+second_num)*-1);
	}
	long long sum=0;
	while(!pq.empty()){
		sum+=pq.top();
		pq.pop();
	}
	cout<<sum*-1;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}