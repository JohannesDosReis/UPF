#include <stdio.h>

int LstFind(struct *plist, void *pData, pFunction fComp)
{
    int i = 0, length;
    length = LstSize(pList);
    void *DataList;
    char found;
    for (i = 0; i < length; i++)
    {
        found = LstGet(pList, i, DataList);
        if(found)
        {
            return i + 1;
        }
    }
}
