#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll N,K;
	cin>>N>>K;
	ll tmp_num=0; // 총 개수
	bool flag=0;
	for(ll i=0;i<9;++i){
		tmp_num+=9*(ll)pow(10,i)*(i+1);
		if(tmp_num>=K){
			flag=1;
			tmp_num-=9*(ll)pow(10,i)*(i+1);
			K-=tmp_num;

			ll Q=K/(i+1); // 몫
			ll M=K%(i+1); // 나머지
			ll new_num=0; // K번째 숫자가 포함되어 있는 수
			for(int j=1;j<=i;++j){
				new_num+=9*(ll)pow(10,j-1);	
			}
			new_num+=(Q+1); // new_num=9, 99, 999 꼴이므로 +1을 더해주고 몫을 더해줌
			if(M==0)
				// 나머지가 0이라면 1을 뺀 수의 마지막 숫자를 구함
				new_num-=1;
				M=i+1;
			}
			string s=to_string(new_num);
			if(N<new_num){
				cout<<-1;
			}else{
				cout<<s[M-1];	
			}
			
			break;
		}
	}
	if(!flag){
		cout<<-1;
	}
	return 0;
}