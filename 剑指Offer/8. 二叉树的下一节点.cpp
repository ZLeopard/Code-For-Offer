/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr)
            return nullptr;
        TreeLinkNode* pNext = nullptr;
        if(pNode->right != nullptr)     //情况一：有右子树
        {
            TreeLinkNode* pRight = pNode->right;
            while(pRight->left != nullptr)    
                pRight = pRight->left;    //查找右子树的最左端节点
            pNext = pRight;
        }
        else if(pNode->next != nullptr)   //情况二：右子树为空
        {
            TreeLinkNode *pCurrent = pNode;
            TreeLinkNode *pParent = pNode->next;
            while(pParent != nullptr && pCurrent == pParent->right) 
                //2.1 右子树为空且该节点为右节点，则一直向上查找，直到该节点为父节点的左节点，
                //则该节点的父节点为下一节点
            {
                pCurrent = pParent;
                pParent = pParent->next;
            }
            //2.2 右子树为空且为左节点，则父节点为下一节点
            pNext = pParent;
        }
         return pNext;
    }
};