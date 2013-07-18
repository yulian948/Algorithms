#include <iostream>

using namespace std;

class Floyd
{
	unsigned int number;
	unsigned int **routes;
	int **distances;
	int min(int a,int b);
public:
	Floyd();
	Floyd(int n);
	~Floyd();
	Floyd(Floyd &f);
	void setNumber(int n);
	void input();
	//void fileInput(char* path);
	void solve();
	void output();
};