#include "test.h"

void od_a05() {
	int N, T;
	cin >> N >> T;
	//节点之间互通
	int u, v;
	map<int, set<int>>mp;  //边与边的关系，lionel，这个我不太熟悉
	for (int i = 0; i < T; i++) {
		cin >> u >> v;
		mp[u].insert(v);
		mp[v].insert(u);  //lionel，这是啥意思，保持节点互通？   【记录，当前节点，与邻接节点，互为邻接的关系】
	}

	int start;
	cin >> start;

	queue<int>q;
	set<int> visited;   //lionel，为啥用set？
	int layer = 0; //层数

	q.push(start);
	visited.insert(start);

	//lionel，差别在这儿？
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
	//lionel，这个再消化一下
	vector<int> d(N+1);
	//dijkstra的做法
	while (!q.empty()) {
		//每次取最近的节点
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

//lionel，有些dijstra用的也是bfs

//https://blog.csdn.net/tomren/article/details/128672582?spm=1001.2014.3001.5502

//边与边的关系，没懂

//https://blog.csdn.net/wj_phm/article/details/132549651  【如果可以，把这个看懂，目前用的是BFS，不是dijkstra】