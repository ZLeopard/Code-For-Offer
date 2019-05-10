//利用队列的形式打印二叉树，先进先出的性质
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
       
        
        vector<int> res;
         if(!root)
            return res;      //如果为空，则需要返回空vector
        deque<TreeNode *> tmp;
        tmp.push_back(root);
        
        while(!tmp.empty())
        {
            TreeNode* node = tmp.front();
            res.push_back(node->val);    //取出队头数据
            tmp.pop_front();
            if(node->left)
                tmp.push_back(node->left);
            if(node->right)
                tmp.push_back(node->right);
        }
        return res;
    }
};