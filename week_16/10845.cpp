#include <iostream>
#include <queue>
#include <string>

int N;
std::string s;
std::queue<int> que;
std::vector<int> result;

// push X: 정수 X를 큐에 넣는 연산이다.
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 큐에 들어있는 정수의 개수를 출력한다.
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에
// 1
// 2
// 2
// 0
// 1
// 2
// -1
// 0
// 1
// -1
// 0
// 3

// push, pop, size, empty, front, back
void output()
{
	for (auto &i : result)
		std::cout << i << '\n';
}

void solution()
{
	int num;

	if (s == "push")
	{
		std::cin >> num;
		que.push(num);
	}
	else if (s == "pop")
	{
		if(que.empty())
		{
			result.push_back(-1);
		}
		else
		{
			result.push_back(que.front());
			que.pop();
		}
	}
	else if (s == "size")
		result.push_back(que.size());
	else if (s == "empty")
	{
		if (que.empty())
			result.push_back(1);
		else
			result.push_back(0);
	}
	else if (s == "front")
	{
		if (que.empty())
			result.push_back(-1);
		else
			result.push_back(que.front());
	}
	else
	{
		if (que.empty())
			result.push_back(-1);
		else
			result.push_back(que.back());
	}

}

void input()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> s;
		solution();
	}
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
	output();
}
