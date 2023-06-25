#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//1139
int N=0;
vector<pair<int,pair<int,int>>> v;

void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b,c=0;
		cin>>a>>b>>c;
		v.push_back({a,{b,c}});
	}	
}
int check[1000+1]={0,};
void solve(){
	for(int i=111;i<=999;++i){
		check[i]=0;
	}
	for(int i=0;i<N;++i){
		int cur_num=v[i].first;
		int strike=v[i].second.first;
		int ball=v[i].second.second;
		for(int j=111;j<=999;++j){
			string cur_num_str=to_string(cur_num);
			
			int cur_strike=0;
			int cur_ball=0;
			string cur_j=to_string(j);
			if(cur_j[0]=='0' ||cur_j[1]=='0' || cur_j[2]=='0'){
				continue;
			}
			if(cur_j[0]==cur_j[1] || cur_j[1]==cur_j[2] || cur_j[0]==cur_j[2]){
				continue;
			}
			for(int k=0;k<3;++k){
				if(cur_num_str[k]==cur_j[k]){
					++cur_strike;
				}
			}
			for(int k=0;k<3;++k){
				for(int p=0;p<3;++p){
					if(k==p) continue;
					if(cur_num_str[k]==cur_j[p]){
						++cur_ball;
					}
				}
			}
			if(cur_strike==strike && cur_ball==ball){
				++check[j];
			}
		}
	}
	int cnt=0;
	for(int i=111;i<=999;++i){
		if(check[i]==N){
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