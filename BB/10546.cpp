#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define MAX_TABLE (1000003)
#define MAX_NUM (1000001)
typedef unsigned long long int ull;
#define ll long long

ull myhash(const char *str)
{
	ull hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}
void mystrcpy(char *a, char *b){
    while(*a++=*b++);
}
int mystrcmp(const char *a, const char *b){
    while(*a && *a==*b) ++a, ++b;
    return *a-*b;
}
typedef struct st{
	char name[20];
	int is_fin;
}DB;
typedef struct st2{
	DB* db;
	struct st2* next;
}HASH;
HASH POOL[200000+1];
HASH HEAD[MAX_TABLE];
DB dbList[200000+1];
int p_cnt=0;
int db_cnt=0;

void solve(){
	 // HEAD 배열 초기화 추가!
    // for(int i=0;i<MAX_TABLE;++i){
    //     HEAD[i].next=NULL;
    // }
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		char s[20];
		scanf("%s",s);
		int cur_hash=myhash(s);
		HASH *nd=&POOL[p_cnt++];
		nd->db=&dbList[db_cnt++];
		mystrcpy(nd->db->name,s);
		nd->db->is_fin=0;
		nd->next=HEAD[cur_hash].next;
		HEAD[cur_hash].next=nd;
	}
	for(int i=0;i<n-1;++i){
		char s[20];
		scanf("%s",s);
		int cur_hash=myhash(s);
		HASH *nd=HEAD[cur_hash].next;
		while(nd){
			if(!mystrcmp(nd->db->name,s) && !nd->db->is_fin){
				nd->db->is_fin=1;
				break;
			}
			nd=nd->next;
		}
	}
	char ans[20];
	for(int i=0;i<db_cnt;++i){
		if(!dbList[i].is_fin){
			mystrcpy(ans,dbList[i].name);
		}
	}
	printf("%s",ans);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	// cin>>o;
	while(o--){
		solve();
	}
	return 0;
}