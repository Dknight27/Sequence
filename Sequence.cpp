#include<iostream>
#include"Sequence.h"
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;
char dna[1200000];
char* start;
char* coor[1200000];
Sequence::Sequence(string filename)
{
	char* ch;
	ifstream fin;
	fin.open(filename);
	if (!fin)
	{
		cerr << "There is something wrong." << endl;
	}
	start = dna;
	ch = dna;
	while (!fin.eof())
	{
		fin >> ch;
		ch += 100;
	};
	for (int i = 0; start[i] != '\0'; i++)
		coor[i] = &dna[i];
	*(start+strlen(dna)) = '\0';
	fin.close();
}

int Sequence::length()
{
	return strlen(start);
}

int Sequence::numberOf(char base)
{
	int count = 0;
	for (int i = 0; start[i] != '\0'; i++)
	{
		if (start[i] == base)
			count++;
	}
	return count;
}

string Sequence::longestConsecutive()
{
	string pre;
	string longest;
	char base = 'A';
	int count_pre = 0;
	int count_longest = 0;
	for (int i = 0; start[i + 1] != '\0'; i++)
	{
		count_pre = 0;
		base = start[i];
		if (dna[i] == dna[i + count_longest - 1])
		{
			for (int j = i;; j++)
			{
				if (start[j + 1] == start[j])
				{
					count_pre++;
				}
				else
				{
					i = j; break;
				}
			}
			if (count_pre>count_longest)
			{
				count_longest = count_pre;
				longest = pre;
				for (int m = 0; m <= count_longest; m++)
					longest += base;
			}
		}
	}
	return longest;
}

int commonlen(char *p, char *q)
{
	int i = 0;
	while (*p && (*p++ == *q++))
	{
		++i;
	}
	return i;
}

int pstrcmp(const void *p1, const void *p2)
{
	return strcmp(*(char* const *)p1, *(char* const*)p2);
}

string Sequence::longestRepeated()
{
	int len = strlen(dna);
	int n = 0;
	int l;
	int count_longest = 0;
	int index = 0;

	qsort(coor, len, sizeof(char*), pstrcmp);
	for (int i = 0; i<len - 1; i++)
	{
		l = commonlen(coor[i], coor[i + 1]);
		if (l>count_longest)
		{
			count_longest = l;
			index = i;
		}
	}

	char *longestre = new char[count_longest + 1];
	longestre = coor[index];
	longestre[count_longest+1] = '\0';
	return longestre;
}
