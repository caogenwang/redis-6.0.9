#include "sds.h"
#define ZSKIPLIST_MAXLEVEL 32 /* Should be enough for 2^64 elements */
#define ZSKIPLIST_P 0.25      /* Skiplist P = 1/4 */

typedef struct zskiplistNode {
    sds ele;//key
    double score;//分值
    struct zskiplistNode *backward;//后退指针
    struct zskiplistLevel {
        struct zskiplistNode *forward;//前进指针
        unsigned long span;//跨度
    } level[];
} zskiplistNode;

typedef struct zskiplist {
    struct zskiplistNode *header, *tail;
    unsigned long length;//跳跃表的长度
    int level;//最大层的那个节点的层数
} zskiplist;

zskiplist *zslCreate(void);
zskiplistNode *zslCreateNode(int level, double score, sds ele);
void zslFree(zskiplist *zsl);
void zslFreeNode(zskiplistNode *node);
zskiplistNode *zslInsert(zskiplist *zsl, double score, sds ele);
int zslDelete(zskiplist *zsl, double score, sds ele, zskiplistNode **node);
void zslDeleteNode(zskiplist *zsl, zskiplistNode *x, zskiplistNode **update);