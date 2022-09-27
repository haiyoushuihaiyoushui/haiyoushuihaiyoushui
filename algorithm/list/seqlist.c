#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct TagLink
{
    int length;
    int capacity;
    long *array;
} TagLink;

SeqLinkList *SeqLinkList_Create(int cap)
{
    TagLink *tmp = NULL;
    tmp = (TagLink *)malloc(sizeof(TagLink));
    if (tmp == NULL)
    {
        printf("SeqLinkList_Create malloc error");
        return NULL;
    }
    tmp->array = (long *)malloc(sizeof(long) * cap);
    if (tmp == NULL)
    {
        printf("SeqLinkList_Create malloc error");
        return NULL;
    }
    tmp->capacity = cap;
    tmp->length = 0;
    return tmp;
}
void SeqLinkList_Destroy(SeqLinkList *list)
{
    if (list == NULL)
    {
        return;
    }
    TagLink *tagList = (TagLink *)list;
    if (tagList->array != NULL)
    {
        free(tagList->array);
    }
    free(tagList);
    list = NULL;
}
void SeqLinkList_Clear(SeqLinkList *list)
{
    TagLink *tList = NULL;
    if (list == NULL)
    {
        return;
    }
    tList = (TagLink *)list;
    tList->length = 0;
}
int SeqLinkList_Length(SeqLinkList *list)
{
    TagLink *tList = NULL;
    if (list == NULL)
    {
        return -1;
    }
    tList = (TagLink *)list;

    return tList->length;
}

int SeqLinkList_Capacity(SeqLinkList *list)
{
    TagLink *tList = NULL;
    if (list == NULL)
    {
        return -1;
    }
    tList = (TagLink *)list;

    return tList->capacity;
}

int SeqLinkList_Insert(SeqLinkList *list, SeqLinkListNode *node, int pos)
{
    if (list == NULL || node == NULL || pos < 0)
    {
        return -1;
    }
    TagLink *tmpList = (TagLink *)list;
    if (tmpList->length >= tmpList->capacity)
    {
        printf("len error");
        return -1;
    }
    if (pos > tmpList->length)
    {
        printf("modify pos");
        pos = tmpList->length;
    }
    for (int i = tmpList->length; i > pos; i--)
    {
        tmpList->array[i] = tmpList->array[i - 1];
    }
    tmpList->array[pos] = (long)node;
    tmpList->length++;

    return 0;
}

SeqLinkListNode *SeqLinkList_Get(SeqLinkList *list, int pos)
{
    if (list == NULL || pos < 0)
    {
        return NULL;
    }
    TagLink *tmpList = (TagLink *)list;
    return (SeqLinkListNode *)tmpList->array[pos];
}

SeqLinkListNode *SeqLinkList_Delete(SeqLinkList *list, int pos)
{
    if (list == NULL || pos < 0)
    {
        return NULL;
    }

    SeqLinkListNode *ret = NULL;
    TagLink *tmpList = (TagLink *)list;
    if (tmpList->length >= tmpList->capacity || pos > tmpList->length)
    {
        printf("len error");
        return NULL;
    }
    // 缓存被删除的节点
    ret = (SeqLinkList *)tmpList->array[pos];
    for (int i = pos; i < tmpList->length + 1; i++)
    {
        tmpList->array[i] = tmpList->array[i + 1];
    }
    tmpList->length--;
    return ret;
}