#include <stdio.h>
#include "list.h"
#include <locale>
void main() {
  setlocale(LC_ALL, "Russian");
  int n = 0;
  int el = 0;
  bool c;
  List<int> l;
  while (1)
  {
  cout << "������� ���������� ��������� � ������: ";
  cin >> n;
  if (n <= 0)
  {
	  cout << endl << "����������� ��������� �����. ���������� ��� ���" << endl;
	  continue;
  }
  cout << endl << "������� �������� ������:" << endl;
  cin >> el;
  l.InsFirst(el);
  n--;
	  while (n > 0)
	  {
		  cin >> el;
		  l.InsLast(el);
		  n--;
	  }
	  switch (rand()%2)
	  {
	  case(1):
			  l.Circle(rand()%(n-1));
			  break;
	  default:
		  break;
	  }
	  cout << endl << "����� ���������� ������ ����� ������ ���������������? "<< endl <<" ������� 0, ���� '���� � ��������'.  "<< endl << "������� 1, ���� ���������������� ������. " << endl;
	  cin >> n;
	  while (!((n == 0) || (n == 1)))
	  {
		  cout << endl << "������� ������: ";
		  cin >> n;
	  }

	  switch (n)
	  {
	  case(0):
		  c = l.Rabbit();
		  break;
	  case(1):
		  c = l.Rotate();
		  break;
	  default:
		  break;
	  }
	
	  if (c)
		  cout << endl << "������ �������� " << endl;
	  else
		  cout << endl << "������ �� �������� " << endl;
	  cout << endl << "����� ����������, ������� ����� ������ " << endl<<"����� �����, ������� 1" << endl;
	  cin >> n;
	  if (n == 1)
		  break;
  }

}