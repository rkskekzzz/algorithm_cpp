#include <string>
#include <vector>
#include <queue>
#include <cstring>

std::queue<std::pair<int, int> >q;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int visited[5][5];

bool bfs(int k, int y, int x, std::vector<std::vector<std::string> >& place)
{
	int qy, qx, ny, nx;

	std::memset(visited, 0, sizeof(visited));
	q = std::queue<std::pair<int, int> >();
	q.push({y, x});
	visited[y][x] = 1;
	while (!q.empty())
	{
		qy = q.front().first;
		qx = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny <0 || ny >= 5 || nx < 0 || nx >= 5 || visited[ny][nx] || place[k][ny][nx] == 'X')
				continue;
			if (visited[qy][qx] == 3)
				continue;
			visited[ny][nx] = visited[qy][qx] + 1;
			if (place[k][ny][nx] == 'P')
				return (1);
			q.push({ny, nx});
		}
	}
	return (0);
}

std::vector<int> solution(std::vector<std::vector<std::string>> places)
{
	std::vector<int> answer;
	bool fl;

	for (size_t i = 0 ; i < places.size(); i++)
	{
		fl = 1;
		for(size_t j = 0 ; fl && j < places[i].size() ; j++)
			for (size_t k = 0 ; k < places[i][j].size() ; k++)
				if (places[i][j][k] == 'P' && bfs(i, j, k, places))
				{
					fl = 0;
					break;
				}
		if (fl)
			answer.push_back(1);
		else
			answer.push_back(0);
	}
	return answer;
}