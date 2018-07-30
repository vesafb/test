#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
    * @param S: a String consists of a and b
    * @return: the longest of the longest string that meets the condition
    */
    int getAns(string &S) {
        // Write your code here
        if (S.find('A') == string::npos || S.find('B') == string::npos || S.empty())
            return 0;
        int len = S.size();
        int maxLen = 0;
        vector<int> vec(len);//存放当前A和B数目的差值
        unordered_map<int, int> m;//存放数目差值及其最大位置
        int temp = 0;
        for (int i = 0; i < len; ++i)
        {
            if (S[i] == 'A')
                temp--;
            else
                temp++;
            vec[i] = temp;
            m[temp] = i;
        }
        //寻找数目差为0的区域
        cout << endl;
        for (int i = 0; i < len; ++i)
        {
            if (vec[i] != 0)
            {
                maxLen = maxLen >= m[vec[i]] - i ? maxLen : m[vec[i]] - i;
                cout << maxLen << " ";
            }
        }
        cout << endl;
        //为0返回最大位置+1
        if (m.find(0) != m.end())
        {
            if (m[0] + 1 > maxLen)
                maxLen = m[0] + 1;
        }
        return maxLen;
    }
};

int main() {
  string s("ABABAAABBB");
  Solution sl;
  cout << sl.getAns(s) << endl;
}
