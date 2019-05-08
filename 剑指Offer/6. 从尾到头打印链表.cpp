
//思路一：将链表节点压入堆栈中，然后再取出
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> nodes;
        vector<int> res;
        ListNode* pNode = head;
        while(pNode != nullptr)
        {
            nodes.push(pNode->val);
            pNode = pNode->next;
        }
        while(!nodes.empty())
        {
            res.push_back(nodes.top());
            nodes.pop();
        }
        return res;
    }
};

//思路二：递归法，但鲁棒性不太好，虽然代码简单
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> res;    //注意将vector放置全局变量
    vector<int> printListFromTailToHead(ListNode* head) {
        
        ListNode *p=NULL;
        p=head;
        if(p!=NULL){
            if(p->next!=NULL){
                printListFromTailToHead(p->next);
            }
            res.push_back(p->val);
        }
        return res;
    }
};