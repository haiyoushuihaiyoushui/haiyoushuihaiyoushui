#ifndef __SEQSTACK__
#define __SEQSTACK__

typedef void SeqStack;
typedef void SeqStackNode;

SeqStack *SeqStack_Create(int capacity);
void SeqStack_Destroy(SeqStack *list);
void SeqStack_Clear(SeqStack *list);
int SeqStack_Length(SeqStack *list);
int SeqStack_Capacity(SeqStack *list);
int SeqStack_Insert(SeqStack *list, SeqStackNode *node, int pos);
SeqStackNode *SeqStack_Get(SeqStack *list, int pos);
SeqStackNode *SeqStack_Delete(SeqStack *list, int pos);

#endif