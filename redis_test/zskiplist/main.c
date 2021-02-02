#include <stdio.h>
#include <stdlib.h>
#include "sds.h"
#include "zskiplist.h"

static zskiplist *g_zsklist;
int main(int argc, char const *argv[])
{
    zskiplistNode * node;
    g_zsklist = zslCreate();

    sds s =  sdsnew("hello");
    node = zslInsert(g_zsklist,20,s);

    sds s2 =  sdsnew("world");
    node = zslInsert(g_zsklist,15,s2);
    
    sds s3 =  sdsnew("nihao");
    node = zslInsert(g_zsklist,30,s3);
    
    sds s4 =  sdsnew("laji");
    node = zslInsert(g_zsklist,14,s4);

    // printf("%s\n",node->ele);
    // printf("%lu\n",node->level[1].span);
    // printf("%lf\n",node->score);

    printf("%s\n",g_zsklist->header->level[2].forward->ele);
    
    zslFree(g_zsklist);
    return 0;
}
