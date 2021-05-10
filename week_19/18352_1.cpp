#include <iostream>
#include <vector>
#include <algorithm>

int N, M, K, X;
std::vector<std::vector<std::pair<int, int> > > map;
std::vector<int> line;
std::vector<int> result;
std::vector<int> visited;

void output()
{
	for(int i = 1 ; i <= N ; ++i)
		if (line[i] == K)
			result.push_back(i);
	if (result.size() == 0)
		std::cout << -1;
	else
	{
		std::sort(result.begin(), result.end());
		for(auto& j : result)
			std::cout << j <<  '\n';
	}
}

int minval()
{
	int min = 99;
	int idx = 0;
	for(int i = 1 ; i <= N ; ++i)
	{
		if (!visited[i] && min > line[i])
		{
			min = line[i];
			idx = i;
		}
	}
	return idx;
}

void solution()
{
	for(int i = 0 ; i < N - 2 ; ++i)
	{
		int pos = minval();
		visited[pos] = 1;
		for(auto& j : map[pos])
		{
			if(!visited[j.first])
			{
				if(line[pos] + j.second < line[j.first])
					line[j.first] = j.second + line[pos];
			}
		}

	}
}

void init(int from, int to)
{
	map[from].push_back({to, 1});
}

void input()
{
	std::cin >> N >> M >> K >> X;
	int from, to;
	map.resize(N + 1);
	visited = std::vector(N + 1, 0);
	line = std::vector(N + 1, 99);
	for(int i = 0 ; i < M ; ++i)
	{
		std::cin >> from >> to;
		init(from, to);
	}

	for(auto& i : map[X])
		line[i.first] = i.second;
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
