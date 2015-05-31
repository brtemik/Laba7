/** 
	\file: main.cpp
	*/

#include <iostream>
#include <conio.h>

/*! \brief class cList() - shablonnyi class spiska  */



template <typename T>
	class cList {
	public:
		T value;
		cList* pNext;
	public:
		cList <typename T> (T value, cList* pNext){
			this->value = value;
			this->pNext = pNext;
		}
		~cList(){};
		void PrintOn(){
			cList* p;
			p = this;
			std::cout << "List is:\n";
			while(p){
				std::cout << "  " << p->value << "\n";
				p = p->pNext;
			}
		}
	};

/*! \brief void main() - tochka vhoda v programmu

*	Sprashivaet polzovatelya, kakoy tip dannyh
*	on hotel by vvesti, zatem generiret y vyvodit spisok 
*   s obectami vybrannogo tipa. */

void main(){
	int mode;
	std::cout << "A list of what type of data do u want to create?(enter number)\n";
	std::cout << "  1 - int;\n";
	std::cout << "  2 - double;\n";
	std::cout << "  3 - char;\n";
	std::cout << "  4 - string;\n";
	std::cin >> mode;

	int prov = 1;
	switch (mode) {
	case 1:
		{
			cList <int> *p = NULL;
			for (int i=0; i<5; i++)
				p = new cList <int> (i, p);
			p->PrintOn();
		}
		break;
	case 2:
		{
			cList <double> *p = NULL;
			for (int i=0; i<5; i++)
				p = new cList <double> ( (double)i*10 / 9 , p);
			p->PrintOn();
		}
		break;
	case 3:
		{
			cList <char> *p = NULL;
			for (int i=0; i<5; i++)
				p = new cList <char> (i+65, p);
			p->PrintOn();
		}
		break;
	case 4:
		{
			cList <char*> *p = NULL;
			char* str[5] = {"first", "second", "third", "fourth", "last string"};
			for (int i=0; i<5; i++)
				p = new cList <char*> (str[i], p);
			p->PrintOn();
		}
		break;
	default:
		std::cout << "Error\n";
		break;
	}
	getch();
}