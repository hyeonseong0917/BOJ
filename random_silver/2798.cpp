#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long
int N,M;
const int MAX=100+1;
vector<int> card;
bool visited[MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		card.push_back(a);
	}
	memset(visited,0,sizeof(visited));
}
int ans=0;
vector<int> v;
void pick(int idx, int cnt, int sum){
	if(cnt==3){
		ans=max(ans,sum);
		return;
	}
	if(idx==N){
		return;
	}
	for(int i=idx;i<N;++i){
		if(!visited[i] && sum+card[i]<=M){
			visited[i]=1;
			pick(i,cnt+1,sum+card[i]);
			visited[i]=0;
		}
	}
}
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	Input();
	pick(0,0,0);
	cout<<ans;

	return 0;
}