// sdizo_1.cpp : Defines the entry point for the console application.


//Program byl pisany samodzielnie
//Podczas jego pisania korzystalem z materialow zawartych na stronach:
//www.pl.wikibooks.org
//www.eduinf.waw.pl
//http://www.cplusplus.com
//www.cpp0x.pl

//Autor:
//Filip Baszak

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <list>
#include <chrono>
#include <string>
#include <ctime>

using namespace std;

//Zacznijmy od tego ze liczba ma byc 4 bajtowa ze znakiem czyli operujemy na intach
//Dodatkowo mamy zrealizowac te same operacje na 4 strukturach: tablica, lista, kopiec binarny i drzewo czerwono czarne
//Potrzebujemy 4 klasy
//Dodatkwoo przyda³aby sie klasa MENU

class Tablica { //Klasa zajmujaca sie struktura: Tablica
public:
	Tablica();
	Tablica(Tablica & model);
	ifstream file;
	int *tab;
	int size;
	void createTab();
	void printTab();
	void menu();
};

void Tablica::menu() { //Metoda zarzadzajaca dzialaniem i operacjach wykonywalnych na strukturze

	short exit = 0;
	short choise;

	int index = 0;
	int number = 0;
	while (exit == 0) {
		if (exit == 1) break;
		cout << "Co chcesz zrobic?\n";
		cout << "1. Dodaj liczbe na poczatek tablicy. \n";
		cout << "2. Dodaj liczbe na koniec tablicy. \n";
		cout << "3. Dodaj liczbe na okreslone miejsce w tablicy. \n";
		cout << "4. Usun liczbe z pierwszego miejsca tablicy. \n";
		cout << "5. Usun liczbe z ostatniego miejsca w tablicy. \n";
		cout << "6. Usun liczbe z  okreslonego miejsca w tablicy. \n";
		cout << "7. Wypisz liczbe o zadanym indeksie. \n";
		cout << "8. Wypisz elementy WSZYSTKIE ELEMENTY! \n";
		cout << "9. Wroc do poprzedniego menu. \n";
		cin >> choise;
		if (!cin) {
			cin.clear();
			cin.ignore();
		}
		switch (choise) {

		case 1:
		{
			cout << "Podaj liczbe: \n";
			cin >> number;
			const Tablica copy(*this);
			delete[] tab;
			size++;
			tab = new int[size];
			tab[0] = number;
			for (int i = 0; i < copy.size; i++) {
				tab[i + 1] = copy.tab[i];
			}
			delete[] copy.tab;
			break;
		}
			
		case 2:
		{
			cout << "Podaj liczbe: \n";
			cin >> number;
			const Tablica copy(*this);
			delete[] tab;
			size++;
			tab = new int[size];

			for (int i = 0; i < copy.size; i++) {
				tab[i] = copy.tab[i];
			}
			tab[copy.size] = number;
			delete[] copy.tab;
			number = 0;
			break;
		}
		case 3:
		{
			cout << "Podaj liczbe: \n";
			cin >> number;
			cout << "Podaj index: \n";
			cin >> index;

			const Tablica copy(*this);
			delete[] tab;
			size++;
			tab = new int[size];

			for (int i = 0; i < index; i++) {
				tab[i] = copy.tab[i];
			}
			tab[index] = number;
			for (int i = index; i < copy.size; i++) {
				tab[i + 1] = copy.tab[i];
			}
			delete[] copy.tab;
			number = 0;
			break;
		}
		case 4:
		{
			const Tablica copy(*this);
			delete[] tab;
			size--;
			tab = new int[size];
			for (int i = 0; i < size; i++) {
				tab[i] = copy.tab[i + 1];
			}
			delete[] copy.tab;
			break;
		}
		case 5:
		{
			const Tablica copy(*this);
			delete[] tab;
			size--;
			tab = new int[size];
			tab[0] = number;
			for (int i = 0; i < size; i++) {
				tab[i] = copy.tab[i];
			}
			delete[] copy.tab;
			break;
		}
		case 6:
		{
			cout << "Podaj index: \n";
			cin >> index;

			const Tablica copy(*this);
			delete[] tab;
			size--;
			tab = new int[size];

			for (int i = 0; i < index; i++) {
				tab[i] = copy.tab[i];
			}

			for (int i = index; i < size; i++) {
				tab[i] = copy.tab[i + 1];
			}
			delete[] copy.tab;
			index = 0;
			break;
		}
		case 7:
			cout << "Podaj index: \n";
			cin >> index;
			if (index < 0 || index > size) {
				cout << "Wpisales zly index.\n";
			}
			else {
				cout << "Liczba o podanym indexie: " << tab[index] << endl;
			}
			break;
		case 8:
			cout << "Oto dane z naszej tablicy: \n";
			printTab();
			break;
		case 9:
			cout << "Wychodzisz ze struktury: TABLICA. \n";
			delete[] tab;
			exit = 1;
			break;
		default:
			cout << "Wybrales zla opcje! \n";
			break;
		}

	}
}
Tablica::Tablica(Tablica & model) { //Konstruktor kopiujacy
	tab = new int[model.size];
	size = model.size;
	for (int i = 0; i<model.size; i++)
	{
		tab[i] = model.tab[i];
	}
}
void Tablica::printTab() { //Metoda ktora wyswietla tablice
	for (int i = 0; i < size; i++) {
		cout << tab[i] << endl;
	}
	cout << "Liczba elementow: " << size << endl;
}
void Tablica::createTab() { //Metoda tworzaca tablice danych
	string path = "dane.txt";
	file.open(path.c_str());
	if (file.good()) {
		file >> size;
		tab = new int[size];
		int counter = 0;
		int currentN;
		while (counter<size) {

			file >> currentN;
			tab[counter] = currentN;
			counter++;
		}
		//tab = Tab;
		cout << "Udalo sie utworzyc tablice. \n";
	}
	else {
		cout << "Nie udalo sie utworzyc tablicy ;c";
		exit(100);
	}
	file.close();
}
Tablica::Tablica() { //Konstruktor struktury Tablica
	createTab();
	printTab();

}

