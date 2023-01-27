#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX=10000+1;
int N=0;
pair<int,int> p[MAX];
int fin,oil=0;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b=0;
		cin>>a>>b;
		p[i].first=a;
		p[i].second=b;
	}
	cin>>fin>>oil;
	sort(p,p+N);
}

int solve(){
	int cnt=0;
	priority_queue<int> pq;
	int idx=0;
	while(oil<fin){
		while(idx<N && oil>=p[idx].first){
			pq.push(p[idx].second);
			++idx;
			
		}
		if(pq.empty()){
			return -1;
		}
		oil+=pq.top();
		pq.pop();
		++cnt;
	}
	return cnt;
		
}

int main() {
	// your code goes here
	Input();
	// solve();
	cout<<solve();
	return 0;
}