#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> arr;
std::vector<std::string> cmp;
int N, M, result;

void output()
{
	if (arr != cmp)
		std::cout << "-1";
	else
		std::cout << result;
}

void flip(int idx, int jdx)
{
	++result;
	for (int i = idx; i < idx + 3; ++i)
	{
		for (int j = jdx; j < jdx + 3; ++j)
		{
			if (arr[i][j] == '0')
				arr[i][j] = '1';
			else
				arr[i][j] = '0';
		}
	}
}

void solution()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; j++)
		{
			if (i + 2 >= N || j + 2 >= M)
				break;
			if (arr[i][j] != cmp[i][j])
			{
				flip(i, j);
			}
		}
	}
}

void input()
{
	std::cin >> N >> M;
	arr.resize(N);
	cmp.resize(N);
	for (auto &i : arr)
		std::cin >> i;
	for (auto &i : cmp)
		std::cin >> i;
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

