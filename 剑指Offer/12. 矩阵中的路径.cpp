class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || rows < 1 || cols < 1 || str==nullptr)
            return false;
        
        bool * visited = new bool[rows*cols];
        memset(visited, 0, rows*cols);
        
        int pathLength = 0;
        for(int row = 0;row < rows; ++row)
        {
            for(int col = 0;col < cols; ++col)
            {
                if(str[0] == matrix[row*cols+col] &&      //优化，遍历整个矩阵，如果匹配到第一个字母，然后再回溯寻找
				hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
                {
                    return true;
                }
            }
        }
        delete [] visited;
        return false;
    }
    
    bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,
                    const char* str, int& pathLength, bool* visited)
    {
        if(str[pathLength] == '\0')
            return true;
        
        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols &&
           matrix[row*cols+col] == str[pathLength] && !visited[row*cols+col])
        {
            ++pathLength;
            visited[row*cols+col] = true; //对一个位置相邻四个位置进行遍历
            hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row + 1, col , str, pathLength, visited);
            if(!hasPath)
            {
                --pathLength;
                visited[row * cols + col] = false;   //如果为假，返回上一个字符，说明上一个字符匹配有问题
            }
        }
        return hasPath;
    }
};