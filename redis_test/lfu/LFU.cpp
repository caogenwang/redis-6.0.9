#include <iostream>
#include <list>
#include <unordered_map>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct p{
    int key,value,cnt;
    p(int a,int b,int c):key(a),value(b),cnt(c){}
};
class LFUCache {
public:
    unordered_map<int,list<p>::iterator> mp_key;
    unordered_map<int,list<p>> mp_cnt;
    int min_cnt=1;
    //key,value,cnts
    int n;
    LFUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(n==0){return -1;}
        //cout<<"get begin  ";
        if(mp_key.count(key)){//命中
            auto iter=mp_key[key];
            int cnt=iter->cnt,val=iter->value;
            mp_cnt[cnt+1].push_front(p(iter->key,val,cnt+1));//放到cnt+1的链表头部
            mp_cnt[cnt].erase(iter);    //删除之前节点
            if(min_cnt==cnt and mp_cnt[cnt].size()==0){//更新min_cnt
                min_cnt++;
            }
            mp_key[key]=mp_cnt[cnt+1].begin();  //更新mp_key
            //cout<<"get end"<<endl;
            return val;
        }
        //cout<<"get end"<<endl;
        return -1;
    }
    
    void put(int key, int value) {
        if(n==0){return;}
        //cout<<"get begin  ";
        if(mp_key.count(key)){//命中
            auto iter=mp_key[key];
            int cnt=iter->cnt;
            mp_cnt[cnt+1].push_front(p(key,value,cnt+1));
            mp_cnt[cnt].erase(iter);
            mp_key[key]=mp_cnt[cnt+1].begin();
            if(min_cnt==cnt and mp_cnt[cnt].size()==0){
                min_cnt++;
            }
        }
        else{//插入新节点
            if(mp_key.size()>=n){//需要删除cnt最小的list中最早出现的(mp_cnt[min_cnt].back())
                int deleteKey=mp_cnt[min_cnt].back().key;
                mp_cnt[min_cnt].pop_back();
                mp_key.erase(deleteKey);
            }
            mp_cnt[1].push_front(p(key,value,1));
            mp_key[key]=mp_cnt[1].begin();
            min_cnt=1;//插入新节点了，最小cnt一定是1
        }
        //cout<<"put end"<<endl;
    }
};