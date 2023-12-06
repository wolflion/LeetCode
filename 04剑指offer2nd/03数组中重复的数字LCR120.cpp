/*
设备中存有 n 个文件，文件 id 记于数组 documents。若文件 id 相同，则定义为该文件存在副本。请返回任一存在副本的文件 id。

 

示例 1：

输入：documents = [2, 5, 3, 0, 5, 0]
输出：0 或 5
*/

//2023-12-01，参考了LC03的题解，主要还是unordered_set<>用法不太熟悉

class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        unordered_set<int> lookup;
        for(int i=0;i<documents.size();i++){
            while(lookup.find(documents[i]) != lookup.end()){
                return documents[i];
            }
            lookup.insert(documents[i]);
        }
        return 0;
    }
};

