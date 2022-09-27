#include <stdio.h>
#include "list.h"

typedef struct Teacher
{
    LinkListNode node;
    int age;
    char name[24];
} Teacher;

int main()
{
    int len = 0;
    int ret = 0;
    LinkList *list = NULL;
    list = LinkList_Create();
    if (list == NULL)
    {
        return -1;
    }
    Teacher t1, t2, t3;
    t1.age = 33;
    t2.age = 45;
    t3.age = 44;

    ret = LinkList_Insert(list, (LinkListNode *)&t1, 0);
    if (ret != 0)
    {
        printf("insert err\n");
    }
    ret = LinkList_Insert(list, (LinkListNode *)&t2, 0);
    if (ret != 0)
    {
        printf("insert err\n");
    }
    ret = LinkList_Insert(list, (LinkListNode *)&t3, 0);
    if (ret != 0)
    {
        printf("insert err\n");
    }
    len = LinkList_Length(list);
    for (int i = 0; i < len; i++)
    {
        Teacher *tmp = (Teacher *)LinkList_Get(list, i);
        if (tmp == NULL)
        {
            return -1;
        }
        printf("age: %d\n", tmp->age);
    }

    while (LinkList_Length(list) > 0)
    {
        Teacher *tmp = (Teacher *)LinkList_Delete(list, 0);
        if (tmp == NULL)
        {
            return -1;
        }
    }

    LinkList_Destroy(list);

    return 0;
}