class Lista //Klasa operujaca na liscie oraz przechowujaca jej elementy
{
public:
	int size;
	list<int>::iterator it;
	ifstream file;
	list<int> lista;
	Lista();
	~Lista();
	void createList();
	void printList();
	void menu();

};

void Lista::menu() { //Klasa zajmujaca sie struktura: Lista

	short exit = 0;
	short choise;

	int index = 0;
	int number = 0;
	while (exit == 0) {
		if (exit == 1) break;
		cout << "Co chcesz zrobic?\n";
		cout << "1. Dodaj liczbe na poczatek listy. \n";
		cout << "2. Dodaj liczbe na koniec listy. \n";
		cout << "3. Dodaj liczbe na okreslone miejsce w listy. \n";
		cout << "4. Dodaj liczbe za okreslona liczbe. \n";
		cout << "5. Usun liczbe z pierwszego miejsca listy. \n";
		cout << "6. Usun liczbe z ostatniego miejsca w listy. \n";
		cout << "7. Usun liczbe z okreslonego miejsca w listy lub usun dana wartosc z listy. \n";
		cout << "8. Wypisz liczbe o zadanym indeksie. \n";
		cout << "9. Wypisz elementy WSZYSTKIE ELEMENTY! \n";
		cout << "10. Rozpocznij testy LISTY! \n";
		cout << "0. Wroc do poprzedniego menu. \n";
		cin >> choise;
		if (!cin) {
			cin.clear();
			cin.ignore();
		}
		switch (choise) {
		case 1:
		{
			

			cout << endl;
			cout << "podaj liczbe: \n";
			cin >> number;
			lista.push_front(number);
			size = lista.size();
			number = 0;
			break;
		}
		case 2:
		{
			cout << endl;
			cout << "podaj liczbe: \n";
			cin >> number;
			lista.push_back(number);
			size = lista.size();
			number = 0;
			cout << endl;
			break;
		}
		case 3:
		{
			cout << endl;
			it = lista.begin();
			cout << "Podaj liczbe: \n";
			cin >> number;
			cout << "Podaj index: \n";
			cin >> index;
			for (int i = 0; i < index; i++) {
				it++;
			}
			lista.insert(it, number);
			index = 0;
			number = 0;
			size = lista.size();
			cout << endl;
			break;
		}
		case 4:
		{
			cout << endl;
			bool foundN = false;
			cout << "Podaj liczbe ktora chcesz wstawic: \n";
			cin >> number;
			cout << "Podaj liczbe za ktora chcesz wstawic: \n";
			cin >> index;
			int numberH;
			int counter = 0;
			for (auto x : lista) {
				numberH = x;

				if (numberH == index) {
					it = lista.begin();
					foundN = true;
					advance(it, counter);
					lista.insert(it, number);
					break;
				}
				counter++;
			}
			if (foundN) {
				cout << "Wstawiles liczbe " << number << " za liczbe " << index << " na miejscu " << counter << endl;

			}
			else {
				lista.push_front(number);
				cout << "Nie znalezlismy podanej liczby w liscie, wstawilismy nowa liczbe na poczatek listy.\n";
			}
			number = 0;
			index = 0;
			cout << endl;
			cout << endl;
			break;
		}
		case 5:
		{
			cout << endl;
			lista.pop_front();
			size = lista.size();
			cout << endl;
			break;
		}
		case 6:
		{
			cout << endl;
			lista.pop_back();
			size = lista.size();
			cout << endl;
			break;
		}
		case 7:
		{
			cout << endl;
			char wybor;
			cout << "Czy chcesz usunac po indeksie czy po wartosci?(I/W) \n";
			cin >> wybor;
			if (wybor == 'I') {
				it = lista.begin();
				cout << "Podaj index do usuniecia: \n";
				cin >> index;
				if (index <0 || index >lista.size()) {
					cout << "Zly index!\n";
					break;
				}
				for (int i = 0; i < index; i++) {
					it++;
				}
				lista.erase(it);
				size = lista.size();
				index = 0;
				break;
			}
			else if (wybor == 'W') {
				cout << "Podaj wartosc do usuniecia: \n";
				cin >> number;
				lista.remove(number);
				size = lista.size();
				number = 0;
				break;
			}
			else {
				cout << "Wpisales zla opcje! \n";
			}
			cout << endl;
			break;
		}
		case 8:
		{
			cout << endl;
			cout << "Podaj index: \n";
			cin >> index;
			it = lista.begin();

			advance(it, index);
			number = *it;
			cout << "Oto numer o podanym indeksie: " << number << endl;
			index = 0;
			number = 0;
			cout << endl;
			break;
		}
		case 9:
			printList();
			cout << endl;
			break;
		case 0:
			cout << "Wychodzisz ze struktury: Lista. \n";
			exit = 1;
			break;
		
		default:
			cout << "Wybrales zla opcje! \n";
			break;
		}

	}
}
void Lista::createList() { //Metoda tworzaca liste z liczb zapisanych w pliku
	string path = "dane.txt";
	file.open(path.c_str());
	if (file.good()) {

		file >> size;
		int counter = 0;
		int currentN;
		while (counter<size) {

			file >> currentN;
			lista.push_back(currentN);
			counter++;
		}

		cout << "Udalo sie utworzyc liste. \n";
	}
	else {
		cout << "Nie udalo sie utworzyc tablicy ;c";
		exit(100);
	}
	size = lista.size();
	file.close();
}

