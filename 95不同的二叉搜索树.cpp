class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTreesHelper(1, n);
    }

private:
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> result;
        //如果开始下标小于结束下标，那么证明这个地方没有元素，则是一个空，将NULL入队然后返回
        if (start > end) {
            result.push_back(NULL);
            return result;
        }
        //对于在start—end之间的数字，都有机会做树根；
        for (int i = start; i <= end; ++i) {
            //生成v[i]左边的所有左子树的树根
            vector<TreeNode*> leftSubtrees = generateTreesHelper(start, i - 1);
            //生成v[i]右边的所有可能的右子树的树根的向量
            vector<TreeNode*> rightSubtrees = generateTreesHelper(i + 1, end);
            //通过两层循环，将所有的左子树与右子树自由组合，形成所有的树，插入到result中
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
