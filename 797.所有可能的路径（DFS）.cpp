class Solution {
public:
    vector<vector<int>>result;
    //储存的答案
    vector<int>path;
    //存储的路径
    void DFS(vector<vector<int>>& graph, int vertex) {//进行深度优先遍历的函数
        /*
        graph——存的图
        vertex——当前访问的节点！！！！
        */
        if (vertex == graph.size() - 1) {//递归条件，如果当你当前遍历的节点是最后一个节点，遍历完成，跳出递归
            result.push_back(path);//路径收录
            return;
        }
        for (int i = 0; i < graph[vertex].size(); i++) {//依次深度优先遍历当前节点的所有邻接节点
            path.push_back(graph[vertex][i]);//这个节点是深度优先搜索到的，所以是路径上的一个节点
            DFS(graph, graph[vertex][i]);//对于这个节点进行搜索
            path.pop_back();//剪枝，***非常重要，遍历这个节点完之后一定要剪枝！！！！真的是太奇妙的想法了！！！！
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        DFS(graph, 0);
        return result;
    }
};
