#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
	return a[2] < b[2];
}

int rec(vector<int> node, int i)
{
	if (node[i] == i)
		return (i);
	return (rec(node, node[i]));
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
	int cnt = 0;
	vector<int> node;

	node.resize(n);
	for(size_t i = 0 ; i < node.size() ; ++i)
		node[i] = i;
    sort(costs.begin(), costs.end(), comp);
	for (size_t i = 0 ; i < costs.size() ; ++i)
	{
		if (rec(node, costs[i][0]) != rec(node, costs[i][1]))
		{
			answer += costs[i][2];
			// if (costs[i][0] > costs[i][1]) {
			// 	swap(costs[i][0], costs[i][1]);
			// }
			int n1_top,n2_top;
			n1_top = rec(node, costs[i][0]);
			n2_top = rec(node, costs[i][1]);
			int s = (n1_top > n2_top) ? n2_top : n1_top;
			node[costs[i][0]] = s;
			node[costs[i][1]] = s;
			node[n1_top] = s;
			node[n2_top] = s;
			++cnt;
		}
		if (cnt == n - 1)
			break ;
	}

    return answer;
}
