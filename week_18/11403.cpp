#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> graph;

void output()
{
	for (auto &i : graph)
	{
		for (auto &j : i)
			std::cout << j << " ";
		std::cout << '\n';
	}
}

void solution()
{
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if ((graph[i][k] && graph[k][j]) || graph[i][j])
					graph[i][j] = 1;
}

void input()
{
	std::cin >> N;
	graph = std::vector(N, std::vector(N, 0));
	for (auto &i : graph)
		for (auto &j : i)
			std::cin >> j;
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
