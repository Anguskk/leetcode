
#include "myheader.h"  
#include "mytree.h"
#include "myfunc.h"
class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2); 

};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    vector<int> ans(nums1.size()+nums2.size());
    merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),ans.begin());
    if (ans.size()%2 == 1) return  (double)ans[ans.size()/2];
    else return  ( double)(ans[(ans.size()-1)/2]+ ans[ans.size()/2])/2;
};


int main(){
    Solution s;   
    
    vector<int> ans;
    
    vector<int> myvec;
    myvec.push_back(1);
    myvec.push_back(2);
    cout<<"hello"<<std::endl;
    if (true)
    {
       int a,b;
       cin>>a>>b;
       std::swap(a,b);
       cout<<a<<" "<<b<<endl;
    }
    TreeNode * myroot;
    
    TreeNode * root= new TreeNode();
    root->left = new TreeNode();
    
    
    
    string str="3+2/34*2";
    //cout<< calculate(str);
    int ret = calculate(str);

    return 0;

}