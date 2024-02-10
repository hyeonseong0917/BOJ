#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

vector<ll> v;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int X;
	cin>>X;
	string s;
	cin>>s;
	int N=s.size();
	int M=0, W=0;
	int idx=0;
	while(1){
		if(idx==N-1){
			if(s[idx]=='M'){
				if(M+1-W<=X){
					++M;
				}
			}else{
				if(W+1-M<=X){
					++W;
				}
			}
			break;
		}
		if(s[idx]=='M'){
			if(M+1>W+X){
				if(s[idx+1]=='M'){
					break;
				}else{
					++M;
					++W;
					idx+=2;
				}
			}else{
				++M;
				++idx;
			}
		}else{
			if(W+1>M+X){
				if(s[idx+1]=='W'){
					break;
				}else{
					++M;
					++W;
					idx+=2;
				}
			}else{
				++W;
				++idx;
			}
		}
	}
	cout<<M+W;
	
	return 0;
}