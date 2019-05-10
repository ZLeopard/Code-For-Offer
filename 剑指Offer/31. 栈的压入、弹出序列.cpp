class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) return false;
        stack<int> tmp;
        for(int i = 0, j = 0;i < pushV.size();)
        {
            tmp.push(pushV[i++]);     // 如果栈顶和弹出的数据一致，则弹出，否则一直压栈，直到弹出，判断最后栈是否为空
            while(j < popV.size() && tmp.top() == popV[j])
            {
                tmp.pop();
                ++j;
            }
        }
        return tmp.empty();
    }
};