void Lista::printList() { //Metoda wypisujaca zawartosc listy
	for (auto x : lista) {
		cout << x << endl;

	}
	cout << "Ilosc liczba na liscie: " << size << endl;
}

Lista::Lista() //Konstruktor klasy Lista
{
	createList();
	printList();
}

Lista::~Lista() //Destruktor klasy Lista
{
}

struct Heap //Struktura kopca binarnego
{
	Heap * father; //Wskazniki na ojca i synow
	Heap * left;
	Heap * right;
	int number; //wartosc int
};

class HeapTab { //Klasa operujaca na strukturze kopca oraz przechowujaca jego elementy
public:
	Heap * root;
	ifstream file;
	int size;
	Heap **tab;
	Heap **help;
	HeapTab();
	HeapTab(HeapTab *model);
	~HeapTab();
	//const HeapTab help;
	void createHeap();
	void menu();
	void printHeap();
	//void addToHeap(Heap *x, int index);
	void addToHeap(int number, int index);
	void checkNumber(int i, int f);
	void printBT(string sp, string sn, int v);
	//void addNew(Heap *x);
	void addNew(int number);
	void removeRoot();
	void checkDown(int father);
	void findNumber(int number);
	string zr, zl, zp;
};

void HeapTab::printHeap() { //Metoda ktora wypisuje liczby zapisane w kopcu TABLICOWO!
	for (int i = 0; i < size; i++) {
		cout << tab[i]->number << endl;
	}
	cout << "W kopcu mamy: " << size << " elementow." << endl;
}


void::HeapTab::findNumber(int  number) { //Metoda szukajaca danej wartosci w kopcu
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (tab[i]->number == number) {
			found = true;
			cout << "Liczba znajduje sie w kopcu.\n";
			cout << "Index: " << i << endl;
			if ((i - 1) / 2 >= 0) {
				cout << "Numer indeksu ojca: " << (i - 1) / 2 << endl;
			}
			if ((i * 2 + 1) < size) {
				cout << "Numer indeksu lewego syna: " << (i * 2 + 1) << endl;
			}
			if ((i * 2 + 2) < size) {
				cout << "Numer indeksu prawego syna: " << (i * 2 + 2) << endl;
			}
			return;
		}
	}
	cout << "Takiej liczby nie ma w kopcu. \n";

}
void HeapTab::addNew(int number) { //Metoda dodajaca nowy obiekt typu Heap do struktury Kopca binarnego
	int sizeCopy = size;
	Heap **tabCopy = new Heap*[size];
	for (int i = 0; i < sizeCopy; i++) {
		tabCopy[i] = tab[i];
	}
	size++;
	delete[] tab;
	tab = new Heap*[size];
	for (int i = 0; i < sizeCopy; i++) {
		tab[i] = tabCopy[i];
	}
	addToHeap(number, sizeCopy);
	delete[] tabCopy;
}
void HeapTab::removeRoot() { //Metoda usuwajaca z kopca binarnego korzen
	int number = root->number;
	int sizeCopy = size;
	HeapTab help(this);
	//help = new Heap*[size];
	size--;
	tab = 0;
	delete[] tab;
	tab = new Heap*[size];
	for (int i = 1; i < size; i++) {
		tab[i] = help.tab[i];
	}
	tab[0] = help.tab[size];
	tab[0]->left = tab[1];
	tab[0]->right = tab[2];
	tab[0]->father = root;
	root = tab[0];

	checkDown(0);
	cout << "korzen przed suuneiciem: " << number << endl;
	cout << "Korzen po usunieciu: " << root->number << endl;
}

