#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

// 1157 1314
ll ans;
int n;
string s;
int br_cnt=0;
// visited[i]=1: i번째 수는 괄호의 대상이라는 것
bool visited[20];
void Input(){
	cin>>n;
	cin>>s;
}
void Init(){
	ans=(((ll)1<<31)-1)*-1;
	for(int i=0;i<20;++i){
		visited[i]=0;
	}
}
ll Calc(char cur_oper, ll pre_num, ll cur_num){
	// cur_oper라는 자료형을 pre_num과 cur_num사이에 연산시켰을 때 결과값
	ll cur_val=0;
	if(cur_oper=='+'){
		cur_val=pre_num+cur_num;
	}else if(cur_oper=='-'){
		cur_val=pre_num-cur_num;
	}else if(cur_oper=='*'){
		cur_val=pre_num*cur_num;
	}
	return cur_val;
}

void dfs(int cur_idx, int cur_cnt){
	if(cur_cnt==0){
		ll cur_num=0;
		int idx=0;
		while(idx<n){
			if(visited[idx]){
				// 괄호임
				if(idx){
					char pre_oper=s[idx-1];
					ll cur_br=Calc(s[idx+1],s[idx]-'0',s[idx+2]-'0');
					cur_num=Calc(pre_oper,cur_num,cur_br);
				}else{
					cur_num=Calc(s[1],s[0]-'0',s[2]-'0');
				}
				idx+=4;
			}else{
				// 괄호가 아님
				if(idx){
					char pre_oper=s[idx-1];
					cur_num=Calc(pre_oper,cur_num,s[idx]-'0');
					idx+=2;
					// // 다음 수가 괄호라면?
					// if(idx+2<n-2 && visited[idx+2]){
					// 	char pre_oper=s[idx-1];
					// 	char cur_oper=s[idx+1];
					// 	char next_oper=s[idx+3];

					// 	ll cur_br=Calc(next_oper,s[idx+2]-'0',s[idx+4]-'0');
					// 	ll cur_br_num=Calc(cur_oper,s[idx]-'0',cur_br);
					// 	cur_num=Calc(pre_oper,cur_num,cur_br_num);
					// 	idx+=6;
					// }else{
					// 	// 다음 수 괄호 아님
					// 	char pre_oper=s[idx-1];
					// 	cur_num=Calc(pre_oper,cur_num,s[idx]-'0');
					// 	idx+=2;
					// }
				}else{
					// cur_num=Calc(s[1],s[0]-'0',s[2]-'0');
					cur_num=s[0]-'0';
					idx+=2;
					// // idx가 0인경우
					// if(idx+2<n && visited[idx+2]){
					// 	// 다음 수가 괄호라면?
					// 	cur_num=s[0]-'0';
					// 	char cur_oper=s[1];
					// 	char next_oper=s[3];
					// 	ll cur_br=Calc(next_oper,s[idx+2]-'0',s[idx+4]-'0');
					// 	cur_num=Calc(cur_oper,cur_num,cur_br);
					// 	idx+=6;
					// }else{
					// 	// 다음 수 괄호 아님
					// 	cur_num=Calc(s[1],s[0]-'0',s[2]-'0');
					// 	idx+=4;
					// }
				}
			}
			// cout<<idx<<" "<<cur_num<<endl;
		}
		ans=max(ans,cur_num);
		return;
	}
	if(cur_idx>=n) return;
	// cur_idx에서 괄호를 넣을 것인지?
	if(cur_idx!=n-1){
		visited[cur_idx]=1;
		visited[cur_idx+2]=1;
		dfs(cur_idx+4,cur_cnt-1);
		visited[cur_idx]=0;
		visited[cur_idx+2]=0;
	}
	// 괄호를 넣지 않음
	dfs(cur_idx+2,cur_cnt);
	
}
void Solve(){
	// 괄호를 추가한다는 연산을 어떻게?
	// 짝수번째 수에 괄호를 열기 시작, 괄호를 열었다면 다음 짝수번째 수도 check
	// 괄호의 최대 개수는 몇 개?
	// 숫자의 개수 -> n/2+1
	// 괄호의 개수 = 숫자의 개수/2
	if(n==1){
		ans=s[0]-'0';
		return;
	}
	int cnt=n/2+1;
	int br_cnt=cnt/2;
	// br_cnt는 최대 5개
	for(int i=0;i<=br_cnt;++i){
		for(int j=0;j<=n;++j){
			visited[j]=0;
		}
		dfs(0, i);
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(ll o=1;o<=1;++o){
		Init();
		Input();
		Solve();
		cout<<ans;
	}
	return 0;
}