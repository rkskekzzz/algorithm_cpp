#include <iostream>
#include <vector>
// 왜틀렸징 ㅜㅜ
int wid, hei, result;
std::vector<std::vector<int> > paper;

void output()
{
	std::cout << result;
}

void solution()
{
	int und, fnb, lnr;

	und = fnb = lnr = 0;

	// up & down
	und = wid * hei * 2;

	// fnb & back
	for(int i = 1 ; i <= wid ; ++i)
		for(int j = 1 ; j <= hei + 1 ; ++j)
			fnb += std::abs(paper[j][i] - paper[j - 1][i]);
	//left & right
	for(int i = 1 ; i <= hei ; ++i)
		for(int j = 1 ; j <= wid + 1 ; ++j)
			lnr += std::abs(paper[i][j] - paper[i][j - 1]);
	result = und + fnb + lnr;
	// std::cout << "all : " << und + fnb + lnr << std::endl;
}

void input()
{
	std::cin >> wid >> hei;
	paper = std::vector(hei + 2, std::vector(wid + 2, 0));
	for(int i = 1 ; i <= hei ; ++i)
		for(int j = 1 ; j <= wid ; ++j)
			std::cin >> paper[i][j];
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

int main()
{
	preset();
	input();
	solution();
	output();
}