void HeapTab::checkDown(int father) { //Metoda sprawdzajaca warunek kopca "w dol"
	int sonL, sonR;
	Heap help;
	int number;
	sonL = (2 * father) + 1;
	sonR = (2 * father) + 2;
	bool isBad = true;
	if (tab[father]->number >= tab[sonL]->number && tab[father]->number >= tab[sonR]->number) {
		isBad = false;
	}
	while (isBad) {
		if (tab[sonL]->number >= tab[father]->number) {
			if (tab[father]->number >= tab[sonL]->number && tab[father]->number >= tab[sonR]->number) {
				isBad = false;
			}
			else {
				if (sonL < size) {
					number = tab[sonL]->number;
					tab[sonL]->number = tab[father]->number;
					tab[father]->number = number;
					father = sonL;
				}
			}

			
			if ((2 * father) + 1 < size) {
				sonL = (2 * father) + 1;
			}
			else {
				isBad = false;
			}
			if ((2 * father) + 2 < size) {
				sonR = (2 * father) + 2;
			}
		}
		else {

			if (tab[father]->number >= tab[sonL]->number && tab[father]->number >= tab[sonR]->number) {
				isBad = false;
			}
			else {
				if (sonR < size) {
					number = tab[sonR]->number;
					tab[sonR]->number = tab[father]->number;
					tab[father]->number = number;
					father = sonR;
				}
			}
			

			if ((2 * father) + 1 < size) {
				sonL = (2 * father) + 1;
			}
			else {
				isBad = false;
			}
			if (((2 * father) + 2) < size) {
				sonR = (2 * father) + 2;
			}
			
		}
	}
}
void HeapTab::menu() { //Menu zarzadzajace struktura

	short exit = 0;
	short choise;
	int number = 0;
	while (exit == 0) {
		if (exit == 1) break;
		cout << "Co chcesz zrobic?\n";
		cout << "1. Dodaj liczbe do kopca. \n";
		cout << "2. Usun liczbe z kopca. \n";
		cout << "3. Znajdz liczbe. \n";
		cout << "4. Wyswietl kopiec w postaci listy. \n";
		cout << "5. Wyswietl kopiec w postaci drzewa. \n";
		cout << "9. Wroc do poprzedniego menu. \n";
		cin >> choise;
		if (!cin) {
			cin.clear();
			cin.ignore();
		}
		switch (choise) {//Wybor naszego Menu
		case 1:
		{
			cout << endl;
			cout << "Podaj liczbe jaka chcesz dodac: \n";
			cin >> number;
			Heap *help = new Heap;;
			help->number = number;
			help->father = NULL;
			help->left = NULL;
			help->right = NULL;
			addNew(number);
			number = 0;
			cout << endl;
			break;
		}
		case 2:
		{
			cout << endl;
			removeRoot();
			cout << endl;
			break;
		}
		case 3:
		{
			cout << endl;
			cout << "Podaj liczbe jaka chcesz znalezc: \n";
			cin >> number;
			findNumber(number);
			number = 0;
			cout << endl;
			break;
		}
		case 4:
		{
			printHeap();
			cout << endl;
			break;
		}
		case 5:
		{
			printBT("", "", 0);
			cout << endl;
			break;
		}
		case 9:
			cout << "Wychodzisz ze struktury: Kopiec binarny. \n";
			tab=NULL;
			delete []tab;
			exit = 1;
			break;
		default:
			cout << "Wybrales zla opcje! \n";
			break;
		}

	}
}
void HeapTab::createHeap() { //Metoda wczytujaca liczby z pliku i tworzaca strukture
	string path = "dane.txt";
	file.open(path.c_str());
	if (file.good()) {
		file >> size;
		int counter = 0;
		int currentN=0;
		Heap *currentH = new Heap();
		currentH->father = NULL;
		currentH->left = NULL;
		currentH->right = NULL;
		tab = new Heap*[size];
		while (counter<size) {
			file >> currentN;
			currentH->number = currentN;
			if (root == NULL) {
				//tab[counter] = currentH;
				tab[counter] = new Heap();
				tab[counter]->number = currentN;
				tab[counter]->father = NULL;
				tab[counter]->left = NULL;
				tab[counter]->right = NULL;
				root = tab[counter];
			}
			else {
				addToHeap(currentN, counter);
			}
			counter++;
		}
		counter = 0;
		cout << "Udalo sie utworzyc kopiec. \n";
	}
	else {
		cout << "Nie udalo sie utworzyc kopca!";
		exit(100);
	}
	file.close();
}
void HeapTab::addToHeap(int number, int index) { //Metoda dodajaca nowy element do Kopca binarnego
	cout << number << endl;
	int father = (index - 1) / 2;
	bool ok = false;
	tab[index] = new Heap;
	tab[index]->number = number;
	tab[index]->left = NULL;
	tab[index]->father = NULL;
	tab[index]->right = NULL;
	//cout << "wchodzi do addToHeap()" << endl;
	if (tab[father]->left == NULL) {
		tab[index]->father = tab[father];
		tab[father]->left = tab[index];
		//cout << "Numer ojca: " << tab[index].father->number << endl;
		checkNumber(index, father);

		return;
		//cout << "Nie wyszlo z metody!" << endl;
	}
	if (tab[father]->right == NULL) {
		tab[index]->father = tab[father];
		tab[father]->right = tab[index];
		checkNumber(index, father);
		return;
		//cout << "Nie wyszlo z petli 2!" << endl;
	}
}
void HeapTab::checkNumber(int i, int f) { //Metoda ustawiajaca w kolejnosci elementy kopca binarnego
	bool notGood = true;
	if (tab[i]->number <= tab[f]->number) {
		notGood = false;
		return;
	}
	Heap * father = tab[i]->father;
	Heap *help;
	while ((notGood)) {

		help = tab[f];
		tab[f] = tab[i];
		tab[i] = help;
		if (i % 2 == 0) {
			tab[f]->left = help->left;
			tab[f]->right = tab[i];
			tab[f]->father = tab[i]->father;
		}
		else {
			tab[f]->right = help->right;
			tab[f]->left = tab[i];
			tab[f]->father = tab[i]->father;
		}
		tab[i]->left = NULL;
		tab[i]->right = NULL;
		tab[i]->father = tab[f];
		i = f;
		f = (i - 1) / 2;
		father = tab[i]->father;
		if ((tab[i]->number <= tab[f]->number) || (tab[i]->father == NULL)) {
			notGood = false;
		}


	}

}
void HeapTab::printBT(string sp, string sn, int v) //Metoda wypisujaca kopiec w postaci drzewa
{
	string s;

	if (v < size) //rekurencja trwa dopoki nie zejdziemy na najnizszy poziom 
	{
		s = sp;
		if (sn == zr) s[s.length() - 2] = ' ';
		printBT(s + zp, zr, 2 * v + 2); //Prawi synowie

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << " " << tab[v]->number << endl;

		s = sp;
		if (sn == zl) s[s.length() - 2] = ' ';
		printBT(s + zp, zl, 2 * v + 1); //lewi synowie
	}
}
HeapTab::HeapTab() { //Konstruktor HeapTab
	root = NULL;
	createHeap();

	zr = zl = zp = "  ";//Potrzebujemy paru stringow do ladnego wypisania kopca
	zr[0] = 218; zr[1] = 196;
	zl[0] = 192; zl[1] = 196;
	zp[0] = 179;
	//menu();//Wywolanie metody ktora odpowiada za fcje struktury Kopca binarnego
}
HeapTab::HeapTab(HeapTab *model) { //Konstruktor kopiujacy
	tab = new Heap*[model->size];
	size = model->size;
	for (int i = 0; i<size; i++)
	{
		tab[i] = model->tab[i];
	}
}
HeapTab::~HeapTab() { //Destruktor klasy HeapTab

}

