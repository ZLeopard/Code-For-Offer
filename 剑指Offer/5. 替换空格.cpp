
//版本一，利用STL
class Solution {
public:
	void replaceSpace(char *str,int length) {
        string s(str);
        int index;
        while((index = s.find(' ')) > -1)
        {
            s.erase(index, 1);
            s.insert(index, "%20");
        }
        auto ret=s.c_str();
        strcpy(str,ret);   //要进行深拷贝
	}
};

//版本二，从后向前进行处理
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i =0;i < length; i++){
            if(str[i] == ' ')
                count++;
        }
        for(int i = length; i >= 0; i--){
            if(str[i] != ' ')
            {
                str[i + 2*count] = str[i];
            }
            else{
                str[i+2*count] = '0';
                str[i+2*count-1] = '2';
                str[i+2*count-2] = '%';
                count--;
            }
        }
	}
};