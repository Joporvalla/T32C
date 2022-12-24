#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Knigpech
{
public:
	Knigpech()
	{
		nomer = rand() % 100 + 1;
		familia = "n/a";
		imya = "n/a";
		otchestvo = "n/a";
		book = "n/a";
		cost = 1000 + rand() % 1000 + 1;
	}

	Knigpech(int nm, int cst, string fm, string im, string ov, string bk)
	{
		nomer = nm;
		familia = fm;
		imya = im;
		otchestvo = ov;
		book = bk;
		cost = cst;
	}

	void change_nomer(int new_nomer)
	{
		nomer = new_nomer;
	}
	void change_cost(int new_cost)
	{
		cost = new_cost;
	}
	void change_familia(string new_familia)
	{
		familia = new_familia;
	}
	void change_imya(string new_imya)
	{
		imya = new_imya;
	}

	void change_otchestvo(string new_otchestvo)
	{
		otchestvo = new_otchestvo;
	}
	void change_book(string new_book)
	{
		book = new_book;
	}
	int get_nomer()
	{
		return nomer;
	}
	int get_cost()
	{
		return cost;
	}
	string get_familia()
	{
		return familia;
	}
	string get_imya()
	{
		return imya;
	}
	string get_otchestvo()
	{
		return otchestvo;
	}
	string get_book()
	{
		return book;
	}
	void get_info()
	{
		cout << setiosflags(ios::left);


		cout << "  ";
		cout << setw(5) << nomer;
		cout << "   " << setw(9) << familia;
		cout << "   " << setw(9) << imya;
		cout << "   " << setw(9) << otchestvo;
		cout << "   " << setw(20) << book;
		cout << " " << cost;
	}


private:
	int nomer;
	string familia;
	string imya;
	string otchestvo;
	string book;
	int cost;
};




int main()
{
	vector<Knigpech> knig;
	int choose, nm, cst;
	string fm, im, ov, bk;
	Knigpech* object;
	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "1. Новый объект без данных\n2. Новый объект с данными\n3. Переместить элементы\n4. Выдать базу данных\n5. Отчистить\n6. Выход" << endl;
		cout << "Выберите вариант:" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			object = new Knigpech();
			knig.push_back(*object);
			cout << "object created" << endl;
			break;
		case 2:
			cout << "Введите номер"; cin >> nm;
			cout << "Введите фамилию"; cin >> fm;
			cout << "Введите имя"; cin >> im;
			cout << "Введите отчество"; cin >> ov;
			cout << "Введите название книги"; cin >> bk;
			cout << "Enter введите цену"; cin >> cst;
			object = new Knigpech(nm, cst, fm, im, ov, bk);
			knig.push_back(*object);
			break;
		case 3://убрать
			nm = NULL; cst = NULL; fm = ""; im = ""; ov = ""; bk = "";
			int num;
			cout << "Если элемент хотите прервать редактирование, введите -1" << endl;
			cin >> num;
			if (num == -1) break;
			cout << "Номер изменяемой строки: " << endl;
			cout << setiosflags(ios::left);
			cout << "   Номер   " << "Имя   " << "  Фамилия" << "Отчество  " << "Название книги" << "Цена  " << endl;
			knig[num - 1].get_info();
			cout << endl;

			cout << "Введите номер"; cin >> nm;
			cout << "Введите имя"; cin >> im;
			cout << "Введите фамилию"; cin >> fm;
			cout << "Введите отчество"; cin >> ov;
			cout << "Введите название книги"; cin >> bk;
			cout << "Enter cost"; cin >> cst;

			if (nm != -1)
				knig[num - 1].change_nomer(nm);
			if (im != "-1")
				knig[num - 1].change_imya(im);
			if (fm != "- 1")
				knig[num - 1].change_familia(fm);
			if (ov != "- 1")
				knig[num - 1].change_otchestvo(ov);
			if (bk != "- 1")
				knig[num - 1].change_book(bk);
			if (cst != -1)
				knig[num - 1].change_cost(cst);


			cout << setiosflags(ios::left);
			cout << "   Номер   " << "Имя   " << "  Фамилия" << "Отчество  " << "Название книги" << "Цена  " << endl;

			for (int i = 0; i < knig.size(); i++)
			{
				cout << i + 1 << ".  ";
				knig[i].get_info();
				cout << endl;
			}
			cout << endl;
			break;
		case 4:
			cout << "  Номер   " << "Имя\t   " << "   Фамилия     " << "Отчество  " << "  Название книги    " << "   Цена" << endl;
			for (int i = 0; i < knig.size(); i++)
			{

				knig[i].get_info();
				cout << endl;
			}
			break;
		case 5:
			//reknign 0;
			system("cls");
			break;
		case 6:
			return 0;
		default:
			cout << "Неверный ввод" << endl;
			break;
		}
	} while (choose != 6);
}
