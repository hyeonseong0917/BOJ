#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MAX=200000+1;
int N,Q;
int cow[MAX];
int to_change[MAX];
int sum=0;
void Input(){
	cin>>N>>Q;
	
	for(int i=0;i<N;++i){
		cin>>cow[i];
	}
	for(int i=0;i<Q;++i){
		cin>>to_change[i];
		--to_change[i];
	}
	for(int i=0;i<N;++i){
		int s=1;
		for(int j=0;j<4;++j){
			if(i+j>=N){
				s*=(cow[i+j-N]);
				
			}else{
				s*=(cow[i+j]);
			}
		}
		sum+=s;
	}
}
void calc(int cur_cow){
	//cur_cow-3에서 시작
	vector<int> v;
	for(int i=-3;i<=3;++i){
		int cur_num=cur_cow+i;
		if(cur_num<0){
			cur_num=N-abs(cur_num);
		}else if(cur_num>=N){
			cur_num-=N;
		}
		v.push_back(cur_num);	
	}
	int s=0;
	for(int i=0;i<4;++i){
		// cout<<
		s+=(cow[v[i]]*cow[v[i+1]]*cow[v[i+2]]*cow[v[i+3]]);
		// cout<<s<<endl;
	}
	sum+=(s*-2);
	cow[cur_cow]*=-1;
}
void solve(){
	for(int i=0;i<Q;++i){
		int cur_cow=to_change[i];
		calc(cur_cow);	
		cout<<sum<<"\n";
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	
	return 0;
}