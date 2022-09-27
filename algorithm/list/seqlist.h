#ifndef _SEQLIST_H
#define _SEQLIST_H

typedef void SeqLinkList;

typedef void SeqLinkListNode;

SeqLinkList *SeqLinkList_Create(int cap);
void SeqLinkList_Destroy(SeqLinkList *list);
void SeqLinkList_Clear(SeqLinkList *list);
int SeqLinkList_Length(SeqLinkList *list);
int SeqLinkList_Capacity(SeqLinkList *list);
int SeqLinkList_Insert(SeqLinkList *list, SeqLinkListNode *node, int pos);
SeqLinkListNode *SeqLinkList_Get(SeqLinkList *list, int pos);
SeqLinkListNode *SeqLinkList_Delete(SeqLinkList *list, int pos);

#endif
