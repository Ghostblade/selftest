#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct A{
	int time;
	int id;
}Barber;

int getBarber(){

}


int main(){
	ifstream in;
	in.open("in.txt");

	ofstream out;
	out.open("out.txt");

	int testcase;
	in >> testcase;
	for (int i = 0; i < testcase;++i)
	{
		out << "Case #" << i + 1 <<": "<<getBarber() << "\n";
	}

	in.close();
	out.close();
}