struct RBTree { //Struktura wezla czerwono czarnego
	RBTree * father; //Wskazniki na ojca i synow
	RBTree * left;
	RBTree * right;
	//int key;
	char color;
	int number;
};

class RBTreeTab { //Klasa operujaca na drzewie oraz przechowujaca jego elementy
public:
	ifstream file;
	int size;
	RBTreeTab();
	RBTreeTab(RBTreeTab *model);
	~RBTreeTab();
	RBTree **tab;
	RBTree **tabSorted;
	RBTree * root;
	RBTree *sentinel;
	RBTree *findMin(RBTree * element);
	RBTree *findChangable(RBTree * element);
	void createRBTree();
	void addToRBTree(int number, int i);
	void checkColor(RBTree *e);
	void printTree(string sp, string sn, RBTree * element);
	void printSorted();
	void findNumber(int number);
	void deleteNumber(RBTree *element);
	void deleteF(int number);
	void rotateTreeRight(RBTree * A);
	void rotateTreeLeft(RBTree * element);
	void menu();
	void addNew(int number);
	string zr, zl, zp;
};

RBTreeTab::RBTreeTab() { //Konstruktor
	sentinel = NULL;
	tab = NULL;
	tabSorted = NULL;
	zr = zl = zp = "  "; //Potrzebujemy paru stringow do ladnego wypisania drzewa
	zr[0] = 218; zr[1] = 196;
	zl[0] = 192; zl[1] = 196;
	zp[0] = 179;
	sentinel = new RBTree();
	sentinel->number = 0;
	sentinel->father = sentinel;
	sentinel->left = sentinel;
	sentinel->right = sentinel;
	sentinel->color = 'B';
	root = new RBTree();
	root = sentinel;
	createRBTree();
	
	//menu();
}

RBTreeTab::RBTreeTab(RBTreeTab *model) { //Konstruktor kopiujacy
	size = model->size;
	tab = new RBTree*[size];
	for (int i = 0; i<size; i++) {
		tab[i] = model->tab[i];
	}

}

RBTreeTab::~RBTreeTab() { //Destruktor

}
void RBTreeTab::createRBTree() {  //Metoda budujaca strukture drzewa czerwono czarnego
	string path = "dane.txt";
	file.open(path.c_str());
	if (file.good()) {
		file >> size;
		int counter = 0;
		int currentN;
		RBTree *currentRB = new RBTree();

		tab = new RBTree*[size];
		while (counter<size) {
			//cout << counter << endl;
			currentRB->father = root;
			currentRB->left = sentinel;
			currentRB->right = sentinel;
			file >> currentN;
			currentRB->number = currentN;
			if (root == sentinel) {
				tab[counter] = new RBTree;
				tab[counter]->number = currentN;
				tab[counter]->father = root;
				tab[counter]->left = sentinel;
				tab[counter]->right = sentinel;
				tab[counter]->color = 'B';
				root = tab[counter];
				root->left = sentinel;
				root->right = sentinel;
				cout << "KORZEN" << endl;
				cout << "Numer korzenia to...: " << root->number << endl;
				counter++;
			}
			else {
				addToRBTree(currentN, counter);
				//cout << "Numer korzenia to...: " << root->number << endl;
				counter++;
			}

		}
		cout << "Udalo sie utworzyc drzewo czerwono czarne. \n";
		cout << "Korzen: " << root->number << endl;
		
	}
	else {
		cout << "Nie udalo sie utworzyc drzewa!";
		exit(100);
	}
	file.close();
}

