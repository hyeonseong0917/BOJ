#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int K;
	cin>>K;
	vector<ll> v;
	stack<ll> st;
	for(int i=0;i<K;++i){
		ll a;
		cin>>a;
		v.push_back(a);
	}
	ll sum=0;
	for(int i=0;i<K;++i){
		if(v[i]!=0){
			st.push(v[i]);
		}else{
			st.pop();
		}
	}
	while(!st.empty()){
		sum+=st.top();
		st.pop();
	}
	cout<<sum;
	return 0;
}