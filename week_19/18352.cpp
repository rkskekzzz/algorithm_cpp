#include <iostream>
#include <vector>

int N, M, K, X;
std::vector<std::pair<int, int> > inp;
std::vector<std::vector<int> > map;
std::vector<int> result;
std::vector<int> visited;

void output()
{
	for(int i = 1 ; i <= N ; ++i)
		if (map[X][i] == K)
			result.push_back(i);
	if (result.size() == 0)
		std::cout << -1;
	else
		for(auto& j : result)
			std::cout << j <<  '\n';
}

int minval()
{
	int min = 99;
	int idx;
	for(int i = 1 ; i <= N ; ++i)
	{
		if (!visited[i] && min > map[X][i])
		{
			min = map[X][i];
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
		for(int j = 1 ; j <= N ; ++j)
		{
			if(!visited[j])
			{
				if(map[X][pos] + map[pos][j] < map[X][j])
					map[X][j] = map[X][pos] + map[pos][j];
			}
		}

	}
}

void init()
{
	for(auto& i : inp)
	{
		map[i.first][i.second] = 1;
	}
}

void input()
{
	std::cin >> N >> M >> K >> X;
	map = std::vector(N + 1, std::vector(N + 1, 99));
	visited = std::vector(N + 1, 0);
	inp.resize(M);
	for(auto& i : inp)
	{
		std::cin >> i.first >> i.second;
	}
	init();
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
