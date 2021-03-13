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
  cout << "Введите количество элементов в списке: ";
  cin >> n;
  if (n <= 0)
  {
	  cout << endl << "Некорректно введенное число. Попробуйте еще раз" << endl;
	  continue;
  }
  cout << endl << "Введите элементы списка:" << endl;
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
	  cout << endl << "Каким алгоритмом поиска цикла хотите поспользоваться? "<< endl <<" Введите 0, если 'заяц и черепаха'.  "<< endl << "Введите 1, если переворачиванием списка. " << endl;
	  cin >> n;
	  while (!((n == 0) || (n == 1)))
	  {
		  cout << endl << "Введите заново: ";
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
		  cout << endl << "Список зациклен " << endl;
	  else
		  cout << endl << "Список не зациклен " << endl;
	  cout << endl << "Чтобы продолжить, введите любой символ " << endl<<"Чтобы выйти, нажмите 1" << endl;
	  cin >> n;
	  if (n == 1)
		  break;
  }

}