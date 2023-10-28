#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	// 1 9 
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll finger_hurt=0;
	ll finger_cnt=0;
	cin>>finger_hurt;
	cin>>finger_cnt;
	ll ans=0;
	ans=(finger_cnt/2)*8;
	if(finger_hurt==5){
		ans=finger_cnt*8;
		ans+=4;
	}else if(finger_hurt==1){
		ans=finger_cnt*8;
	}else{
		if(finger_cnt%2==0){
			ans+=(finger_hurt-1);
		}else{
			ans+=(5+(4-finger_hurt));
		}
	}
	cout<<ans<<"\n";	
	
	

	return 0;
}