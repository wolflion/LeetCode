#include "test.h"

void od_a05() {
	int N, T;
	cin >> N >> T;
	//�ڵ�֮�以ͨ
	int u, v;
	map<int, set<int>>mp;  //����ߵĹ�ϵ��lionel������Ҳ�̫��Ϥ
	for (int i = 0; i < T; i++) {
		cin >> u >> v;
		mp[u].insert(v);
		mp[v].insert(u);  //lionel������ɶ��˼�����ֽڵ㻥ͨ��   ����¼����ǰ�ڵ㣬���ڽӽڵ㣬��Ϊ�ڽӵĹ�ϵ��
	}

	int start;
	cin >> start;

	queue<int>q;
	set<int> visited;   //lionel��Ϊɶ��set��
	int layer = 0; //����

	q.push(start);
	visited.insert(start);

	//lionel������������
	while(visited.size()<N){
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int cur = q.front();
			q.pop();

			for (auto val : mp[cur]) {
				if (0 == visited.count(val)) {
					q.push(val);
					visited.insert(val);
				}
			}
		}
		++layer;
	}

	cout << layer * 2 << endl;

#if 0
	//lionel�����������һ��
	vector<int> d(N+1);
	//dijkstra������
	while (!q.empty()) {
		//ÿ��ȡ����Ľڵ�
		int node = q.front();
		for (auto n : mp[node]) {
			if (!visited.find(n)) {
				visited.add(n);
				d[n] = d[node] + 1;
				q.push(n);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < N + 1; i++) {
		res = max(res, d[i]);
	}
	cout << res * 2 << endl;
#endif
}

//lionel����Щdijstra�õ�Ҳ��bfs

//https://blog.csdn.net/tomren/article/details/128672582?spm=1001.2014.3001.5502

//����ߵĹ�ϵ��û��

//https://blog.csdn.net/wj_phm/article/details/132549651  ��������ԣ������������Ŀǰ�õ���BFS������dijkstra��