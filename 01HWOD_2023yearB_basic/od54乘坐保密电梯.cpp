#include "test.h"

extern void dfs(vector<int> nums, int direction, int level, int i, int target, vector<int> &path, vector<bool> &visitied);
int min1 = INT32_MAX; 
vector<int> res(3);

void od54() {
	// 5,3 
	// 1 2 6
	//输出6 2 1  【1，2 6和6，2，1都是，按先处理大值，6，2，1】

	//典型的回溯，(lionel，我怎么看不出来典型）

	
	
	int target=5, n=3;
	//cin >> target >> n;
	//1 2 6 怎么写到vector中
	int tmp;
	vector<int> nums{1,2,6};
#if 0
	//其实可以在while（）里用n--的方式
	while (cin >> tmp) {
		nums.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}
#endif

	//按大值处理，先排序
	sort(nums.begin(), nums.end(), greater<int>());
	vector<int> path(n,0);
	vector<bool>visited(100,false);  //lionel，记错了，前面是数量，后面才是初始化的值

	dfs(nums, 1, 0, 0, target, path, visited);

	if (!res.empty()) {   //lionel，为啥这个地方是6呢
		string s = to_string(res[0]);
		for (int i = 1; i < res.size(); i++){
			s += ",";
			s += to_string(res[i]);
		}
		cout << s << endl;
	}
}

/*
* 数组序列
* 向上还是下
* 目前所在楼层
* 第几次楼层移动
* 目标楼层
* 在楼层上下过程中的记录
* 记录哪些移动楼层数字已经被使用
*/
void dfs(vector<int> nums, int direction, int level, int i, int target, vector<int> &path, vector<bool> &visitied) {
	//使用完所有次数
	if(i==nums.size()){
		//到达楼层，或者小于该楼层最近
		if (target - level >= 0 && target - level < min1) {
			min1 = target - level;
			res = path;
		}
		return;
	}

	//遍历序列，
	for (int j = 0; j < nums.size(); j++) {
		if (!visitied[j]) {
			visitied[j] = true;
			path.push_back(nums[j]);
			//上还是下
			if (direction == 1) {
				dfs(nums, 0, level + nums[j], i + 1, target, path, visitied);
			}else {
				//下的话，就要减
				dfs(nums, 1, level - nums[j], i + 1, target, path, visitied);
			}
			//回溯
			path.pop_back();//删除元素  https://blog.csdn.net/qq_39451578/article/details/115015639
			visitied[j] = false;
		}
	}
}


//https://blog.csdn.net/wj_phm/article/details/132826106