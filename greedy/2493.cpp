#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N=0;
vector<int> arr;
stack<pair<int,int>> st;
vector<int> v;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		arr.push_back(a);
	}
}
void solve(){
	st.push({arr[0],0});
	v.push_back(0);
	for(int i=1;i<N;++i){
		while(!st.empty() && st.top().first<arr[i]){
			st.pop();
		}
		
		if(st.empty()){
			st.push({arr[i],i});
			v.push_back(0);
		}else{
			v.push_back(st.top().second+1);
			st.push({arr[i],i});
		}
	}
	for(int i=0;i<v.size();++i){
		cout<<v[i]<<" ";
	}
	// cout<<v.size();
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}