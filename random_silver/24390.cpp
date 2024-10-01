#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s;
		cin>>s;
		ll cur_time=0;
		ll fst_time=stoll(s.substr(0,2));
		ll sed_time=stoll(s.substr(3));
		cur_time+=fst_time*60+sed_time;
		if(cur_time<=30){
			if(cur_time==10){
				cout<<2;
			}else if(cur_time==20){
				cout<<3;
			}else{
				cout<<1;
			}
		}else{
			ll fst_start=cur_time-30;
			ll fst_cnt=1;
			// fst_start를 10, 30, 60, 600
			while(fst_start){
				if(fst_start>=600){
					fst_start-=600;
					++fst_cnt;
				}else if(fst_start>=60){
					fst_start-=60;
					++fst_cnt;
				}else if(fst_start>=30){
					fst_start-=30;
					++fst_cnt;
				}else{
					fst_start-=10;
					++fst_cnt;
				}
			}
			ll last_start=cur_time;
			ll last_cnt=1;
			while(last_start){
				if(last_start>=600){
					last_start-=600;
					++last_cnt;
				}else if(last_start>=60){
					last_start-=60;
					++last_cnt;
				}else{
					last_start-=10;
					++last_cnt;
				}
			}
			cout<<min(fst_cnt, last_cnt);
		}
	}
	return 0;
}