void RBTreeTab::addNew(int number) { //Metoda dodajaca nowy element do drzewa czerwono-czarnego
	RBTreeTab helpT(this);
	delete[] tab;
	size++;
	tab = new RBTree*[size];
	for (int i = 0; i<size - 1; i++) {
		tab[i] = new RBTree;
		tab[i] = helpT.tab[i];
		delete helpT.tab[i];
	}
	addToRBTree(number, helpT.size);
	helpT.tab = NULL;
	delete[] helpT.tab;
	number = 0;
	bool ok = true;
	RBTree *uncle;
	int index = size - 1;
	tab[index] = new RBTree;
	tab[index]->number = number;
	tab[index]->father = root;
	tab[index]->left = sentinel;
	tab[index]->right = sentinel;
	int licznik = 0;
	while (true) {																						//  |
		if ((tab[index]->number) < (tab[index]->father->number)) {										//  |
			if ((tab[index]->father->left) == sentinel) {												//  |
				tab[index]->father->left = tab[index];													//  |
				RBTree *wsk1 = tab[index]->father->left;												//  |
				RBTree *wsk2 = tab[index]->father;														//  |
				tab[index]->left = sentinel;															//  |
				tab[index]->right = sentinel;															//  |
				break;																					//  | - fragment kodu suzkjacego dobrego miejsca w drzewie dla danego wezla( miejsce wyznaczane jest po kluczu)
			}																							//  |
			RBTree *wsk3 = tab[index]->father->left;													//  |
			tab[index]->father = wsk3;																	//  |
		}																								//  |
		else {																							//  |
			if ((tab[index]->father->right) == sentinel) {												//  |
				tab[index]->father->right = tab[index];													//  |
				RBTree *wsk1 = tab[index]->father->right;												//  |
				RBTree *wsk2 = tab[index]->father;														//  |
				tab[index]->left = sentinel;															//  |
				tab[index]->right = sentinel;															//  |
				break;																					//  |
																										//  |
			}																							//  |
			tab[index]->father = tab[index]->father->right;												//  |
		}																								//  |
																										//  |
		licznik++;
	}//-----------------------------------------------------------------------------------------------------------
	checkColor(tab[index]);			//Daje prawidlowy kolor wezlom

}

void RBTreeTab::addToRBTree(int number, int index) { //Metoda dodajaca nowy element do drzewa czerwono-czarnego

	bool ok = true;
	RBTree *uncle;
	tab[index] = new RBTree;
	tab[index]->number = number;
	tab[index]->father = root;
	tab[index]->left = sentinel;
	tab[index]->right = sentinel;
	int licznik = 0;
	while (true) {																						//  |
		if ((tab[index]->number) < (tab[index]->father->number)) {										//  |
			if ((tab[index]->father->left) == sentinel) {												//  |
				tab[index]->father->left = tab[index];													//  |
				RBTree *wsk1 = tab[index]->father->left;												//  |
				RBTree *wsk2 = tab[index]->father;														//  |
				tab[index]->left = sentinel;															//  |
				tab[index]->right = sentinel;															//  |
				break;																					//  | - fragment kodu suzkjacego dobrego miejsca w drzewie dla danego wezla( miejsce wyznaczane jest po kluczu)
			}																							//  |
			RBTree *wsk3 = tab[index]->father->left;													//  |
			tab[index]->father = wsk3;																	//  |
		}																								//  |
		else {																							//  |
			if ((tab[index]->father->right) == sentinel) {												//  |
				tab[index]->father->right = tab[index];													//  |
				RBTree *wsk1 = tab[index]->father->right;												//  |
				RBTree *wsk2 = tab[index]->father;														//  |
				tab[index]->left = sentinel;															//  |
				tab[index]->right = sentinel;															//  |
				break;																					//  |
																										//  |
			}																							//  |
			tab[index]->father = tab[index]->father->right;												//  |
		}																								//  |
																										//  |
		licznik++;
	}//-----------------------------------------------------------------------------------------------------------
	checkColor(tab[index]);			//Daje prawidlowy kolor wezlom
	
}

void RBTreeTab::checkColor(RBTree *e) {
	bool czarny=false;
	if (e->father->color == 'B') {
		czarny = true;
		e->color = 'R';
	}
	else {
		e->color = 'B';
	}

}

void RBTreeTab::findNumber(int number) { // Metoda szukajaca elementu w drzewie
	for (int i = 0; i<size; i++) {
		if (tab[i]->number == number) {
			cout << "Liczba znajduje sie w drzewie. \n";
			return;
		}
	}
	cout << "Takiej liczby nie ma w drzewie. \n";
}

void RBTreeTab::rotateTreeRight(RBTree * element) { // Metoda wykonujaca rotacje w drzewie(rotacja potrzebna do przywrocenia struktury drzewa podczas operacji dodawania i usuwania elementu); rotacja w prawo
	RBTree *brother, *help;
	brother = element->left;
	if (brother != sentinel)
	{
		help = element->father;
		element->left = brother->right;
		if (element->left != sentinel) {
			element->left->father = element;
		}
		brother->right = element;
		brother->father = help;
		element->father = brother;

		if (help != sentinel)
		{
			if (help->left == element) {
				help->left = brother;
			}
			else {
				help->right = brother;
			}
		}
		else root = brother;
	}
}

void RBTreeTab::rotateTreeLeft(RBTree * element) { // Metoda wykonujaca rotacje w drzewie(rotacja potrzebna do przywrocenia struktury drzewa podczas operacji dodawania i usuwania elementu); rotacja w lewo
	RBTree *brother, *help;
	brother = element->right;
	//cout << &brother << endl;
	if (brother != sentinel)
	{
		help = element->father;
		element->right = brother->left;
		if (element->right != sentinel) {
			element->right->father = element;
		}
		brother->left = element;
		brother->father = help;
		element->father = brother;
		if (help != sentinel)
		{
			if (help->left == element) {
				help->left = brother;
			}
			else {
				help->right = brother;
			}
		}
		else root = brother;
	}
}

void RBTreeTab::printSorted() { //Metoda ktora wyprintowuje drzewo w postaci listy 
	//sortToRBTree(root, sizeH);
	for (int i = 0; i < size; i++) {
		cout << tab[i]->number << endl;
	}
	cout << "W drzewie jest: " << size << " elementow." << endl;
}

