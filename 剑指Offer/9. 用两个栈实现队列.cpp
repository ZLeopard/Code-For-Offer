class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size() <= 0)
        {
            while(stack1.size())
            {
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        int head = stack2.top();
        stack2.pop();
        return head;
    }
//一个栈用于插入，另一个栈用于删除，如果删除栈为空，那么将插入栈数据push进删除栈
private:
    stack<int> stack1;
    stack<int> stack2;
};