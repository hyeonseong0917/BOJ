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
	int N;
	cin>>N;
	string s;
	cin>>s;
	// 색 별로 나누기
	// 오른쪽 끝 or 왼쪽 끝 선점 그 끝부터 해당 색 공이 몇 개 있는지
	int blue_num=0, red_num=0;

	// 빨간 색을 선택
	// 왼쪽 끝을 설정
	int red_left_cnt=0;
	int blue_left_cnt=0;
	bool isBlueExist=0;
	bool isRedExist=0;
	for(int i=0;i<N;++i){
		if(s[i]=='R' && isBlueExist){
			++red_left_cnt;
		}
		if(s[i]=='B'){
			isBlueExist=1;
		}
		if(s[i]=='B' && isRedExist){
			++blue_left_cnt;
		}
		if(s[i]=='R'){
			isRedExist=1;
		}
	}
	// 오른쪽 끝을 설정
	int red_right_cnt=0;
	int blue_right_cnt=0;
	isBlueExist=0;
	isRedExist=0;
	for(int i=N-1;i>=0;--i){
		if(s[i]=='R' && isBlueExist){
			++red_right_cnt;
		}
		if(s[i]=='B'){
			isBlueExist=1;
		}
		if(s[i]=='B' && isRedExist){
			++blue_right_cnt;
		}
		if(s[i]=='R'){
			isRedExist=1;
		}
	}
	cout<<min(min(red_left_cnt,red_right_cnt),min(blue_left_cnt,blue_right_cnt));
	return 0;
}