void RBTreeTab::deleteF(int number) { // Metoda sprawdzajca czy dana liczba moze byc usunieta
	for (int i = 0; i < size; i++) {
		if (tab[i]->number == number) {
			cout << "Liczba " << number << " znajduje sie w drzewie!\n";
			deleteNumber(tab[i]);
			cout << "Liczba " << number << " zostala usunieta.\n";
			return;
		}
	}
	cout << "Liczby " << number << " nie ma w drzewie.\n";
}

void RBTreeTab::deleteNumber(RBTree * e) { // Mtoda ktora usuwa dany elemnet z drzewa czerwono czarnego
	RBTree *brother, *toD, *son;//toD - wskaznik wskazujcy na element ktory trzeba usunac; son - wskaznik ktory zastapi miejsce usunietego(bedzie synem ojca elemntu usunietego); uncle - brat wskaznika son
	if ((e->left == sentinel) && (e->right == sentinel)) {
		if (e == e->father->left) {
			e->father->left = sentinel;
		}
		else {
			e->father->right = sentinel;
		}
		delete e;
		return;
	}
	if ((e->left == sentinel) || (e->right == sentinel)) {//|
		toD = e;										//  |
	}													//  |
	else {												//  |
		toD = findChangable(e);							//  |
	}													//  |
	if (toD->left != sentinel) {						//  |
		son = toD->left;								//  | - ta czesc kodu wyszukuje wskazniki ktorymi trzeba zastapic puste miejsce w drzewie
	}													//  |
	else {												//  |
		son = toD->right;								//  |
	}													//  |
	son->father = toD->father;							//  |
														//  |
	if (toD->father == sentinel) {						//  |
		root = son;										//  |
	}													//  |
	else {												//	|
		if (toD == toD->father->left) {					//  |
			toD->father->left = son;					//  |
														//  |
		}												//  |
		else {											//  |
			toD->father->right = son;					//  |
		}												//  |
		if (toD != e) {									//  |
			e->number = toD->number;					//  |
		}												//  |
	}													//
	if (toD->color == 'B') {							// Od tego momentu program sprawdza czy struktura drzewa czerwono czarnego jest zachowana a jesli nie to ja naprawia
		while ((son != root) && (son->color == 'B')) {	//sprawdzane sa rozne mozliwe przypadki powiazan elemnetu ktory trzeba usunac
			if (son == son->father->left)
			{
				brother = son->father->right;			//znajdujemu brata wskaznika son

				if (brother->color == 'R')				//Przypadek gdy brat wskaznika son jest czerwony
				{   // Przypadek 1
					brother->color = 'B';
					son->father->color = 'R';
					rotateTreeLeft(son->father);
					brother = son->father->right;
				}

				if ((brother->left->color == 'B') && (brother->right->color == 'B'))//Przypadek gdy brat wskaznika son jest czarny i posiada czarnych synow
				{   // Przypadek 2
					brother->color = 'R';
					son = son->father;
					continue;
				}

				if (brother->right->color == 'B')		//Przypadek gdy brat wskaznika son jest czarny a synowie sa mieszani
				{   // Przypadek 3
					brother->left->color = 'B';
					brother->color = 'R';
					rotateTreeRight(brother);
					brother = son->father->right;
				}
				// Przypadek 4
				brother->color = son->father->color;	// Przypadek gdy brat wskaznika son jest czarny a jego prawy syn czerwony
				son->father->color = 'B';
				brother->right->color = 'B';
				rotateTreeLeft(son->father);
				son = root;								// To spowoduje zakoñczenie pêtli
			}
			else										//Przypadki lustrzane
			{                
				brother = son->father->left;

				if (brother->color == 'R')
				{   // Przypadek 1
					brother->color = 'B';
					son->father->color = 'R';
					rotateTreeRight(son->father);
					brother = son->father->left;
				}

				if ((brother->left->color == 'B') && (brother->right->color == 'B'))
				{   // Przypadek 2
					brother->color = 'R';
					son = son->father;
					continue;
				}

				if (brother->left->color == 'B')
				{   // Przypadek 3
					brother->right->color = 'B';
					brother->color = 'R';
					rotateTreeLeft(brother);
					brother = son->father->left;
				}
				// Przypadek 4
				brother->color = son->father->color;  
				son->father->color = 'B';
				brother->left->color = 'B';
				rotateTreeRight(son->father);
				son = root;								// To spowoduje zakoñczenie pêtli
			}
		}
	}
	//root->color = 'B';									//Kolorujemy obiekt na ktory wskazuje wskaznik son na czarno
	//delete toD;
	//delete son;
	son = NULL;
	toD = NULL;
	brother = NULL;
}

RBTree * RBTreeTab::findMin(RBTree * e) {				//Metoda szukajaca najmniejszego elementu w galezi drzewa
	if (e->left == sentinel) {
		return e;
	}
	e = e->left;
}

RBTree * RBTreeTab::findChangable(RBTree * e) {			//Metoda szukajaca elementu 
	RBTree *help;
	if (e == sentinel) {
		return e;
	}
	else {
		if (e->right != sentinel) {
			return findMin(e->right);
		}
		else {
			help = e->father;
			while ((help != sentinel) && (e == help->right))
			{
				e = help;
				help = help->father;
			}
			return help;
		}
	}
}

void RBTreeTab::printTree(string sp, string sn, RBTree * element) //Metoda wypisujaca drzewo w postaci drzewa
{
	string t;
	if (element == root) {
		cout << "Element jest korzeniem!\n";
		cout << element->number << endl;
	}
	if (element != sentinel)
	{
		t = sp;
		if (sn == zr) t[t.length() - 2] = ' ';
		printTree(t + zp, zr, element->right);

		t = t.substr(0, sp.length() - 2);
		cout << t << sn << element->color << ":" << element->number << endl;

		t = sp;
		if (sn == zl) t[t.length() - 2] = ' ';
		printTree(t + zp, zl, element->left);
	}
}

