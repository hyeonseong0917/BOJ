#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	priority_queue<pair<int,int>> plus_pq, minus_pq;
	cin>>N;
	map<int,int> m; //
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		plus_pq.push({b,a});
		minus_pq.push({-b,-a});
		m[a]=b; //m[문제번호]=난이도
	}
	int M=0;
	cin>>M;
	map<pair<int,int>,int> solved;
	queue<pair<int,int>> minus_tmp;
	queue<pair<int,int>> plus_tmp;
	for(int i=0;i<M;++i){
		string s;
		cin>>s;
		if(s=="add"){
			int P,L;
			cin>>P>>L;
			plus_pq.push({L,P});
			minus_pq.push({-L,-P});
			m[P]=L;
		}else if(s=="recommend"){
			int x;
			cin>>x;
			if(x==1){
				while(!plus_pq.empty()){
					int P=plus_pq.top().second;
					int D=plus_pq.top().first; //난이도
					if(solved[{P,D}]){
						plus_pq.pop();
					}else{
						cout<<P<<"\n";
						break;
					}
				}
			}else{
				while(!minus_pq.empty()){
					int P=minus_pq.top().second*-1;
					int D=minus_pq.top().first*-1; //난이도
					if(solved[{P,D}]){
						minus_pq.pop();
					}else{
						cout<<P<<"\n";
						break;
					}
				}
			}
		}else if(s=="solved"){
			int P=0;
			cin>>P;
			int cur_num=m[P];
			solved[{P,cur_num}]=1;
		}
	}
	return 0;
}