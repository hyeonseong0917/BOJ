#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
using namespace std;

#define ll long long

vector<int> block[4];
int K=0;
vector<pair<int,int>> v;
void Input(){
	cin>>K;
	for(int i=0;i<6;++i){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
}
void Init(){
	vector<int> a={4,2,3,1,3,1};
	vector<int> b={4,2,3,1,4,1};
	vector<int> c={2,3,1,4,2,4};
	vector<int> d={2,3,2,3,1,4};
	block[0]=a;
	block[1]=b;
	block[2]=c;
	block[3]=d;
}
void solve(){
	Init();
	int sum=0;
	for(int i=0;i<4;++i){
		vector<int> cur_dir=block[i];
		// cout<<cur_dir.size();
		vector<int> new_dir;
		bool flag=0;
		int dir=-1;
		for(int j=0;j<6;++j){
			new_dir.clear();
			flag=0;
			for(int k=0;k<6;++k){
				new_dir.push_back(cur_dir[(j+k)%6]);
			}
			for(int k=0;k<6;++k){
				if(new_dir[k]!=v[k].first){
					flag=1;
					break;
				}
			}
			if(!flag){
				dir=j;
				break;
			}
		}
		if(!flag){
			// new_dir과 v[x].first 순서를 맞춰줘야
			vector<pair<int,int>> new_v;
			dir=6-dir;
			for(int i=0;i<v.size();++i){
				new_v.push_back(v[(i+dir)%6]);
			}
			for(int i=0;i<v.size();++i){
				v[i]=new_v[i];
			}
			if(i==0){
				sum=v[0].second*v[1].second-v[3].second*v[4].second;
			}else if(i==1){
				sum=v[1].second*v[2].second-v[4].second*v[5].second;
			}else if(i==2){
				sum=v[1].second*v[2].second-v[4].second*v[5].second;
			}else{
				sum=v[4].second*v[5].second-v[1].second*v[2].second;
			}
		}
	}
	cout<<sum*K;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}