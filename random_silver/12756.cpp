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
	int a_atk, a_life, b_atk, b_life;
	cin>>a_atk>>a_life;
	cin>>b_atk>>b_life;
	if(a_life/b_atk==b_life/a_atk){
		// 11 5 6 3
		if(a_life%b_atk==0 && b_life%a_atk==0){
			cout<<"DRAW";
		}else{
			if(a_life%b_atk==0 || b_life%a_atk==0){
				if(a_life%b_atk==0){
					cout<<"PLAYER B";
				}else{
					cout<<"PLAYER A";
				}
			}else{
				cout<<"DRAW";	
			}	
		}
		
		
		
	}else{
		if(a_life/b_atk>b_life/a_atk){
			cout<<"PLAYER A";
		}else{
			cout<<"PLAYER B";
		}
	}
	return 0;
}