#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N;
string cur_str, res_str;
void Input(){
	cin>>N;
	cin>>cur_str;
	cin>>res_str;
}
int solve(string cur, string res){
	string tmp_cur=cur;
	// i-1번째 값이 다를 때, i번쨰 스위치 on
	//0번째 스위치 누르지 않고 진행
	int cnt=0;
	for(int i=1;i<N;++i){
		
		if(tmp_cur[i-1]!=res[i-1]){
			++cnt;
			tmp_cur[i-1]=res[i-1];
			if(tmp_cur[i]=='0'){
				tmp_cur[i]='1';
			}else{
				tmp_cur[i]='0';
			}
			
			if(i+1<N){
				if(tmp_cur[i+1]=='0'){
					tmp_cur[i+1]='1';
				}else{
					tmp_cur[i+1]='0';
				}	
			}
			
		}
	}
	if(tmp_cur.compare(res)==0){
		return cnt;
	}else{
		return -1;
	}
	
	
}

int main() {
	// your code goes here
	Input();
	// 0번째 스위치 누르지 않고 진행
	int firstNum=solve(cur_str, res_str);
	for(int i=0;i<2;++i){
		if(cur_str[i]=='0'){
			cur_str[i]='1';
		}else{
			cur_str[i]='0';
		}
	}
	// 0번째 스위치 누르고 진행
	int secondNum=solve(cur_str, res_str);
	if(secondNum!=-1){
		++secondNum;
	}
	if(firstNum==-1 && secondNum==-1){
		cout<<-1;
		return 0;
	}
	if(firstNum!=-1 && secondNum!=-1){
		cout<<min(firstNum, secondNum);
	}else{
		cout<<max(firstNum, secondNum);
	}
	
	
	return 0;
}