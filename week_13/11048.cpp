// 9251 번

#include <algorithm>
#include <iostream>
#include <vector>


int N;
int M;
std::vector<std::vector<int> > arr;


void output()
{
	std::cout << arr[N][M];
}

void solution()
{
	for (int i = 1; i <= N ; i++)
		for (int j =  1; j <= M ; j++)
			arr[i][j] += std::max({arr[i - 1][j], arr[i - 1][j - 1], arr[i][j - 1]});
}

void input()
{
	std::cin >> N >> M;
	arr = std::vector(N + 1, std::vector(M + 1, 0));
	for (int i = 1; i <= N ; i++)
		for (int j =  1; j <= M ; j++)
			std::cin >> arr[i][j];
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main(void)
{
	preset();
	input();
	solution();
	output();
}
