#include<iostream>
#include"Sequence.h"
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
char dna[1200000];
char* start;
char* ch;
Sequence::Sequence(string filename)
{
    ifstream fin;
    fin.open(filename);
	if(!fin)
	{
		cerr<<"There is something wrong."<<endl;
	}
	cout<<"First"<<endl;
	start=dna;
	ch=dna;
    while(fin>>ch)
	{
		ch+=100;
	};
}

int Sequence::length()
{
    return strlen(start);
}

int Sequence::numberOf(char base)
{
    int count=0;
    for(int i=0;start[i]!='\0';i++)
    {
        if(start[i]==base)
            count++;
    }
    return count;
}

string Sequence::longestConsecutive()
{
    string pre;
    string longest;
	char base='A';
    int count_pre=0;
    int count_longest=0;
    for(int i=0;start[i+1]!='\0';i++)
    {
        count_pre=0;
        base=start[i];
		if(start[i]==start[i+count_longest-1])
		{
        for(int j=i;;j++)
        {
            if(start[j+1]==start[j])
            {
                count_pre++;
            }
            else
            {
                i=j;break;
		    }
        }
        if(count_pre>count_longest)
        {
            count_longest=count_pre;
            longest=pre;
			for(int m=0;m<=count_longest;m++)
				longest+=base;
		}
		}
    }
    return longest;
}

string Sequence::longestRepeated()
{
    string pre;
    string longest;
    int count_pre=0;
    int count_longest=0;
    for(int i=0;start[i+1]!='\0';i++)
    {
        int k=i+1;
        while(start[k]!=start[i]){k++;}
        for(int j=k;;j++)
        {
            pre[0]=start[j];
            int count_pre=1;
            if(start[j+count_pre]==start[i+count_pre])
            {
                count_pre;
                pre[count_pre]=start[j+count_pre];
            }
            else
            {
                i+=count_pre;break;
            }
        }
        if(count_pre>count_longest)
        {
            count_longest=count_pre;
            longest=pre;
        }
    }
    return longest;
}

