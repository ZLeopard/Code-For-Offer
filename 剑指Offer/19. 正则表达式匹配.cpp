// 版本一: 回归方法
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(pattern == nullptr || str == nullptr)
            return false;
        return matchCore(str, pattern);
    }
    
    bool matchCore(char* str, char* pattern)
    {
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        if(*(pattern + 1) == '*')
        {
            //*可以匹配零个字符，而.必须匹配一个
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))   
            {
                return matchCore(str+1, pattern+2)    //*号匹配一个字母
                    || matchCore(str+1, pattern)      //*号匹配多个，仍然留在本状态
                    || matchCore(str, pattern+2);     //忽略a*，由于*可以匹配零个
            }
            else
                return matchCore(str, pattern+2);  //忽略a*
        }
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str+1, pattern+1);
        return false;
    }
};

// 版本二: 动态规划策略
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        string s = str;
        string p = pattern;
        vector<vector<char>> dp(s.size() + 1,vector<char>(p.size() + 1,-1));
        return isMatch(0,s,0,p,dp);
    }
    bool isMatch(int i, string& s, int j, string &p, vector<vector<char>> &dp)
    {
        if(dp[i][j] > -1) return dp[i][j];
        int pn = p.size(), sn = s.size();
        if(j==pn) return dp[i][j] = i==sn;  //匹配完成，结束
        if(j+1<pn && p[j+1]=='*')
        {
            if(isMatch(i,s,j+2,p,dp) ||
               i<sn && (p[j] == '.' || s[i] == p[j]) && isMatch(i+1,s,j,p,dp))
                return dp[i][j] = 1;
        }
        else if (i<sn && (p[j]=='.'|| s[i]==p[j]) && isMatch(i+1,s,j+1,p,dp))
            return dp[i][j] = 1;
         
        return dp[i][j] = 0;
    }
};