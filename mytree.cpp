#include"myheader.h"
#include"mytree.h
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
TreeNode* CreateTree(vector<int> nums){
    TreeNode *root = new TreeNode(nums[0]);    
    queue<TreeNode*> q;
    q.push(root);
    int i=1;
    while (!q.empty() and i<nums.size()){
        TreeNode *parent= q.front();
        q.pop();
        if (nums[i]!= -1) {
            parent->left = new TreeNode(nums[i]);
            q.push(parent->left);
        }
        i++;
        if (nums[i]!= -1) {
            parent->right = new TreeNode(nums[i]);
            q.push(parent->right);
        }
        i++;
    }

    return root;
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    int levelnum=1,cnt=0,level=1;
    while(!q.empty()){
        stack<int> s_end;
        vector<int> vlv;
        for (int k=0;k<levelnum;++k){
            auto top = q.front();
            if (level%2==1) vlv.emplace_back(top->val);
            else s_end.push(top->val);
            q.pop();
            if (top->left != NULL) {
                q.push(top->left);
                ++cnt;
            }
            if (top->right != NULL) {
                q.push(top->right);
                ++cnt;
            }
        }
        levelnum = cnt;
        cnt =0;
        if (level%2==0) {
            do{
                vlv.emplace_back(s_end.top());
                s_end.pop();
            }while (!s_end.empty());
        }
        ans.emplace_back(vlv);
        level +=1;
    }
    return ans;
}