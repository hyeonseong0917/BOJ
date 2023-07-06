#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K=0;
vector<int> v;
void Input(){
	cin>>K;
}
void to_binary(){
	while(1){
		if(K<1){
			break;
		}
		v.push_back(K%2);
		K/=2;
	}
	reverse(v.begin(),v.end());
	
}
void solve(){
	K+=1;
	to_binary();	
	for(int i=1;i<v.size();++i){
		if(v[i]==0){
			v[i]=4;
		}else{
			v[i]=7;
		}
	}
	string ans="";
	for(int i=1;i<v.size();++i){
		ans+=(v[i]+'0');
	}
	cout<<ans;
	
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}