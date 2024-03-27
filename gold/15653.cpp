#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
const int MAX=10+1;
char board[MAX][MAX];
pair<int,int> init_blue, init_red, hole;
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
			if(board[i][j]=='R'){
				init_red={i,j};
			}
			if(board[i][j]=='B'){
				init_blue={i,j};
			}
			if(board[i][j]=='O'){
				hole={i,j};
			}
		}
	}
}
int ans=1222232421;
bool flag=0;
void dfs(pair<int,int> pre_blue, pair<int,int> pre_red, pair<int,int> cur_blue, pair<int,int> cur_red, int cnt){
	if(cur_blue==hole) return;
	if(cur_red==hole){
		flag=1;
		ans=min(ans,cnt);
		return;
	}
	if(pre_blue==cur_blue && pre_red==cur_red) return;
	cout<<dir<<" "<<pre_blue.first<<" "<<pre_blue.second<<" "<<cur_blue.first<<" "<<cur_blue.second<<" "<<cnt<<"\n";
	cout<<dir<<" "<<pre_red.first<<" "<<pre_red.second<<" "<<cur_red.first<<" "<<cur_red.second<<" "<<cnt<<"\n";
	// left turn, --nrx
	int nby=cur_blue.first;
	int nbx=cur_blue.second;
	int nry=cur_red.first;
	int nrx=cur_red.second;
	if(cur_blue.second<cur_red.second){
		// cur_blue 먼저
		while(1){
			--nbx;
			if(board[nby][nbx]=='#'){
				++nbx;
				break;
			}
			if(board[nby][nbx]=='O'){
				break;
			}
		}
		// 이제 cur_red
		while(1){
			--nrx;
			if(board[nry][nrx]=='#'){
				++nrx;
				break;
			}
			if(board[nry][nrx]=='O'){
				break;
			}
			if(make_pair(nry,nrx)==make_pair(nby,nbx)){
				++nrx;
				break;
			}
		}
	}else{
		// cur_red
		while(1){
			--nrx;
			if(board[nry][nrx]=='#'){
				++nrx;
				break;
			}
			if(board[nry][nrx]=='O'){
				break;
			}
		}
		// 이제 cur_blue
		while(1){
			--nbx;
			if(board[nby][nbx]=='#'){
				++nbx;
				break;
			}
			if(board[nby][nbx]=='O'){
				break;
			}
			if(make_pair(nry,nrx)==make_pair(nby,nbx)){
				++nbx;
				break;
			}
		}
	}
	dfs(cur_blue, cur_red, {nby,nbx}, {nry,nrx}, cnt+1);		
	
	// right turn, ++nrx
	nby=cur_blue.first;
	nbx=cur_blue.second;
	nry=cur_red.first;
	nrx=cur_red.second;
	if(cur_blue.second>cur_red.second){
		// cur_blue 먼저
		while(1){
			++nbx;
			if(board[nby][nbx]=='#'){
				--nbx;
				break;
			}
			if(board[nby][nbx]=='O'){
				break;
			}
		}
		// 이제 cur_red
		while(1){
			++nrx;
			if(board[nry][nrx]=='#'){
				--nrx;
				break;
			}
			if(board[nry][nrx]=='O'){
				break;
			}
			if(make_pair(nry,nrx)==make_pair(nby,nbx)){
				--nrx;
				break;
			}
		}
	}else{
		// cur_red
		while(1){
			++nrx;
			if(board[nry][nrx]=='#'){
				--nrx;
				break;
			}
			if(board[nry][nrx]=='O'){
				break;
			}
		}
		// 이제 cur_blue
		while(1){
			++nbx;
			if(board[nby][nbx]=='#'){
				--nbx;
				break;
			}
			if(board[nby][nbx]=='O'){
				break;
			}
			if(make_pair(nry,nrx)==make_pair(nby,nbx)){
				--nbx;
				break;
			}
		}
	}
	dfs(cur_blue, cur_red, {nby,nbx}, {nry,nrx}, cnt+1);
	

	// up turn, --nry
	nby=cur_blue.first;
	nbx=cur_blue.second;
	nry=cur_red.first;
	nrx=cur_red.second;
	if(cur_blue.first<cur_red.first){
		// cur_blue 먼저
		while(1){
			--nby;
			if(board[nby][nbx]=='#'){
				++nby;
				break;
			}
			if(board[nby][nbx]=='O'){
				break;
			}
		}
		// 이제 cur_red
		while(1){
			--nry;
			if(board[nry][nrx]=='#'){
				++nry;
				break;
			}
			if(board[nry][nrx]=='O'){
				break;
			}
			if(make_pair(nry,nrx)==make_pair(nby,nbx)){
				++nry;
				break;
			}
		}
	}else{
		// cur_red
		while(1){
			--nry;
			if(board[nry][nrx]=='#'){
				++nry;
				break;
			}
			if(board[nry][nrx]=='O'){
				break;
			}
		}
		// 이제 cur_blue
		while(1){
			--nby;
			if(board[nby][nbx]=='#'){
				++nby;
				break;
			}
			if(board[nby][nbx]=='O'){
				break;
			}
			if(make_pair(nry,nrx)==make_pair(nby,nbx)){
				++nby;
				break;
			}
		}
	}
	dfs(cur_blue, cur_red, {nby,nbx}, {nry,nrx}, cnt+1);	
	

	// down turn, ++nry
	nby=cur_blue.first;
	nbx=cur_blue.second;
	nry=cur_red.first;
	nrx=cur_red.second;
	if(cur_blue.first>cur_red.first){
		// cur_blue 먼저
		while(1){
			++nby;
			if(board[nby][nbx]=='#'){
				--nby;
				break;
			}
			if(board[nby][nbx]=='O'){
				break;
			}
		}
		// 이제 cur_red
		while(1){
			++nry;
			if(board[nry][nrx]=='#'){
				--nry;
				break;
			}
			if(board[nry][nrx]=='O'){
				break;
			}
			if(make_pair(nry,nrx)==make_pair(nby,nbx)){
				--nry;
				break;
			}
		}
	}else{
		// cur_red
		while(1){
			++nry;
			if(board[nry][nrx]=='#'){
				--nry;
				break;
			}
			if(board[nry][nrx]=='O'){
				break;
			}
		}
		// 이제 cur_blue
		while(1){
			++nby;
			if(board[nby][nbx]=='#'){
				--nby;
				break;
			}
			if(board[nby][nbx]=='O'){
				break;
			}
			if(make_pair(nry,nrx)==make_pair(nby,nbx)){
				--nby;
				break;
			}
		}
	}
	dfs(2,cur_blue, cur_red, {nby,nbx}, {nry,nrx}, cnt+1);	
}
void solve(){
	dfs({-1,-1},{-1,-1},init_blue,init_red,0);
}

int main() {
	Input();
	solve();
	cout<<ans;
	return 0;
}