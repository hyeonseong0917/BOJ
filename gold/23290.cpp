#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

int M,S;
vector<pair<int,pair<int,int>>> fish;
pair<int,int> shark;
int fdy[8]={0,-1,-1,-1,0,1,1,1};
int fdx[8]={-1,-1,0,1,1,1,0,-1};

int sdy[4]={-1,0,1,0};
int sdx[4]={0,-1,0,1};
void Input(){
	cin>>M>>S;
	for(int i=0;i<M;++i){
		int y,x,dir;
		cin>>y>>x>>dir;
		fish.push_back({dir-1,{y-1,x-1}});
	}
	cin>>shark.first>>shark.second;
	--shark.first;
	--shark.second;
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<4 && x<4);
}
vector<vector<int>> shark_dir; // {0,0,0}, {0,0,1}
vector<pair<int,pair<int,int>>> smell; // time,{y,x}

void move_fish(){
	for(int i=0;i<fish.size();++i){
		int dir=fish[i].first;
		int y=fish[i].second.first;
		int x=fish[i].second.second;
		bool is_smell=0;
		for(int j=0;j<smell.size();++j){
			if((y+fdy[dir])==smell[j].second.first && (x+fdx[dir])==smell[j].second.second){
				is_smell=1;
				break;
			}
		}
		bool is_shark=0;
		if(shark.first==(y+fdy[dir]) && shark.second==(x+fdx[dir])) is_shark=1;
		if(!isRange(y+fdy[dir],x+fdx[dir]) || is_smell || is_shark){
			int init_dir=dir;
			while(1){
				dir=(dir+7)%8;
				if(dir==init_dir){
					break;
				}
				// cout<<dir<<" "<<init_dir<<endl;
				int ny=y+fdy[dir];
				int nx=x+fdx[dir];
				is_smell=0;
				is_shark=0;
				for(int j=0;j<smell.size();++j){
					// cout<<"smell "<<smell[j].second.first<<" "<<smell[j].second.second<<endl;
					if(ny==smell[j].second.first && nx==smell[j].second.second){
						is_smell=1;
						break;
					}
				}
				if(shark.first==ny && shark.second==nx) is_shark=1;
				if(!isRange(ny,nx) || is_smell || is_shark){
					continue;
				}else{
					fish[i].first=dir;
					fish[i].second.first=ny;
					fish[i].second.second=nx;
					break;
				}
				
			}
		}else{
			fish[i].second.first=y+fdy[dir];
			fish[i].second.second=x+fdx[dir];
		}
	}
}
int cur_time=0;
map<pair<int,int>,int> is_smell_pos;
void move_shark(){
	vector<int> max_shark_dir(3,0);
	int max_fish_eat=-1;
	vector<pair<int,pair<int,int>>> cur_fish;
	vector<pair<int,pair<int,int>>> backup_fish;
	for(int i=0;i<fish.size();++i){
		backup_fish.push_back(fish[i]);
	}
	for(int i=0;i<shark_dir.size();++i){
		// i->64
		vector<int> cur_shark_dir=shark_dir[i];
		int y=shark.first;
		int x=shark.second;
		bool flag=0;
		int cur_fish_eat=0;
		
		for(int j=0;j<cur_shark_dir.size();++j){
			cur_fish.clear();
			int cur_dir=cur_shark_dir[j];
			y+=sdy[cur_dir];
			x+=sdx[cur_dir];
			if(!isRange(y,x)){
				flag=1;
				break;
			}
			// cout<<y<<" "<<x<<endl;
			// 먹는 물고기 지우기
			for(int k=0;k<fish.size();++k){
				if(fish[k].second.first==y && fish[k].second.second==x){
					++cur_fish_eat;
				}else{
					cur_fish.push_back(fish[k]);
				}
			}
			fish.clear();
			for(int k=0;k<cur_fish.size();++k){
				fish.push_back(cur_fish[k]);
			}

			// 먹은 물고기 수 카운팅
			
		}
		// 지운 물고기 복원
		fish.clear();
		for(int j=0;j<backup_fish.size();++j){
			fish.push_back(backup_fish[j]);
		}

		if(flag) continue;

		if(max_fish_eat<cur_fish_eat){
			max_fish_eat=cur_fish_eat;
			for(int j=0;j<cur_shark_dir.size();++j){
				max_shark_dir[j]=cur_shark_dir[j];
			}
		}
		// cout<<max_fish_eat<<endl;
		// if(cur_shark_dir[0]==0 && cur_shark_dir[1]==0 && cur_shark_dir[2]==0){
		// 	cout<<max_fish_eat<<endl;	
		// }
	}
	vector<pair<int,pair<int,int>>> new_fish;
	for(int i=0;i<max_shark_dir.size();++i){
		shark.first+=sdy[max_shark_dir[i]];
		shark.second+=sdx[max_shark_dir[i]];
		// cout<<shark.first<<" "<<shark.second<<endl;
		new_fish.clear();
		for(int j=0;j<fish.size();++j){
			if(fish[j].second.first==shark.first && fish[j].second.second==shark.second){
				if(!is_smell_pos[{shark.first, shark.second}]){
					is_smell_pos[{shark.first,shark.second}]=1;
					smell.push_back({cur_time,{shark.first, shark.second}});	
				}else{
					for(int k=0;k<smell.size();++k){
						if(smell[k].second.first==shark.first && smell[k].second.second==shark.second){
							smell[k].first=cur_time;
						}
					}
				}
				
			}else{
				new_fish.push_back(fish[j]);
			}
		}
		fish.clear();
		for(int j=0;j<new_fish.size();++j){
			fish.push_back(new_fish[j]);
		}
	}
}
void delete_smell(){
	vector<pair<int,pair<int,int>>> new_smell;
	for(int i=0;i<smell.size();++i){
		if(cur_time-2==smell[i].first){
			is_smell_pos[{smell[i].second.first, smell[i].second.second}]=0;
			continue;	
		} 
		new_smell.push_back(smell[i]);
		is_smell_pos[{smell[i].second.first, smell[i].second.second}]=1;
	}
	smell.clear();
	for(int i=0;i<new_smell.size();++i){
		smell.push_back(new_smell[i]);
	}
}

