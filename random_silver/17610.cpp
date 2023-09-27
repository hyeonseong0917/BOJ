#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long

int k=0;
ll sum=0;
const int MAX=13+1;
bool visited[MAX];
// map<ll,int> m;
vector<bool> m;
vector<int> v;
void Input(){
	cin>>k;
	
	for(int i=0;i<k;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
		sum+=a;
	}
	for(ll i=0;i<=sum;++i){
		m.push_back(0);
	}
}
// + or - or 넘기기
void pick(int idx, ll sum){
	// cout<<idx<<" "<<sum<<endl;
	if(k==idx){
		if(sum>=0){
			m[sum]=1;
		}
		return;
	}
	pick(idx+1,sum);
	pick(idx+1,sum+v[idx]);
	pick(idx+1,sum-v[idx]);
	
}
void solve(){
	pick(0,0);
	int cnt=0;
	for(int i=1;i<=sum;++i){
		if(!m[i]){
			++cnt;
		}
	}
	cout<<cnt;
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