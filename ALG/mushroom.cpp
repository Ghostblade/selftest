#include <iostream>
#include <stdlib.h>
#include <vector>

#include <fstream>

#define max2(a,b)    (((a) > (b)) ? (a) : (b))
#define min2(a,b)    (((a) < (b)) ? (a) : (b))

using namespace std;

void getEatenNum(int &method1, int &method2, ifstream& file){
	int seq;
	//cin >> seq;
	file >> seq;
	int last;
	//cin >> last;
	file >> last;
	int curmax=-100000;
	vector<unsigned int> tmp;
	for (int i = 1; i < seq;++i)
	{
		int cur;
		//cin >> cur;
		file >> cur;
		int cureaten = last - cur;
		method1 += max2(cureaten,0);
		curmax = max2(curmax, cureaten);

		tmp.push_back(last);
		last = cur;
	}

	for (int i = 0; i < seq - 1;++i)
	{
		method2 += min2(curmax, tmp[i]);
	}
}

int main(){
	ifstream testfile;
	testfile.open("A-large-practice.in");


	int testcase;
	
	testfile >> testcase;
	//cin >> testcase;


	ofstream sout;
	sout.open("a.out");

	for (int i = 0; i < testcase;++i)
	{
		int method1=0, method2=0;
		getEatenNum(method1, method2, testfile);
		sout << "Case #" << i + 1 << ": " << method1 << " " << method2 << "\n";
	}
	sout.close();
	testfile.close();
// 	system("PAUSE");
	return 0;
}