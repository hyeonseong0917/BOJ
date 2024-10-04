#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector<int> v;
vector<int> tmp;
int n,m;
bool visited[8+1];
void pick(){
	if(tmp.size()==m){
		for(int i=0;i<tmp.size();++i){
			cout<<tmp[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=0;i<n;++i){
		if(!visited[i]){
			tmp.push_back(v[i]);
			visited[i]=1;
			pick();
			visited[i]=0;
			tmp.pop_back();
		}
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		cin>>n>>m;
		for(int i=0;i<n;++i){
			int a;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		pick();
	}
	return 0;
}