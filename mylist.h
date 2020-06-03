#include "myheader.h"
#ifndef __MYLIST__H__
#define __MYLIST__H__

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* sortList(ListNode* head);
ListNode* mergeKLists(vector<ListNode*>& lists);
ListNode* CreateList(vector<int> nums);
#endif  //!__MYLIST__H__