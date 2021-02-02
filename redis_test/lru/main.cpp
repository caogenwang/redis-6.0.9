#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <cstdio>
extern "C"
{
    #include "adlist.h"
    #include <unistd.h>
}
using namespace std;
#define MAX_CACHE 1000
static list *g_list;
static unordered_map<int,listNode*> cache;
typedef unordered_map<int,listNode*>::iterator unmap_iter;
/*实现LRU算法，是通过两种数据结构来组织一份数据，hash用来查找，双端链表用来删除尾端数据*/
void display(list * l)
{
    listNode *node = l->head;
    cout<<"len:"<<l->len<<endl;
    for (int i = 0; i < l->len && node != nullptr; i++)
    {
        cout<<node->iv;
        if(i != l->len-1)
        {
            cout<<"->";
        }
        node = node->next;
    }
    cout<<endl;
}

void display2(list * l)
{
    listNode *node = l->tail;
    cout<<"len:"<<l->len<<endl;
    for (int i = 0; i < l->len && node != nullptr; i++)
    {
        cout<<"value:"<<node->iv<<endl;
        node = node->prev;
    }
    
}

int main(int argc, char const *argv[])
{
 
    g_list = listCreate();
    for (int i = 0; i < 1000; i++)
    {
        int key = rand()%15;
        cout<<"key:"<<key<<endl;
        unmap_iter it = cache.find(key);
        if (it != cache.end())//已经存在，需要更新，将节点放到头部
        {
            cout<<"find:"<<it->first<<endl;
            listNode *n = it->second;
            listMoveNodeToHead(g_list,n);
        }
        else
        {
            if (g_list->len >= 10)
            {
                int key = g_list->tail->iv;
                cout<<"del:"<<key<<endl;
                listDelTail(g_list);
                cache.erase(key);
            }
            
            listNode *node = (listNode *)malloc(sizeof(listNode *));
            if (nullptr == node) {
                exit(1);
            }
            node->iv = key;
            cache.insert(std::make_pair<int,listNode*>(key,node));
            cout<<"put_value:"<<key<<endl;
            listInsertHead(g_list,node);
        }
       display(g_list);
        // display2(g_list);
        sleep(4);
        cout<<"--------------------"<<endl;
    }
    
    return 0;
}
