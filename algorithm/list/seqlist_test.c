#include <stdio.h>
#include "seqlist.h"

typedef struct Teacher
{
    int age;
    char name[24];
} Teacher;

int main()
{
    int len = 0;
    int ret = 0;
    SeqLinkList *list = NULL;
    list = SeqLinkList_Create(10);
    if (list == NULL)
    {
        return -1;
    }
    Teacher t1, t2, t3;
    t1.age = 15;
    t2.age = 16;
    t3.age = 17;

    ret = SeqLinkList_Insert(list, (SeqLinkListNode *)&t1, 0);
    if (ret != 0)
    {
        printf("insert err\n");
    }
    ret = SeqLinkList_Insert(list, (SeqLinkListNode *)&t2, 0);
    if (ret != 0)
    {
        printf("insert err\n");
    }
    ret = SeqLinkList_Insert(list, (SeqLinkListNode *)&t3, 0);
    if (ret != 0)
    {
        printf("insert err\n");
    }
    len = SeqLinkList_Length(list);
    for (int i = 0; i < len; i++)
    {
        Teacher *tmp = (Teacher *)SeqLinkList_Get(list, i);
        if (tmp == NULL)
        {
            return -1;
        }
        printf("age: %d\n", tmp->age);
    }

    while (SeqLinkList_Length(list) > 0)
    {
        Teacher *tmp = (Teacher *)SeqLinkList_Delete(list, 0);
        if (tmp == NULL)
        {
            return -1;
        }
    }

    SeqLinkList_Destroy(list);

    return 0;
}