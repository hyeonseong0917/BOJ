#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N=0;
vector<string> in_car;
vector<string> out_car;
map<string,int> m;
map<string,int> IN,OUT;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		string s="";
		cin>>s;
		in_car.push_back(s);
	}
	for(int i=0;i<N;++i){
		string s="";
		cin>>s;
		out_car.push_back(s);
	}
	reverse(in_car.begin(),in_car.end());
	reverse(out_car.begin(),out_car.end());
	for(int i=N-1;i>=0;--i){
		IN[in_car[i]]=N-i;
		OUT[out_car[i]]=N-i;
	}
	// cout<<IN["ZG206A"]<<" "<< OUT["ZG206A"]<<endl;
}
void solve(){
	int cnt=0;
	for(int i=0;i<N;++i){
		string cur_car=in_car[i];
		int in_idx=IN[cur_car];
		int out_idx=OUT[cur_car];
		for(int j=N-1;j>=0;--j){
			if(out_car[j]==cur_car){
				break;
			}
			if(IN[cur_car]<IN[out_car[j]] && m[out_car[j]]==0){
				m[out_car[j]]=1;
				++cnt;
			}
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