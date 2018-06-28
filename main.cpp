#include"Sequence.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    string filename="dna.txt";
    Sequence test(filename);
    cout<<"Length:"<<test.length()<<endl;
    cout<<"Number of:"<<test.numberOf('A')<<endl;
	cout<<"Number of:"<<test.numberOf('C')<<endl;
	cout<<"Number of:"<<test.numberOf('G')<<endl;
	cout<<"Number of:"<<test.numberOf('T')<<endl;
    cout<<"LongestConsecutive:"<<test.longestConsecutive()<<endl;
    cout<<test.longestRepeated()<<endl;
}

