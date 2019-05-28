// 版本一：使用IF语句进行判断
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == nullptr)
            return false;
        bool isNumber = isInterger(&string);
        if(*string == '.')
        {
            ++string;
            isNumber = isUnsigedInterger(&string) || isNumber;
        }
        if(*string == 'e' || *string == 'E')
        {
            ++string;
            isNumber = isInterger(&string) && isNumber;
        }
        return isNumber && (*string == '\0');
    }
    
    bool isUnsigedInterger(char** str)
    {
        bool isUint = false;
        while(**str != '\0' && **str >= '0' && **str <= '9')
        {
            isUint = true;
            ++(*str);
        }
        return isUint;
    }
    
    bool isInterger(char** str)
    {
        if(**str == '+' || **str == '-')
        {
            ++(*str);
        }
        return isUnsigedInterger(str);
    }
};

// 版本二：库函数的调用
#include<regex>
class Solution {
public:
    bool isNumeric(char* str)
    {
       string s=str;
       regex r("([+-])?([0-9]+)?(([.])([0-9]+))?(([eE])([+-])?([0-9]+))?");
       return regex_match(s,r);
    }
 
};