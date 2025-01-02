#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll t;
		cin>>t;
		vector<ll> v(10,0);
		// v[x]=y: 숫자 x를 만드려면 성냥이 y개 필요함
		v[0]=6; 
		v[1]=2;
		v[2]=5;
		v[3]=5;
		v[4]=4;
		v[5]=5;
		v[6]=6;
		v[7]=3;
		v[8]=7;
		v[9]=6;
		// 7개 쓰는거: 8
		// 6개 쓰는거: 0,6,9
		// 5개 쓰는거: 2,3,5
		// 4개 쓰는거: 4
		// 3개 쓰는거: 7
		// 2개 쓰는거: 1
		while(t--){
			ll n;
			cin>>n;
			if(n==2){
				cout<<1<<" "<<1<<"\n";
				continue;
			}
			string min_num="", max_num="";
			// 1. 최댓값 만들기
			if(n%2==0){
				for(ll i=0;i<(n/2);++i){
					max_num+='1';
				}
			}else{
				max_num+='7';
				for(ll i=0;i<(n-3)/2;++i){
					max_num+='1';
				}
			}
			if(n<=7){
				if(n==3){
					min_num="7";
				}
				if(n==4){
					min_num="4";
				}
				if(n==5){
					min_num="2";
				}
				if(n==6){
					min_num="6";
				}
				if(n==7){
					min_num="8";
				}
			}else{
				// 2. 최솟값 만들기 n>=8에 대하여
				// 성냥을 가장 많이 낭비시켜야 좋음
				// 자릿수를 적게 먹어야함
				// 8을 만드려면 성냥 7개 필요 낭비시키기 좋음
				// n개로 만들 수 있는 새로운 수의 최소 자릿수를 구하자
				ll cnt=(n+6)/7; // cnt개의 digit으로 이루어짐
				// 가장 앞자리를 구하려면?
				// (1) 2개 써서 1 가능한지? - n-2개<=7*(cnt-1)
				// (2) 5개 써서 2 가능한지? - n-5개<=7*(cnt-1)
				// (4) 6개 써서 6 가능한지?
				// (5) 7개 써서 8 가능한지?
				if(n-2<=7*(cnt-1)){
					min_num+='1';
					n-=2;
				}else if(n-5<=7*(cnt-1)){
					min_num+='2';
					n-=5;
				}else if(n-6<=7*(cnt-1)){
					min_num+='6';
					n-=6;
				}else{
					min_num+='8';
					n-=7;
				}
				// 뒷자리를 구하려면?
				// (1) 6개 써서 0 가능한지? n-6개의 성냥이 남는데
				// cnt개의 digit을 이론상 채우는게 가능?
				// (2) 2개 써서 1 가능한지?
				// (3) 5개 써서 2 가능한지?
				// (4) 4개 써서 4 가능한지?
				// (5) 3개 써서 7 가능한지?
				// (6) 7개 써서 8 가능한지?
				--cnt;
				while(cnt--){
					if(n-6>=0 && n-6<=7*cnt){
						min_num+='0';
						n-=6;
					}else if(n-2>=0 && n-2<=7*cnt){
						min_num+='1';
						n-=2;
					}else if(n-5>=0 && n-5<=7*cnt){
						min_num+='2';
						n-=5;
					}else if(n-4>=0 && n-4<=7*cnt){
						min_num+='4';
						n-=4;
					}else if(n-3>=0 && n-3<=7*cnt){
						min_num+='7';
						n-=3;
					}else{
						min_num+='8';
						n-=7;
					}
				}

			}
			
			
			// 
			// cout<<max_num<<endl;
			cout<<min_num<<" "<<max_num<<"\n";
		}
		
	}
	return 0;
}