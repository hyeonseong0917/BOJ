#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N=0;
pair<int,int> p[200000+1];

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
}

void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b=0;
		cin>>a>>b;
		p[i].first=a;
		p[i].second=b;
	}
	sort(p,p+N,comp);
}

int solve(){
	int idx=0;
	int sum=0;
	priority_queue<int> q;
	for(int i=0;i<N;++i){
		int curDead=p[i].first;
		int curNum=p[i].second;
		q.push(curNum*-1);
		while(curDead<q.size()){
			q.pop();
		}
	}
	while(!q.empty()){
		sum+=q.top()*-1;
		q.pop();
	}
	return sum;
}

int main() {
	// your code goes here
	Input();
	cout<<solve();
	return 0;
}