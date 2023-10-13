#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long
// 사랑해 내전부



// 첫번째 행사: k개의 접시를 연속해서 먹을경우 할인된 정액 가격
// 두번째 행사: 각 고객에게 초밥 쿠폰 발행, 1번 행사에 참가할 경우 해당 초밥 제공
// 지금 벨트에서 손님이 먹을 수 있는 초밥 가짓수의 최댓값

int N,d,k,c; // N: 접시의 수, d: 초밥의 가짓수, k: 연속해서 먹는 접시 수, c: 쿠폰 번호
vector<int> belt;
bool check[30000+1];
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>d>>k>>c;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		belt.push_back(a);
	}
	int cnt=0;
	for(int i=0;i<N;++i){
		memset(check,0,sizeof(check));
		int flag=0;
   		for(int j=i;j<i+k;++j){
   			if(check[belt[j%N]]) ++flag;
   			else check[belt[j%N]]=1;
   		}
   		int cur_cnt=0;
   		if(!check[c]){
   			++cur_cnt;
   		}
   		cur_cnt+=(k-flag);
   		cnt=max(cnt,cur_cnt);
		
	}
	cout<<cnt;
	return 0;
}