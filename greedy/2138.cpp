#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


// 최소 횟수로 스위치를 작동시켜 원하는 문자열을 만들기
// 000->100->101->010
// 010
// 00000 -> 11100 -> 10010 -> 10101
// 10101
// 앞의 인덱스부터 맞춰주기, k번째 인덱스를 동일하게 하기 위해 k+1번째 스위치 작동
// 현재 idx기준 idx-1, idx, idx+1 값을 확인, 셋 다 같지 않다면
// idx+1기준 idx,idx+2값 확인해 본 기준 셋 다 같다면 ++idx
// 000 111 000000 111111 0111 0000
// 00000
// 10101
// 00000 -> 11000 -> 10110 -> 10101
// 0번째 idx와 n-1번째 idx에 대한 고민
// idx가 0이라면 i번째 값이 다르다면 무조건 i+1번째 스위치 켜는게 이득?
// i가 0,N-1일경우만, i번째 스위치를 켰을 때 i+1스위치를 켰을 때보다 이득인지?
//
// 0000
// 1100
int N=0;
string cur_str,res_str="";
void Input(){
	cin>>N;
	cin>>cur_str;
	cin>>res_str;
}
int cnt=0;
// i번째 값이 다를 때, 
// i+1번째 스위치를 건드릴 것인가? i번째 스위치를 건드릴 것인가?
// i번째 스위치를 건드리고 i를 0부터? i+1번째 스위치를 건드림
// 000
// 011
// 101
// 011에서 101로 가야하는 이유? 0번째 스위치를 켜야하는 이유
// i번째 값이 다르다면 i-1번째까지의 cur과 res가 
// 110
// 101
// 010 => i번째 스위치를 건드려야함

// 010 되는지, 반대인 101되는지 확인 

// 000
// 111 => i+1번째 스위치를 건드려야함

string opp(string s){
	string ans="";
	for(int i=0;i<s.size();++i){
		if(s[i]=='0'){
			ans+='1';
		}else{
			ans+='0';
		}
	}
	return ans;
}
// 000
// 110

// 000
// 011
// 011
// 010

int can_make(string cur, string res){
	if(N==2){
		if(cur.compare(res)==0){
			return 0;
		}else if(cur.compare(opp(res))==0){
			return 1;
		}else{
			return -1;
		}
	}
	int cnt=0;
	map<string,int> visited;
	bool first_clear=1;
	for(int i=0;i<N-1;++i){
		bool flag=0;
		if(i==0){
			if(cur[i]!=res[i]){
				// 길이가 3보다 작다면?
				string res_tmp=res.substr(0,3);
				string tmp=cur.substr(0,2);
				string opp_tmp=opp(tmp);
				opp_tmp+=cur[2];
					// cout<<res_tmp<<endl;
					// cout<<opp_tmp<<endl;
				if(res_tmp.compare(opp_tmp)==0 || opp_tmp.substr(1,2).compare(opp(res_tmp).substr(1,2))==0){
						
					cur[0]=opp_tmp[0];
					cur[1]=opp_tmp[1];
					cur[2]=opp_tmp[2];
					++cnt;
					flag=1;
					continue;
				}
				
			}
		}
		// cout<<flag<<" "<<cur[i]<<" "<<res[i]<<endl;
		if(flag==0 && cur[i]!=res[i]){
			// i+1 스위치 on
			string cur_tmp=cur.substr(i,3);
			string res_tmp=res.substr(i,3);
			bool new_flag=0;
			if(res_tmp.compare(opp(cur_tmp))==0){
				//i+1번쨰 스위치를 킨다
				new_flag=1;
				++cnt;
				cur[i]=res[i];
				if(cur[i+1]=='0'){
					cur[i+1]='1';
				}else{
					cur[i+1]='0';
				}
				if(i+2<N){
					if(cur[i+2]=='0'){
						cur[i+2]='1';
					}else{
						cur[i+2]='0';
					}
				}	
			}else{
				//i-1번째 스위치를 킨다
				if(i>1){
					
					int curIdx=max(i-2,0);
					char c=cur[i];
					cur_tmp=cur.substr(curIdx,2);
					cur_tmp=opp(cur_tmp);
					cur_tmp+=c;
					res_tmp=res.substr(curIdx,3);	
					// cout<<i<<" "<<cur_tmp<<" "<<res_tmp<<endl;
					if(opp(cur_tmp).compare(res_tmp)==0){
						
						new_flag=1;
						cnt+=2;
						cur[i]=res[i];
						
					}
				}
				
				
			}
			if(new_flag==0){
				++cnt;
				cur[i]=res[i];
				if(cur[i+1]=='0'){
					cur[i+1]='1';
				}else{
					cur[i+1]='0';
				}
				if(i+2<N){
					if(cur[i+2]=='0'){
						cur[i+2]='1';
					}else{
						cur[i+2]='0';
					}
				}	
			}
			
		}
		// cout<<cur<<endl;
	}
	// 000
	// 101
	// cout<<cur<<endl;
	// cout<<res<<endl;
	// cout<<cnt<<endl;
	// cout<<cur.compare(res);
	if(cur.compare(res)==0){
		
		return cnt;	
	}else{
		return -1;
	}
}
int main() {
	// your code goes here
	Input();
	int first_cnt=can_make(cur_str,res_str);
	
	int second_cnt=can_make(cur_str,opp(res_str));
	if(second_cnt!=-1){
		second_cnt+=1;
	}
	
	if(first_cnt==-1 || second_cnt==-1){
		if(first_cnt==-1 && second_cnt==-1){
			cout<<-1;
		}else{
			cout<<max(first_cnt, second_cnt);
		}
	}else{
		cout<<min(first_cnt,second_cnt);
	}
	return 0;
}