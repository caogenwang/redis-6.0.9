#include <iostream>
#include <unordered_map>
#include <list>
extern "C"
{
    #include <unistd.h>
}
using namespace std;
struct entry{
    int key;
    int value;
    int cnt;
    entry(int _key,int _value,int _cnt){
        this->key = _key;
        this->value = _value;
        this->cnt = _cnt;
    }
};

class Cache{
    public:
        Cache(int _capacity)
        {
            this->capacity = _capacity;
            min_cnt = 1;
        }
        int get(int key)
        {
            if(key_cnt.count(key))//命中
            {
                lit iter = key_cnt[key];
                int count = iter->cnt,value = iter->value;
                cnt_list[count+1].push_front(entry(key,value,count+1));
                cnt_list[count].erase(iter);

                if(min_cnt==count and cnt_list[count].size()==0){//更新min_cnt
                    min_cnt++;
                }

                key_cnt[key] = cnt_list[count+1].begin();
                return value;

            }
            return -1;
        }
        void put(int key,int value)
        {
             if(key_cnt.count(key))//命中,更新
            {
                lit iter = key_cnt[key];
                int count = iter->cnt,value = iter->value;
                cnt_list[count+1].push_front(entry(key,value,count+1));
                cnt_list[count].erase(iter);

                if(min_cnt==count and cnt_list[count].size()==0){//更新min_cnt
                    min_cnt++;
                }

                key_cnt[key] = cnt_list[count+1].begin();
            }
            else//放入新的节点
            {
                if(key_cnt.size() >= capacity)
                {
                    cout<<"remove"<<endl;
                    int deleteKey=cnt_list[min_cnt].back().key;
                    cnt_list[min_cnt].pop_back();
                    key_cnt.erase(deleteKey);
                }
                cnt_list[1].push_front(entry(key,value,1));
                key_cnt[key] = cnt_list[1].begin();
                min_cnt = 1;
            }
        }
        void display()
        {
            for(cache_iter it = cnt_list.begin();it != cnt_list.end();it++)
            {
                int cnt = it->first;
                list<entry> lentry = it->second;
                cout<<"count: "<<cnt<<endl;
                for (list<entry>::iterator it2 = lentry.begin(); it2 !=  lentry.end(); it2++)
                {
                    cout<<(*it2).key<<"->";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    private:
        typedef list<entry>::iterator lit;
        typedef unordered_map<int,list<entry> >::iterator cache_iter;
        int capacity;
        unordered_map<int,list<entry>::iterator> key_cnt;
        unordered_map<int,list<entry> > cnt_list;
        int min_cnt;
};

int main(int argc, char const *argv[])
{
    Cache cache(10);
    for (int i = 0; i < 1000; i++)
    {
        int key = rand()%15;
        int value = rand()%20;

        cache.put(key,value);
        sleep(4);
        cout<<"------------------"<<endl;
        cache.display();

    }
    return 0;
}
