#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int getBarber(ifstream& in){
	int barber_cnt, queue_pos;
	in >> barber_cnt >> queue_pos;
	vector<int> barber_time(barber_cnt);
	for (int i = 0; i < barber_cnt;++i)
	{
		in >> barber_time[i];
	}

	//use a bisearch scheme to fine the ceil sum

	//*****attention should be paied here use ull
	unsigned long long r = 1e18, l = 0, mid=0, cursum=0;
	while (l<r)
	{
		mid = (l + r) >> 1;
		unsigned long long sum = 0;
		for (int i = 0; i < barber_cnt;++i)
		{
			sum += mid / barber_time[i] + 1;
		}
		if (sum<queue_pos)
		{
			l = mid+1;
		}
		else{
			r = mid;
		}
	}

	std::vector<int> cur_workingbarber;
	for (int i = 0; i < barber_cnt;++i)
	{
		cursum += r / barber_time[i] + 1;
		if (r%barber_time[i]==0)
		{
			cur_workingbarber.push_back(i);
		}
	}

	return cur_workingbarber[cur_workingbarber.size() - 1 - (cursum - queue_pos)] + 1;

}


int main(){
	ifstream in;
	in.open("in.in");

	ofstream out;
	out.open("out.txt");

	int testcase;
	in >> testcase;
	for (int i = 0; i < testcase;++i)
	{
		out << "Case #" << i + 1 <<": "<<getBarber(in) << "\n";
	}

	in.close();
	out.close();
}


