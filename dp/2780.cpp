#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

const int MAX=1000+1;

vector<ll> near_num[10+1];
ll MOD=1234567;


ll dp[MAX][10+1];
string board[3+1];
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<3 && x<3);
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int main() {
	// your code goes here
	int t=0;
	board[0]="123";
	board[1]="456";
	board[2]="789";
	near_num[7].push_back(0);
	near_num[0].push_back(7);
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<4;++k){
				int ny=i+dy[k];
				int nx=j+dx[k];
				if(isRange(ny,nx)){
					// cout<<ny<<" "<<nx<<endl;
					// if(board[i][j]=='6'){
					// 	cout<<ny<<" "<<nx<<endl;
					// }
					near_num[board[i][j]-'0'].push_back(board[ny][nx]-'0');
				}
			}
		}
	}
	for(int i=0;i<MAX;++i){
		for(int j=0;j<10+1;++j){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<=9;++i){
		dp[1][i]=1;
	}
	for(int i=0;i<=9;++i){
		dp[2][i]=near_num[i].size();
	}
	for(int i=3;i<MAX;++i){
		for(int j=0;j<10+1;++j){
			// 시작 숫자 j에 대한 경우의 수
			for(int k=0;k<near_num[j].size();++k){
				dp[i][j]+=(dp[i-1][near_num[j][k]])%MOD;
				dp[i][j]%=MOD;
			}
		}
	}
	// cout<<dp[2][9];
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		ll sum=0;
		for(int i=0;i<=9;++i){
			sum+=(dp[n][i])%MOD;
			sum%=MOD;
		}
		cout<<sum<<"\n";
	}
	return 0;
}