void RBTreeTab::menu() {//Menu zarzadzajace struktura

	short exit = 0;
	short choise;
	int number = 0;
	while (exit == 0) {
		if (exit == 1) break;
		cout << "Co chcesz zrobic?\n";
		cout << "1. Dodaj liczbe do drzewa. \n";
		cout << "2. Usun liczbe z drzewa. \n";
		cout << "3. Znajdz liczbe. \n";
		cout << "4. Wyswietl drzewo w postaci listy. \n";
		cout << "5. Wyswietl drzewo w postaci drzewa. \n";
		cout << "9. Wroc do poprzedniego menu. \n";
		cin >> choise;
		if (!cin) {
			cin.clear();
			cin.ignore();
		}
		switch (choise) {//Wybor naszego Menu
		case 1:
		{

				cout << endl;
				cout << "Podaj liczbe jaka chcesz dodac do drzewa: \n";
				cin >> number;
				
				RBTreeTab helpT(this);
				delete tab;
				size++;
				tab = new RBTree*[size];
				for (int i = 0; i < size - 1; i++) {
					//tab[i] = new RBTree();
					tab[i] = helpT.tab[i];
				}
				addToRBTree(number, helpT.size);
				delete helpT.tab;
				//number = 0;
			cout << endl;
			break;
		}
		case 2:
		{
			cout << endl;
			RBTree help;
			cout << "Podaj liczbe jaka chcesz usunac z drzewa: \n";
			cin >> number;
			help.number = number;
			RBTreeTab helpT(this);
			helpT.deleteF(number);
			delete[] tab;
			size--;
			tab = new RBTree*[size];
			int y = 0;
			for (int i = 0; i<size; i++) {
				if (helpT.tab[y] == NULL) {
					y++;
				}
				tab[i] = helpT.tab[y];
				y++;
			}
			helpT.tab = NULL;
			delete helpT.tab;
			number = 0;
			cout << endl;
			break;
		}
		case 3:
		{
			cout << endl;
			cout << "Podaj liczbe jaka chcesz znalezc: \n";
			cin >> number;
			findNumber(number);
			cout << endl;
			number = 0;
			break;
		}
		case 4:
		{
			printSorted();
			cout << endl;
			break;
		}
		case 5:
		{
			cout << endl;
			printTree("","", root);
			cout << endl;
			break;
		}
		case 9:
			cout << "Wychodzisz ze struktury: Drzewo czerwono-czarne. \n";
			tab=NULL;
			tabSorted = NULL;
			delete tab;
			delete tabSorted;
			exit = 1;
			break;
		default:
			cout << "Wybrales zla opcje! \n";
			break;
		}

	}
}

class Liczby {
public:
	short iloscProdukowanychDanych;
	void doNumbers();

};

void Liczby::doNumbers() {
	int znak;
	int liczba;
	//string const mojPlik();
	ofstream plik("dane.txt");
	if (plik) {
		plik << iloscProdukowanychDanych << endl;
		srand(time(NULL));
		for (int i = 0; i < iloscProdukowanychDanych; i++) {
			znak = (rand() % 2) + 0;
			liczba = (rand() % 2147483647) + 0;
			if (znak == 1) {
				liczba = 0 + liczba;
			}
			else {
				liczba = 0 - liczba;
			}
			plik << liczba << endl;
		}

	}
	else {
		cout << "B£¥D: nie mo¿na otworzyæ pliku." << endl;
	}
	plik.close();
}

class Menu { //Klasa zarzadzajaca glownym Menu programu

public:
	unsigned short option;

	Menu();
	void AskForOption() {
		while (true) {//Nasze glowne menu
			cout << "Witaj w programie uzytkowniku.\n";
			cout << "Wpisz numer polecenia: \n";
			cout << "Opcje struktur: \n";
			cout << "1. Tablica. STRUKTURA GOTOWA.\n";
			cout << "2. Lista. STRUKTURA GOTOWA.\n";
			cout << "3. Kopiec binarny. STRUKTURA GOTOWA\n";
			cout << "4. Drzewo czerwono czarne. STRUKTURA GOTOWA.\n";
			cout << "5. Wygeneruj nowe dane. \n";
			//cout << "9. Rozpocznij testy.\n";
			cout << "Aby wyjsc wpisz cokolwiek innego. \n";
			cin >> option;
			if (!cin) {
				cin.clear();
				cin.ignore();
			}
			switch (option) {
			case 1://Tablica
			{
				Tablica tab;
				tab.menu();
				break;
			}
			case 2://lista
			{
				Lista list;
				list.menu();
				break;
			}
			case 3://Kopiec binarny
			{
				HeapTab heap;
				heap.menu();
				break;
			}
			case 4://Drzewo czerwono-czarne
			{
				RBTreeTab tree;
				tree.menu();
				break;
			}
			case 5://Stworzmy inne dane
			{
				Liczby data;
				cout << "Ile danych typu 'int' ma byc w pliku?\n";
				cin >> data.iloscProdukowanychDanych;
				data.doNumbers();
				break;
			}
			
			default:
				cout << "Zla opcja.";
				exit(1000);
				break;
			}
		}
	}


};
Menu::Menu() {
	option = 0;
}
int main()
{
	Menu menu;
	menu.AskForOption();
	return 0;
}