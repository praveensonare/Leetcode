#include "Header.h"

vector<vector<int>> verticalOrder(TreeNode* root) {

    if (!root) return {};

     map<int, vector<int>> M;
        queue<pair<int, TreeNode*>> Q;
        Q.push(pair<int, TreeNode*>(0, root));

        pair<int, TreeNode*> front;
        while(!Q.empty())
        {
            front = Q.front();
            M[front.first].emplace_back(front.second->val);

            if (front.second->left)
            {
                Q.push(pair<int, TreeNode*>(front.first - 1, front.second->left));
            }
            if (front.second->right)
            {
                Q.push(pair<int, TreeNode*>(front.first + 1, front.second->right));
            }

            Q.pop();
        }

        vector<vector<int>> result;
        for (auto v : M)
        {
            result.emplace_back(v.second);
        }
        return result;

    }
