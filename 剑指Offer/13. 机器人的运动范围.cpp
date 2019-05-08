class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows < 1 || cols < 1)
            return false;
        bool *visited = new bool[rows*cols];
        memset(visited, 0, rows*cols);
        //从0，0位置开始的，并不是从任意位置开始
        //如果扩展，从任意位置开始，可以使用for循环
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        delete [] visited;
        return count;
    }
    
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        int count = 0;
        if(check(threshold, rows, cols, row, col, visited))
        {
            visited[row*cols+col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                      + movingCountCore(threshold, rows, cols, row, col + 1, visited)
                      + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                      + movingCountCore(threshold, rows, cols, row, col - 1, visited);
        }
        return count;
    }
    
    bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        if(row >= 0 && row < rows && col >= 0 && col < cols
          && !visited[row*cols+col] && getSum(row)+getSum(col) <= threshold)
            return true;
        return false;
    }
    
    int getSum(int num)
    {
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};