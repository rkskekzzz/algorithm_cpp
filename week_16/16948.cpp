#include <iostream>
#include <vector>
#include <queue>

int N;
int pos[4];
std::queue<std::pair<int, int> > que;
std::vector<std::vector<int> > visited;
std::vector<std::pair<int, int> > mov = {{-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1}};

void output()
{
	std::cout << visited[pos[2]][pos[3]] - 1;
}

void bfs()
{
	que.push({pos[0], pos[1]});
	visited[pos[0]][pos[1]] = 1;
	while(!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		if (x == pos[2] && y == pos[3])
			break;
		for (auto& i : mov)
		{
			int _x = x + i.first;
			int _y = y + i.second;
			if (_x >= 0 &&  _y >= 0 && _x < N && _y < N && !visited[_x][_y])
			{
				visited[_x][_y] = visited[x][y] + 1;
				que.push({_x, _y});
			}
		}
	}
}

void input()
{
	std::cin >> N;
	for(auto& i : pos)
		std::cin >> i;
	visited = std::vector(N, std::vector(N, 0));
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main()
{
	preset();
	input();
	bfs();
	output();
}
