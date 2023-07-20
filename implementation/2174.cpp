#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A,B,N,M;
const int MAX=100+1;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<pair<pair<int,int>,char>> robot,robot_order;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<B && x<A);
}
void Input(){
	cin>>A>>B;
	cin>>N>>M;
	for(int i=0;i<N;++i){
		int a,b;
		char c;
		cin>>a>>b>>c;
		if(c=='N'){
			c='S';
		}else if(c=='S'){
			c='N';
		}
		robot.push_back({{b-1,a-1},c});
	}
	for(int i=0;i<M;++i){
		int a,b;
		char c;
		cin>>a>>c>>b;
		// if(c=='L'){
		// 	c='R';
		// }else if(c=='R'){
		// 	c='L';
		// }
		robot_order.push_back({{a-1,b},c});
	}
}
int crash_wall=0, crash_robot=0;
void simul(int robot_num, int order_num, char order){
	int y=robot[robot_num].first.first;
	int x=robot[robot_num].first.second;
	char dir=robot[robot_num].second;
	// cout<<dir<<endl;
	if(order=='R'){
		for(int i=0;i<order_num;++i){
			if(dir=='N'){
				dir='W';
			}else if(dir=='E'){
				dir='N';
			}else if(dir=='S'){
				dir='E';
			}else if(dir=='W'){
				dir='S';
			}
		}
		robot[robot_num].second=dir;
	}else if(order=='L'){
		for(int i=0;i<order_num;++i){
			if(dir=='N'){
				dir='E';
			}else if(dir=='E'){
				dir='S';
			}else if(dir=='S'){
				dir='W';
			}else if(dir=='W'){
				dir='N';
			}
		}
		robot[robot_num].second=dir;
	}else{
		// cout<<robot[0].second;
		// cout<<robot_num<<endl;
		int idx=0;
		if(dir=='N'){
			idx=0;
		}else if(dir=='E'){
			idx=1;
		}else if(dir=='S'){
			idx=2;
		}else{
			idx=3;
		}
		// cout<<y<<" "<<x<<endl;
		for(int i=0;i<order_num;++i){
			y+=dy[idx];
			x+=dx[idx];
			// cout<<y<<" "<<x<<endl;
			if(!isRange(y,x)){
				crash_wall=1;
				return;
			}
			for(int j=0;j<robot.size();++j){
				if(y==robot[j].first.first && x==robot[j].first.second){
					crash_robot=j+1;
					return;
				}
			}
		}
		robot[robot_num].first.first=y;
		robot[robot_num].first.second=x;
		
	}
}
void solve(){
	for(int i=0;i<robot_order.size();++i){
		int robot_num=robot_order[i].first.first;
		
		int order_num=robot_order[i].first.second;
		char order=robot_order[i].second;
		simul(robot_num,order_num,order);
		if(crash_wall==1){
			cout<<"Robot "<<robot_num+1<<" crashes into the wall"<<"\n";
			return;
		}
		if(crash_robot!=0){
			cout<<"Robot "<<robot_num+1<<" crashes into robot "<<crash_robot<<"\n";
			return;
		}
	}
	cout<<"OK"<<"\n";
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}