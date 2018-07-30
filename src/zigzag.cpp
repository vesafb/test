#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> v;
        queue<TreeNode*> Q;
        int j = 0;
        if (root == NULL)
            return v;
        Q.push(root);
        while (!Q.empty())
        {
            int size = Q.size();            
            vector<int> val;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* head = Q.front();
                Q.pop();
                val.push_back(head->val);
                if (j % 2 != 0)
                {
                    if (head->left != NULL)
                        Q.push(head->left);
                    if (head->right != NULL)
                        Q.push(head->right);
                }
                else
                {
                    if (head->right != NULL)
                        Q.push(head->right);
                    if (head->left != NULL)
                        Q.push(head->left);
                }

            }
            ++j;
            v.push_back(val);
        }
        return v;
    }
};

int main() {
  TreeNode a(9), b(3), c(2), d(5), e(10);
  a.left = b;
  a.right = c;
  b.left = d;
  b.right = e;
}
