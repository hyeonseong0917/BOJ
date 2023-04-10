#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N,K=0;
const int MAX=100+1;
int A[MAX*2];

void Input(){
	cin>>N>>K;
	for(int i=1;i<=N*2;++i){
		cin>>A[i];
	}
}
vector<pair<pair<int,int>, int>> robot; //{{order,pos},flag}
int order=0;
bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
	return a.first.first<b.first.first;
}
void move(){
	queue<int> q;
	q.push(A[N*2]);
	
	for(int i=1;i<N*2;++i){
		q.push(A[i]);
	}
	for(int i=1;i<=N*2;++i){
		A[i]=q.front();
		q.pop();
	}
	for(int i=0;i<robot.size();++i){
		if(robot[i].second==1){
			++robot[i].first.second;
			if(robot[i].first.second==N){
				robot[i].second=0;
			}
			
		}
		
		
	}
	sort(robot.begin(), robot.end(),comp);
	for(int i=0;i<robot.size();++i){
		if(robot[i].second!=0){
			int nextPos=robot[i].first.second+1;
			bool flag=0;
			for(int j=0;j<robot.size();++j){
				if(i!=j && robot[j].first.second==nextPos && robot[j].second==1){
					flag=1;
					break;
				}
			}
			if(flag==0 && A[nextPos]>0){
				--A[nextPos];
				++robot[i].first.second;
				if(robot[i].first.second==N){
					robot[i].second=0;
					
				}
			}
		}
	}
	if(A[1]>0){
		--A[1];
		robot.push_back({{order++,1},1});
	}
	vector<pair<pair<int,int>,int>> r;
	for(int i=0;i<robot.size();++i){
		if(robot[i].second==1){
			r.push_back(robot[i]);
		}
	}
	robot.clear();
	robot=r;
	
}
bool isFinish(){
	int cnt=0;
	for(int i=1;i<=N*2;++i){
		if(A[i]==0){
			++cnt;
		}
	}
	if(cnt>=K){
		return 1;
	}else{
		return 0;
	}
}
int main() {
	// your code goes here
	Input();
	int cnt=0;
	while(1){
		if(isFinish()){
			break;
		}
		move();
		++cnt;
		
	}
	cout<<cnt;
	return 0;
}