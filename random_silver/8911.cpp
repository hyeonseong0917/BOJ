#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

#define ll long long


int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int dir=0;
		string s;
		cin>>s;
		// x1,y1 x2,y1
		// x1,
		int cy=0, cx=0;
		int y=0, x=0;
		// v[0]: y값 제일 작고 x값 제일 작은
		// v[1]: y값 제일 작고 x값 제일 큰
		// v[2]: y값 제일 크고 x값 제일 작은
		// v[3]: y값 제일 크고 x값 제일 큰
		// 1.x값과 y값의 제일 작고 큰 값을 구한다
		int min_y=0, min_x=0;
		int max_y=0, max_x=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='F'){
				y+=dy[dir];
				x+=dx[dir];
				min_y=min(min_y,y);
				min_x=min(min_x,x);
				max_y=max(max_y,y);
				max_x=max(max_x,x);
			}else if(s[i]=='L'){
				dir=(dir+3)%4;
			}else if(s[i]=='R'){
				dir=(dir+1)%4;
			}else{
				y+=dy[(dir+2)%4];
				x+=dx[(dir+2)%4];
				min_y=min(min_y,y);
				min_x=min(min_x,x);
				max_y=max(max_y,y);
				max_x=max(max_x,x);
			}
			// cout<<y<<" "<<x<<endl;
			
		}

		cout<<abs(max_y-min_y)*abs(max_x-min_x)<<"\n";
	}
	
	return 0;
}