void magic(){
	// backup
	vector<pair<int,pair<int,int>>> tmp_fish;
	for(int i=0;i<fish.size();++i){
		tmp_fish.push_back(fish[i]);
	}
	// 물고기 이동
	// cout<<shark.first<<" "<<shark.second<<endl;
	move_fish();
	// cout<<"MOVEFISH"<<endl;
	// for(int j=0;j<fish.size();++j){
	// 	cout<<fish[j].second.first<<" "<<fish[j].second.second<<" "<<fish[j].first<<endl;
	// }
	// cout<<fish.size()<<endl;

	move_shark();
	// cout<<"MOVESHARK"<<endl;
	// cout<<shark.first<<" "<<shark.second<<endl;
	// for(int j=0;j<fish.size();++j){
	// 	cout<<fish[j].second.first<<" "<<fish[j].second.second<<" "<<fish[j].first<<endl;
	// }
	// cout<<fish.size()<<endl;
	// for(int j=0;j<smell.size();++j){
	// 	cout<<"SMELL "<<smell[j].second.first<<" "<<smell[j].second.second<<" "<<smell[j].first<<endl;
	// }
	delete_smell();
	// cout<<"DELETESMELL"<<endl;
	// cout<<fish.size()<<endl;
	for(int i=0;i<tmp_fish.size();++i){
		fish.push_back(tmp_fish[i]);
	}
	++cur_time;
	
}
void solve(){
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			for(int k=0;k<4;++k){
				vector<int> v;
				v.push_back(i);
				v.push_back(j);
				v.push_back(k);
				shark_dir.push_back(v);
			}
		}
	}
	// magic();
	// cout<<fish.size();
	for(int i=0;i<S;++i){
		// cout<<shark.first<<" "<<shark.second<<endl;
		magic();
		// cout<<shark.first<<" "<<shark.second<<endl;
		// cout<<fish.size()<<endl;
		// for(int j=0;j<fish.size();++j){
		// 	cout<<fish[j].second.first<<" "<<fish[j].second.second<<" "<<fish[j].first<<endl;
		// }
	}
	cout<<fish.size();

}



int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	Input();
	solve();
	return 0;
}