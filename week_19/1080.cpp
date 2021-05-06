#include <iostream>
#include <vector>

std::vector<std::vector<int>> arr;
std::vector<std::vector<int>> cmp;
int N, M, result;

void output()
{
	std::cout << result;
}

void flip(int idx, int jdx)
{
	++result;
	for (int i = idx; i < idx + 3; ++i)
	{
		for (int j = jdx; j < jdx + 3; ++j)
		{
			if (i >= N || j >= M)
				continue;
			arr[i][j] = !arr[i][j];
		}
	}
}

void solution()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] != cmp[i][j])
			{
				std::cout << arr[i][j] << ", " << cmp[i][j]<< std::endl;
				flip(i, j);
			}
		}
	}
}

void input()
{
	std::cin >> N >> M;
	std::cout <<"hello\n";
	arr = std::vector(N, std::vector(M, 0));
	cmp = std::vector(N, std::vector(M, 0));
	for (auto &i : arr)
		for (auto &j : i)
			std::cin >> j;
	for (auto &i : cmp)
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
	std::cout << "hello\n";
	solution();
	output();
}
