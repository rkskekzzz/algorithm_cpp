#include <vector>
#include <queue>

using namespace std;
queue<int> que;
vector<int> visited;

int possible(int from, int to, vector<vector<int>> edge_list)
{
	for(auto k : edge_list)
		if ((k[0] == from && k[1] == to) || (k[0] == to && k[1] == from))
			return 1;
	return (from == to);
}

bool bfs(int start, vector<vector<int>> edge_list, vector<int> gps_log)
{
    que.push(start);

	while(!que.empty())
	{
		auto front = que.front();
		visited[front] = 1;
		que.pop();
		if (front == gps_log[gps_log.size() - 1])
			return true;
		for (auto k : edge_list)
		{
			if (k[0] == front && !visited[k[1]])
				que.push(k[1]);
			else if (k[1] == front && !visited[k[0]])
				que.push(k[0]);
		}
	}
	return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
	visited = vector(n, 0);
	if (bfs(gps_log[0], edge_list, gps_log))
		cout << "wow\n";
	for(auto i = 1 ; i < gps_log.size() ; ++i)
	{
		if (!possible(gps_log[i - 1], gps_log[i], edge_list))
		{

		}
	}

    return answer;
}
