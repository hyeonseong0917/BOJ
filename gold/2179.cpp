#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N;
vector<string> v;
map<string,int> m;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		m[s]=1;
		if(!m[s]){
			m[s]=1;
			v.push_back(s);	
		}
		
	}
}
void solve(){
	
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