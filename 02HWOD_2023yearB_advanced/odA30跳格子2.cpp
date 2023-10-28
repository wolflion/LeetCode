#include "test.h"

void od_a30() {
	string s;//2 3 2，lionel，怎么输入到vector<int>中
	getline(cin, s);
	vector<int> nums{ 2,3,2 };

	//2个dp
	vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
	dp[0][0] = nums[0];
	if (nums.size() > 1) {
		dp[0][1] = max(nums[0], nums[1]);
	}

	for (int i = 2; i < nums.size() - 1; i++) {
		dp[0][i] = max(dp[0][i - 2] + nums[i], dp[0][i - 1]);
	}

	sort(dp[0].begin(), dp[0].end());

	dp[1][0] = nums[1];
	if (nums.size() > 1) {
		dp[1][1] = max(nums[1], nums[2]);
	}

	for (int i = 3; i < nums.size(); i++) {
		dp[1][i] = max(dp[0][i - 2] + nums[i], dp[0][i - 1]);
	}

	sort(dp[1].begin(), dp[1].end());

	int res = max(dp[0][nums.size() - 1], dp[1][nums.size() - 1]);
	cout << res << endl;
}

//参考，打家劫舍2