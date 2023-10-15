#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

//1323
int N;
string s;
ll ans=-11111111111;
void Input(){
	cin>>N;
	cin>>s;
}

vector<ll> num;
vector<char> oper;
vector<ll> tmp_num;
vector<char> tmp_oper;
void pick(int idx, int bracket_cnt, bool flag){
	// cout<<idx<<" "<<bracket_cnt<<endl;
	if(idx==N-1){
		if(bracket_cnt){
			return;
		}
		// 괄호를 해제한 수식을 만들고 계산하는 방법?
		if(!flag){
			num.push_back(s[idx]-'0');	
		}
		
		// for(int i=0;i<num.size();++i){
		// 	cout<<num[i]<<" ";
		// }cout<<endl;
		// for(int i=0;i<oper.size();++i){
		// 	cout<<oper[i]<<" ";
		// }cout<<endl;
		if(!flag){
			num.pop_back();		
		}
		ll sum=num[0];
		// ll init_num=num[0];
		for(int i=0;i<oper.size();++i){
			if(oper[i]=='+'){
				sum+=num[i+1];	
			}else if(oper[i]=='-'){
				sum-=num[i+1];
			}else if(oper[i]=='*'){
				sum*=num[i+1];
			}
		}
		// cout<<sum<<endl;
		ans=max(ans,sum);
		
		return;
	}
	// 현재 idx에 괄호를 씌우지 않음
	num.push_back(s[idx]-'0'); //숫자
	oper.push_back(s[idx+1]); //수식
	pick(idx+2,bracket_cnt,0);
	num.pop_back();
	oper.pop_back();
	// 괄호 개수가 남았을 경우
	
	if(bracket_cnt>0){
		// 현재 idx에 괄호를 씌움
		ll first_num=s[idx]-'0';
		ll second_num=s[idx+2]-'0';
		ll cur_oper=s[idx+1];
		ll cur_num=0;
		if(cur_oper=='+'){
			cur_num=first_num+second_num;
		}else if(cur_oper=='-'){
			cur_num=first_num-second_num;
		}else if(cur_oper=='*'){
			cur_num=first_num*second_num;
		}
		num.push_back(cur_num);
		if(idx+3<N){
			oper.push_back(s[idx+3]);
			pick(idx+4,bracket_cnt-1,0);
			oper.pop_back();
		}else{
			// idx+2==N-1
			pick(idx+2,bracket_cnt-1,1);	
		}
		num.pop_back();
	}
	
	

}
// 최대 괄호의 개수 몇 개?=>숫자의 개수/2
// 수식의 길이는 언제나 홀수, (수식길이+1)/2=숫자의 개수
void solve(){
	int max_bracket=((N+1)/2)/2;
	for(int i=0;i<=max_bracket;++i){
		//괄호의 개수가 i개
		num.clear();
		oper.clear();
		pick(0,i,0);
	}
	cout<<ans;
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