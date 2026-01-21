#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

const int MAX_NODES=2000000+1;
typedef struct NODE{
  int data;
  struct NODE* prev;
  struct NODE* next;
}NODE;

typedef struct DEQUE{
  NODE *head;
  NODE *tail;
  int count;
}DEQUE;

NODE POOL[MAX_NODES];
int p_cnt=0;
NODE* allocateNode(){
  return &POOL[p_cnt++];
}
void initDeque(DEQUE* dq){
  dq->head=NULL;
  dq->tail=NULL;
  dq->count=0;
}
int isEmpty(DEQUE* dq){
  return dq->count==0;
}
int size(DEQUE* dq){
  return dq->count;
}
void pushFront(DEQUE* dq, int data){
  NODE* newNode=&POOL[p_cnt++];
  newNode->data=data;
  newNode->prev=NULL;
  newNode->next=NULL;
  if(isEmpty(dq)){
    dq->tail=newNode;
    dq->head=newNode;
  }else{
    newNode->next=dq->head;
    dq->head->prev=newNode;
    dq->head=newNode;
  }
  dq->count++;
}
void pushBack(DEQUE* dq, int data){
  NODE* newNode=&POOL[p_cnt++];
  newNode->data=data;
  newNode->prev=NULL;
  newNode->next=NULL;
  if(isEmpty(dq)){
    dq->tail=newNode;
    dq->head=newNode;
  }else{
    dq->tail->next=newNode;
    newNode->prev=dq->tail;
    dq->tail=newNode;
  }
  dq->count++;
}
int popFront(DEQUE* dq){
  if(isEmpty(dq)) return -1;
  int data=dq->head->data;
  if(dq->head==dq->tail){
    dq->head=dq->tail=NULL;
  }else{
    dq->head=dq->head->next;
    dq->head->prev=NULL;
  }
  dq->count--;
  return data;
}
int popBack(DEQUE* dq){
  if(isEmpty(dq)) return -1;
  int data=dq->tail->data;
  if(dq->head==dq->tail){
    dq->head=dq->tail=NULL;
  }else{
    dq->tail=dq->tail->prev;
    dq->tail->next=NULL;
  }
  dq->count--;
  return data;
}
int front(DEQUE* dq){
  if(isEmpty(dq)) return -1;
  return dq->head->data;
}
int back(DEQUE* dq){
  if(isEmpty(dq)) return -1;
  return dq->tail->data;
}


DEQUE dq;

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
  initDeque(&dq);
  cin>>o;
	while(o--){
      
      ll a;
      cin>>a;
      if(a==1 || a==2){
        int b;
        cin>>b;
        if(a==1){
          pushFront(&dq,b);
        }else{  
          pushBack(&dq,b);
        }
      }else{
        if(a==3){
          cout<<popFront(&dq)<<"\n";
        }else if(a==4){
          cout<<popBack(&dq)<<"\n";
        }else if(a==5){
          cout<<size(&dq)<<"\n";
        }else if(a==6){
          cout<<(isEmpty(&dq)?1:0)<<"\n";
        }else if(a==7){
          cout<<front(&dq)<<"\n";
        }else{
          cout<<back(&dq)<<"\n";
        }
      }
	} 
	return 0;
}