#include "mylist.h"
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
 };
 ListNode* CreateList(vector<int> nums){

    ListNode* head = new ListNode(nums[0]);
    ListNode * p=head;
    for (int i = 1; i < nums.size() ; ++i) {
        ListNode* cur = new ListNode(nums[i]);
        head->next = cur;
        head = cur;
    }
    head->next = NULL;
    head = p;
    return head;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    //必须new一个节点，不然返回会栈溢出
    ListNode* ans=new ListNode(0);
    ListNode* head=ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > listpq;
    for (int i = 0; i < lists.size() ; ++i) {
        if (lists[i] != NULL){
            listpq.push(pair<int,int>(lists[i]->val,i));
        }
    }
    if (listpq.empty()) return head;
    while (!listpq.empty()){
        int index=listpq.top().second;
        listpq.pop();
        ans->next=lists[index];
        ans = ans->next;
        if (lists[index] != NULL)    lists[index] = lists[index]->next;
        if (lists[index] != NULL) listpq.push(pair<int,int>(lists[index]->val,index));
    }
    ans->next = NULL;
//    for (int j = 0; j < ans.size()-1; ++j) {
//        ans[j]->next = ans[j+1];
//    }
//    ans[ans.size()-1]->next=NULL;
//    for (int k = 0; k < ans.size(); ++k) {
//        if (k!= ans.size()-1)
//        printf("%d->",ans[k]->val);
//        else printf("%d\n",ans[k]->val);
//    }
    ListNode* p;
    for (p = head->next;p!=NULL ; p=p->next) {
        printf("%d->",p->val);
    }
    return head->next;

}
//链表归并排序  先递归cut   merge
ListNode* sortList(ListNode* head) {
    if (head==NULL or head->next==NULL ) return head;
    // fast slow to  cut  the medium point
    ListNode * slow = head,*fast = head->next;
    while (fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

    }
    ListNode *temp = slow->next;
    //cut
    slow->next = NULL;
    ListNode * left = sortList(head);
    ListNode * right = sortList(temp);
    //返回的归并List
    ListNode * res = new ListNode(0);
    ListNode * pres =res;
    while (left!=NULL and right !=NULL){
        if (left->val <=right->val){
            res->next = left;
            left = left->next;
        }else{
            res->next = right;
            right = right->next;
        }
        res = res->next;
    }
    res->next = left==NULL?right:left;
    return pres->next;

}