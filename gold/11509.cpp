#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	vector<int> v;
	map<int,int> m;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	int cnt=0;
	for(int i=0;i<N;++i){
		if(m[v[i]]){
			--m[v[i]];
			++m[v[i]-1];
		}else{
			++cnt;
			++m[v[i]-1];
		}
	}
	cout<<cnt;

	return 0;
}