#include <iostream>
#include <vector>
#include <queue>

int N, M, _max;
std::vector<std::vector<int> > map;
std::vector<std::vector<int> > visited;
std::vector<std::pair<int, int> > dir = {{-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}};
std::queue<std::pair<int, int> > que;

void output()
{
	std::cout << _max;
}

int bfs(int i, int j)
{
	que.push({i, j});
	visited[i][j] = 1;
	while(!que.empty())
	{
		auto front = que.front();
		que.pop();
		// std::cout << front.first << ", " << front.second << ", map : " <<map[front.first][front.second]<<std::endl;
		if (map[front.first][front.second] == 1)
			return visited[front.first][front.second] - 1;
		for(auto& d : dir)
		{
			if(front.first + d.first < 0 || front.first + d.first >= N || front.second + d.second < 0 || front.second + d.second >= M || visited[front.first + d.first][front.second + d.second])
				continue;
			que.push({front.first + d.first, front.second + d.second});
			visited[front.first + d.first][front.second + d.second] = visited[front.first][front.second] + 1;
		}
	}
	return 0;
}

void solution()
{
	for(auto i = 0 ; i < N ; ++i)
		for(auto j = 0 ; j < M ; ++j)
		{
			// std::cout << "----------------------------------------\n";
			// std::cout << "start : " << i << ", " << j << std::endl;
			visited = std::vector(N, std::vector(M, 0));
			que = std::queue<std::pair<int, int> >();
			_max = std::max(_max, bfs(i, j));
		}
}

void input()
{
	std::cin >> N >> M;
	map = std::vector(N, std::vector(M, 0));
	for(auto& i : map)
		for(auto& j : i)
		{
			std::cin >> j;
		}
	// std::cout << "----------------------------------------\n";
	// for(auto i = 0 ; i < N ; ++i)
	// {
	// 	for (auto j = 0; j < M; ++j)
	// 	{
	// 		std::cout << map[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
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
	solution();
	output();
}
