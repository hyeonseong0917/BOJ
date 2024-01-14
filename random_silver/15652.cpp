#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int N,M;
void Input(){
	cin>>N>>M;
}
vector<int> v;
void pick(int cur_num){
	if(v.size()==M){
		for(int i=0;i<v.size();++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
		return;
	}
	for(int i=cur_num;i<=N;++i){
		v.push_back(i);
		pick(i);
		v.pop_back();
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	pick(1);
	return 0;
}