/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* root=ConstructBinaryTree(pre,0,pre.size()-1,vin,0,vin.size()-1);
        return root;
    }
    
// 输入的值不含有重复的数字
//前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
private:
TreeNode* ConstructBinaryTree(vector<int> pre,int startPre,int endPre,vector<int> vin,int startIn,int endIn) {
         
        if(startPre>endPre||startIn>endIn)
            return nullptr;
        TreeNode *root=new TreeNode(pre[startPre]);  //建立在堆上
         
        for(int i=startIn;i<=endIn;i++)
            if(vin[i]==pre[startPre]){
                root->left=ConstructBinaryTree(pre, startPre+1, startPre+i-startIn, 
                                               vin, startIn, i-1);  
	            //左子树的长度为i-startIn, 而右子树的长度为endIn-i+1
				//而且边界是可变的
                root->right=ConstructBinaryTree(pre, startPre+i-startIn+1, endPre, 
												vin, i+1, endIn);
                break;
            }
                 
        return root;
    }
};