#include <iostream>
#include <queue>
#include <vector>
#include <string>
int arr[301][301];
std::string dx, dy;
int N, M, R;
inline void output()
{
	for (int i = 0 ; i < N ; ++i)
	{
		for (int j = 0 ; j < M ; ++j)
			std::cout << arr[i][j] << " ";
		std::cout << '\n';
	}
}
void rotate(int x, int y, int n, int m)
{
	int tmp[1201];
	if (n < 2 || m < 2)
		return;
	int _x = x, _y = y;
	int size = (n + m - 2) * 2;
	int mv;
	for (int i = 0 ; i < size ; ++i)
	{
		tmp[i] = arr[_x][_y];
		mv = ((i % (n + m - 2) > (m - 2)) + 2 * (i / (n + m - 2)));
		_x += dx[mv] - '1';
		_y += dy[mv] - '1';
	}
	_x = x, _y = y;
	for(int i = 0 ; i < size ; ++i)
	{
		arr[_x][_y] = tmp[(i + R) % size];
		mv = ((i % (n + m - 2) > (m - 2)) + 2 * (i / (n + m - 2)));
		_x += dx[mv] - '1';
		_y += dy[mv] - '1';
	}
	rotate(x + 1, y + 1, n - 2, m - 2);
}
inline void input()
{
	std::cin >> N >> M >> R;
	for (int i = 0 ; i < N ; ++i)
		for (int j = 0 ; j < M ; ++j)
			std::cin >> arr[i][j];
	dx = "1210";
	dy = "2101";
}
inline void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}
int main()
{
	preset();
	input();
	rotate(0,0,N,M);
	output();
}
