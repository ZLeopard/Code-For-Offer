//注意数组是有序的
class Solution {
public:
    //我们从上到下检测row，从右向左检测column
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        int columns = array[0].size();
        bool res = false;
        if(rows > 0 && columns > 0)
        {
            int row = 0;
            int column = columns - 1;
            while(row < rows && column >= 0)
            {
                if (target == array[row][column])
                {
                    res = true;
                    return res;
                }
                else if(target < array[row][column])
                    column--;
                else
                    row++;
            }
        }
        return res;
    }
};