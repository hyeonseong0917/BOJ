#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int N,M;
bool visited[8+1];
vector<int> v;
vector<int> tmp;
void pick(int cur_num){
	if(v.size()==M){
		for(int i=0;i<v.size();++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
		return;
	}
	for(int i=cur_num;i<=N;++i){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(i);
			pick(i+1);
			v.pop_back();
			visited[i]=0;
		}
	}
}

int main() {
	// your code goes here
	cin>>N>>M;
	pick(1);
	return 0;
}