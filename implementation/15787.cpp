#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//1210
int N,M=0;
vector<pair<int,pair<int,int>>> v;
const int MAX=100000+1;

void Input(){
	cin>>N>>M;
	
	for(int i=0;i<M;++i){
		int a=0;
		cin>>a;
		if(a<3){
			int b,c=0;
			cin>>b>>c;
			v.push_back({a,{b,c}});
		}else{
			int b=0;
			cin>>b;
			v.push_back({a,{b,-1}});
		}
	}
	// cout<<v[1].second.second;
}
vector<int> train[100000+1];
void RideOrQuit(int cur_order, int train_num, int seat_num){
	if(cur_order==1){
		if(train[train_num][seat_num]==0){
			train[train_num][seat_num]=1;
		}
	}else{
		if(train[train_num][seat_num]==1){
			train[train_num][seat_num]=0;
		}
	}
}
void Move(int cur_order, int train_num){
	if(cur_order==3){
		vector<int> cur_train=train[train_num];
		vector<int> new_train(21,0);
		for(int i=1;i<=19;++i){
			if(cur_train[i]==1){
				new_train[i+1]=1;
			}
		}
		train[train_num]=new_train;
	}else{
		vector<int> cur_train=train[train_num];
		vector<int> new_train(21,0);
		for(int i=20;i>=2;--i){
			if(cur_train[i]==1){
				new_train[i-1]=1;
			}
		}
		train[train_num]=new_train;
	}
}
void solve(){
	for(int i=1;i<=N;++i){
		vector<int> a(21,0);
		train[i]=a;
	}
	map<vector<int>,int> m;
	for(int i=0;i<M;++i){
		int cur_order=v[i].first;
		int train_num=v[i].second.first;
		int seat_num=v[i].second.second;
		if(cur_order<3){
			RideOrQuit(cur_order,train_num,seat_num);
		}else{
			Move(cur_order,train_num);
		}
	}
	int cnt=0;
	for(int i=1;i<=N;++i){
		if(m[train[i]]==0){
			m[train[i]]=1;
			++cnt;
		}
	}
	cout<<cnt;
		
	
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}