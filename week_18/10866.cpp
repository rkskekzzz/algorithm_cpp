#include <iostream>
#include <vector>
#include <deque>
#include <string>

int N;
std::deque<int> deq;
std::vector<int> res;

void output()
{
	for(auto& i : res)
		std::cout << i << '\n';
}

void solution()
{
	std::string str;
	int n;

	std::cin >> N;
	while(N--)
	{
		std::cin >> str;
		if (str == "push_front")
		{
			std::cin >> n;
			deq.push_front(n);
		}
		else if (str =="push_back")	{
			std::cin >> (n);
			deq.push_back(n);
		}
		else if ((str == "front" || str =="pop_front") && !deq.empty()){
			res.push_back(deq.front());
			if (str == "pop_front")
				deq.pop_front();
		}
		else if ((str == "back" || str =="pop_back") && !deq.empty()){
			res.push_back(deq.back());
			if (str== "pop_back")
				deq.pop_back();
		}
		else if (str =="size"){
			res.push_back(deq.size());
		}
		else if (str =="empty"){
			if (deq.empty())
				res.push_back(1);
			else
				res.push_back(0);
		}
		else
			res.push_back(-1);
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
	solution();
	output();
}
