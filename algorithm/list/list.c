#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct TagLink
{
    LinkListNode header;
    int length;
} TagLink;

LinkList *LinkList_Create()
{
    TagLink *ret = NULL;
    ret = (TagLink *)malloc(sizeof(TagLink));
    ret->length = 0;
    ret->header.next = NULL;
    return ret;
}
void LinkList_Destroy(LinkList *list)
{
    if (list != NULL)
    {
        free(list);
        list = NULL;
    }
}
void LinkList_Clear(LinkList *list)
{
    TagLink *tList = NULL;
    if (list == NULL)
    {
        return;
    }
    tList = (TagLink *)list;
    tList->length = 0;
    tList->header.next = NULL;
}
int LinkList_Length(LinkList *list)
{
    TagLink *tList = NULL;
    if (list == NULL)
    {
        return -1;
    }
    tList = (TagLink *)list;

    return tList->length;
}
int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
    if (list == NULL || node == NULL || pos < 0)
    {
        return -1;
    }
    TagLink *tagLink = (TagLink *)list;
    LinkListNode *cur = &(tagLink->header);
    for (int i = 0; i < pos && cur->next != NULL; i++)
    {
        cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;
    tagLink->length++;

    return 0;
}
LinkListNode *LinkList_Get(LinkList *list, int pos)
{
    if (list == NULL || pos < 0)
    {
        return NULL;
    }
    TagLink *tagLink = (TagLink *)list;
    LinkListNode *cur = &(tagLink->header);
    for (int i = 0; i < pos && cur->next != NULL; i++)
    {
        cur = cur->next;
    }
    return cur->next;
}
LinkListNode *LinkList_Delete(LinkList *list, int pos)
{
    if (list == NULL || pos < 0)
    {
        return NULL;
    }
    TagLink *tagLink = (TagLink *)list;
    LinkListNode *cur = &(tagLink->header);

    for (int i = 0; i < pos && cur->next != NULL; i++)
    {
        cur = cur->next;
    }
    // 缓存被删除的节点
    LinkListNode *ret;
    ret = cur->next;
    cur->next = ret->next;
    tagLink->length--;

    return ret;
}