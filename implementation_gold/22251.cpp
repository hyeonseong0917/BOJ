#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

// 1층부터 N층까지 이용 가능
// 디스플레이에 K자리의 수가 보임
// 최소 1개, 최대 P개 반전 가능
// 현재 X층, 반전시킬 수 있는 경우의 수

int N,K,P,X;
int ans=0;
string cur_floor;
void Input(){
	cin>>N>>K>>P>>X;
	cur_floor=to_string(X);
}

// cur_num에서 next_num으로 변환하기 위해 반전시켜야 하는 LED 개수
string turn_led(char c){
	if(c=='0'){
		return "1111110";
	}else if(c=='1'){
		return "0110000";
	}else if(c=='2'){
		return "1101101";
	}else if(c=='3'){
		return "1111001";
	}else if(c=='4'){
		return "0110011";
	}else if(c=='5'){
		return "1011011";
	}else if(c=='6'){
		return "1011111";
	}else if(c=='7'){
		return "1110000";
	}else if(c=='8'){
		return "1111111";
	}else if(c=='9'){
		return "1111011";
	}
	return "";
}
int reverse_cnt(char cur_num, char next_num){
	string cur_led=turn_led(cur_num);
	string next_led=turn_led(next_num);
	int cnt=0;
	for(int i=0;i<7;++i){
		if(cur_led[i]!=next_led[i]){
			++cnt;
		}
	}
	return cnt;
}
map<string,int> m;
void dfs(int idx , string cur_string, bool reversed, int cur_p){
	// cout<<idx<<" "<<cur_string<<endl;
	// cout<<cur_string<<endl;
	if(idx==K){

		if(!reversed){
			return;
		}
		// cout<<cur_string<<endl;
		if(stoi(cur_string)>=1 && stoi(cur_string)<=N){
			// cout<<cur_string<<endl;
			if(!m[cur_string]){
				m[cur_string]=1;
				++ans;
			}	
		}
		
		return;
	}
	// idx번째 숫자 반전시키지 않고 그냥 진행
	dfs(idx+1,cur_string,reversed,cur_p);	
	
	// idx번째 숫자를 i로 반전
	for(int i=0;i<=9;++i){
		if((cur_string[idx]-'0')==i) continue;
		int cur_cnt=reverse_cnt(cur_string[idx],i+'0');
		// cout<<cur_floor[idx]<<" "<<i<<" "<<cur_cnt<<" "<<cur_p<<" "<<cur_string.size()+1<<endl;
		if(cur_cnt<=cur_p){
			char c=i+'0';
			string reversed_string=cur_string;
			reversed_string[idx]=c;
			dfs(idx+1,reversed_string,1,cur_p-cur_cnt);
		}
	}

}

void solve(){
	string start_str="";
	
	for(int i=0;i<K-cur_floor.size();++i){
		start_str+='0';
	}

	start_str+=cur_floor;

	dfs(0,start_str,0,P);
	cout<<ans;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}