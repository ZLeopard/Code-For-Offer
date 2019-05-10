//递归思想
class Solution {
public:
    int Fibonacci(int n) {
        int res[2] = {0, 1};
        if(n < 2)
            return res[n];
        long long fibNum1 = 0;
        long long fibNum2 = 1;
        long long fibN;
        for(unsigned int i = 2;i <= n;++i)   //小于等于,因为从第零项开始
        {
            fibN = fibNum1 + fibNum2;
            fibNum1 = fibNum2;
            fibNum2 = fibN;
        }
        return fibN;
    }
};

//动态规划思想
class Solution {
public:
    int Fibonacci(int n) {
        long long g = 1;
        long long f = 0;
        while(n--)
        {
            g += f;
            f = g - f;
        }
        return f;
    }
};