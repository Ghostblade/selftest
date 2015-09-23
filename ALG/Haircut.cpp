#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct A{
	const int time;
	const int id;
	int elapse;
	A(int _id, int _time) :id(_id), time(_time), elapse(_time){}
}Barber;

void swapMember(std::vector<Barber*>& ary, int i, int j){
	Barber* tmp = ary[i];
	ary[i] = ary[j];
	ary[j] = tmp;
}

void buildHeap(std::vector<Barber*>& ary, int cnt){
	cnt--;
	if (cnt - ((cnt >> 1) << 1))
	{
		int p = (cnt - 1)>>1;
		if (ary[p]->elapse > ary[cnt]->elapse){
			swapMember(ary, p, cnt);
		}
		cnt--;
	}


	for (int i = cnt; i > 0;--i)
	{
		if (i-((i>>1)<<1))
		{
			continue;
		}
		int l = i - 1;
		int p = l >> 1;

		int m = ary[i]->elapse < ary[l]->elapse ? i : l;
		if (ary[m]->elapse<ary[p]->elapse)
		{
			swapMember(ary, p, m);
		}
	}
}

void adjustDown(std::vector<Barber*>& ary, int cnt){
	int i = 0;
	ary[0]->elapse += ary[0]->time;
	while (true)
	{
		int j = -1;
		int lc = (i << 1) + 1;
		int rc = (i << 1) + 2;
		if (lc>cnt-1)
		{
			break;
		}

		if ((ary[lc]->elapse<ary[i]->elapse)
			||
			(ary[lc]->elapse == ary[i]->elapse&&
			ary[lc]->id < ary[i]->id))
		{
			j = lc;
		}

		if (rc>cnt-1)
		{
			if (j>0)
			{
				swapMember(ary, i, j);
			}
			break;
		}

		if ((ary[rc]->elapse<ary[i]->elapse)
			||
			(ary[rc]->elapse == ary[i]->elapse
			&&ary[rc]->id<ary[i]->id))
		{
			if (j>0)
			{
				if ((ary[rc]->elapse < ary[lc]->elapse)
					||
					(ary[rc]->elapse == ary[lc]->elapse&&
					ary[rc]->id < ary[lc]->id)){
					j =rc;
				}
			}
			else{
				j = rc;
			}
		}

		if (j<0)
		{
			break;
		}
		else{
			swapMember(ary, i, j);
			i = j;
		}
	}
}

int getBarber(ifstream& in){
	int barber_num, cur_pos;
	in >> barber_num;
	in >> cur_pos;
	if (cur_pos<=barber_num)
	{
		return cur_pos;
	}
	std::vector<Barber*> barber_ary(barber_num);
	for (int i = 0; i < barber_num;++i)
	{
		int time;
		in >> time;
		barber_ary[i] = new Barber(i + 1, time);
	}

	buildHeap(barber_ary, barber_num);
	int heapsize = barber_num;
	int curbarber;
	do 
	{
		curbarber = barber_ary[0]->id;
		adjustDown(barber_ary, barber_num);
		heapsize++;
	} while (heapsize<cur_pos);
	for (int i = 0; i < barber_num;++i)
	{
		delete barber_ary[i];
	}
	return curbarber;
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