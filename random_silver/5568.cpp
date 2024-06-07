#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long

int n,k;
vector<int> card;
bool visited[10+1];
vector<string> v;
map<string,int> m;
int ret=0;
void pick(int cnt){
	if(cnt==0){
		string ans="";
		for(int i=0;i<v.size();++i){
			ans+=v[i];
		}
		if(!m[ans]){
			++m[ans];
			++ret;
		}
		return;
	}
	for(int i=0;i<n;++i){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(to_string(card[i]));
			pick(cnt-1);
			v.pop_back();
			visited[i]=0;
		}
	}

}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		cin>>n>>k;
		for(ll i=0;i<n;++i){
			int a=0;
			cin>>a;
			card.push_back(a);
		}
		pick(k);
		cout<<ret;
	}
	return 0;
}