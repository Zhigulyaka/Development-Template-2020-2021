#pragma once

#ifndef INCLUDE_TEXT_H_
#define INCLUDE_TEXT_H_
#include <iostream>
using namespace std;

class TTextNode
{
protected:
	TTextNode* next;
	TTextNode* down;
	char c;
	int level; //0-�����, 1-������, 2-�����, 3-�����
public:
	TTextNode(int l=3, char _�=0);
	TTextNode(const TTextNode& other);
	~TTextNode();

	TTextNode* GetNext();
	TTextNode* GetDown();
	char GetC();
	int GetLevel();

	void SetNext(TTextNode* _next);
	void SetDown(TTextNode* _down);
	void SetC(char _c);
	void SetLevel(int _level);

	friend ostream& operator << (ostream & o, const TTextNode & t);
};
#endif  