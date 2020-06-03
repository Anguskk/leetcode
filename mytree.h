#ifndef __MYTREE__H__
#define __MYTREE__H__
#include "myheader.h"
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     //成员列表初始化
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
TreeNode* CreateTree(vector<int> nums);
vector<vector<int>> zigzagLevelOrder(TreeNode* root) ;
#endif  //!__MYTREE__H__