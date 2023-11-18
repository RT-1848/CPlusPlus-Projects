#ifndef wordEntry_H
#define wordEntry_H

#include <iostream>
#include <list>

using namespace std;

//Concordance Struct
struct wordEntry{
 string word;
 int frequency;
 int last_line;
 list<int> line_nums;

 //Key function that returns the word
 string Key() const{
	 return word;
 }
};

#endif
