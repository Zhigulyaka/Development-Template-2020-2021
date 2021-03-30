#include "text.h"

ostream& operator<<(ostream& o, const TTextNode& t)
{
	if (t.level == 3)
	{
		o<< t.c;
		if (t.next != nullptr)
			o << *(t.next);
	}
	else 
	{
		if (t.down != nullptr)
			o << *(t.down);
		if (t.next != nullptr)
			o << *(t.next);
	}
}

TTextNode::TTextNode(int l, char _c )
{
	next = nullptr;
	down = nullptr;
	c = _c;
	level = l;
}

TTextNode::TTextNode(const TTextNode& other)
{
	next = nullptr;
	down = nullptr;
	c = other.c;
	level = other.level;
}

TTextNode::~TTextNode()
{
}

TTextNode* TTextNode::GetNext()
{
	return next;
}

TTextNode* TTextNode::GetDown()
{
	return down;
}

char TTextNode::GetC()
{
	return c;
}

int TTextNode::GetLevel()
{
	return level;
}

void TTextNode::SetNext(TTextNode* _next)
{
	next = _next;
}

void TTextNode::SetDown(TTextNode* _down)
{
	down = _down;
}

void TTextNode::SetC(char _c)
{
	c = _c;
}

void TTextNode::SetLevel(int _level)
{
	if ((level <= 3) && (level >= 3))
		level = _level;
	else
		throw logic_error("invalid_value_of_level");
}
