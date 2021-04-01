#include <iostream>
#include <vector>
#include <algorithm>

int N;
int result;
std::vector<int> arr;


void output()
{
	std::cout << result;
}

void solution()
{
	std::sort(arr.begin(), arr.end());
	for(int i = N ; i > 0 ; --i)
		result += arr[N - i] * i;
}

void input()
{
	std::cin >> N;
	arr.resize(N);
	for (int i = 0 ; i < N ; ++i)
		std::cin >> arr[i];
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
