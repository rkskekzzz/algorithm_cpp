#include <iostream>
#include <vector>


int A, B, C, x, y, result;

void output()
{
	std::cout << result;
}

void solution()
{
	result = (C * 2 < A + B)
			 ? 2 * std::min(x, y) * C + (x - std::min(x, y)) * std::min(A, 2 * C) + (y - std::min(x, y)) * std::min(B, 2 * C) \
			 : result = x * A + y * B;

}

void input()
{
	std::cin >> A >> B >> C >> x >> y;
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
