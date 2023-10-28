#include "test.h"

extern void dfs(vector<int> nums, int direction, int level, int i, int target, vector<int> &path, vector<bool> &visitied);
int min1 = INT32_MAX; 
vector<int> res(3);

void od54() {
	// 5,3 
	// 1 2 6
	//���6 2 1  ��1��2 6��6��2��1���ǣ����ȴ����ֵ��6��2��1��

	//���͵Ļ��ݣ�(lionel������ô�����������ͣ�

	
	
	int target=5, n=3;
	//cin >> target >> n;
	//1 2 6 ��ôд��vector��
	int tmp;
	vector<int> nums{1,2,6};
#if 0
	//��ʵ������while��������n--�ķ�ʽ
	while (cin >> tmp) {
		nums.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}
#endif

	//����ֵ����������
	sort(nums.begin(), nums.end(), greater<int>());
	vector<int> path(n,0);
	vector<bool>visited(100,false);  //lionel���Ǵ��ˣ�ǰ����������������ǳ�ʼ����ֵ

	dfs(nums, 1, 0, 0, target, path, visited);

	if (!res.empty()) {   //lionel��Ϊɶ����ط���6��
		string s = to_string(res[0]);
		for (int i = 1; i < res.size(); i++){
			s += ",";
			s += to_string(res[i]);
		}
		cout << s << endl;
	}
}

/*
* ��������
* ���ϻ�����
* Ŀǰ����¥��
* �ڼ���¥���ƶ�
* Ŀ��¥��
* ��¥�����¹����еļ�¼
* ��¼��Щ�ƶ�¥�������Ѿ���ʹ��
*/
void dfs(vector<int> nums, int direction, int level, int i, int target, vector<int> &path, vector<bool> &visitied) {
	//ʹ�������д���
	if(i==nums.size()){
		//����¥�㣬����С�ڸ�¥�����
		if (target - level >= 0 && target - level < min1) {
			min1 = target - level;
			res = path;
		}
		return;
	}

	//�������У�
	for (int j = 0; j < nums.size(); j++) {
		if (!visitied[j]) {
			visitied[j] = true;
			path.push_back(nums[j]);
			//�ϻ�����
			if (direction == 1) {
				dfs(nums, 0, level + nums[j], i + 1, target, path, visitied);
			}else {
				//�µĻ�����Ҫ��
				dfs(nums, 1, level - nums[j], i + 1, target, path, visitied);
			}
			//����
			path.pop_back();//ɾ��Ԫ��  https://blog.csdn.net/qq_39451578/article/details/115015639
			visitied[j] = false;
		}
	}
}


//https://blog.csdn.net/wj_phm/article/details/132826106