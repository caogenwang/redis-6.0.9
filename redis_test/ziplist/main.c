#include <stdio.h>
#include <string.h>
#include "ziplist.h"
/*列表键和哈希键的应用*/
int main(int argc, char const *argv[])
{
    unsigned char *zl = ziplistNew();
    unsigned char*str = (unsigned char*)"b";
    ziplistPush(zl,str,strlen((char*)str),0);

    unsigned char*str2 = (unsigned char*)"c";
    ziplistPush(zl,str2,strlen((char*)str2),1);

    unsigned char*str3 = (unsigned char*)"de";
    ziplistPush(zl,str3,strlen((char*)str3),1);

    unsigned char*str4 = (unsigned char*)"f";
    ziplistPush(zl,str4,strlen((char*)str4),1);

    unsigned int len =  ziplistLen(zl);
    printf("%d\n",len);

    unsigned char *s = zl;int i = 0;
    for (i = 0 ; s[i] != 0xff; i++)
    {   
        printf("%x ",s[i]);
    }
    printf("length:%d\n",i);
    return 0;
}
/*
<zlbytes> <zltail> <zllen> <entry> <entry> ... <entry> <zlend>
*/
/*
|zlbytes|  |<zltail>| |<zllen>| |--b--| |--c--| |---de---|  |--f--| |zlend|
18 0 0 0   14 0 0 0     4 0     0 1 62  3 1 63  3 2 64 65   4 1 66  0xff
*/