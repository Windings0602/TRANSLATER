#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

multimap <string, string> translate;

void Read() {
	ifstream file("dataBase.txt");
	string str;
	while (getline(file, str)) {
		string key = "";
		int startId;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '|') {
				startId = i + 1;
				break;
			}
			else {
				key += str[i];
			}
		}
		string value = "";
		for (int i = startId; i < str.size(); i++) {
			if (str[i] == ';') {
				translate.insert(pair<string, string>(key, value));
				value = "";
				break;
			}
			else if (str[i] == ',') {
				translate.insert(pair<string, string>(key, value));
				value = "";
			}
			else {
				value += str[i];
			}
		}
	}
}

void PrintDataBase() {
	string oldKey = "";
	for (auto i : translate) {
		if (oldKey == i.first) {
			cout << "," << i.second;
		}
		else if(oldKey=="") {
			cout << i.first << " " << i.second;
		}
		else {
			cout << "\n" << i.first << " " << i.second;
		}
		oldKey=i.first;
	}
	cout << "\n";
}

void AddDataBase() {
	cout << "Добавляем новый элимент, введите значение.\n";
	string key;
	cout << "Key = ";
	getline(cin, key);
	string value;
	cout << "val = ";
	getline(cin, value);
	cout << "Вы уверены? Для подтверждения введите yes. \n";
	string answer;
	cin >> answer;
	if (answer=="yes") {
		translate.insert(pair<string, string>(key, value));
		cout << "Успешно.\n";
	}
	else {
		cout << "не доюавлено.";
	}
}

void Save() {
	ofstream file("dataBase.txt");
	string oldKey = "";
	for (auto i : translate) {
		if (oldKey == i.first) {
			file << "," << i.second;
		}
		else if (oldKey == "") {
			file << i.first << "|" << i.second;
		}
		else {
			file << ";\n" << i.first << "|" << i.second;
		}
		oldKey = i.first;
	}
	file << ";";
	cout << "сохранено";
}

void DeleteKey() {
	cout << "Введите элимент \n";
	string key;
	cout << "Key = ";
	getline(cin, key);
	cout << "Вы уверены? Для подтверждения введите yes. \n";
	string answer;
	cin >> answer;
	if (answer == "yes") {
		translate.erase(key);
		cout << "Успешно.\n";
	}
	else {
		cout << "не удалено.";
	}
}

void DeleteVal() {
	cout << "Введите значение \n";
	string value;
	cout << "Val = ";
	getline(cin, value);
	cout << "Вы уверены? Для подтверждения введите yes. \n";
	string answer;
	cin >> answer;
	if (answer == "yes") {
		for (auto i = translate.begin(); i != translate.end(); i++) {
			if (i -> second==value) {
				translate.erase(i);
				cout << "Успешно.\n";
				return;
			}
		}
		cout << "не удалено.";
	}
	else {
		cout << "не удалено.";
	}
}
void PrintMenu() {
	system("cls");
	cout << "1-прочитать\n2-добавить\n3-удалить\n4-сохранить\n";

}

int main()
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251
	Read();
	PrintMenu();
	while (true){
		switch (_getch()) {
			case 49:
				system("cls");
				PrintDataBase();
				_getch();
				PrintMenu();
				break;
			case 50:
				system("cls");
				AddDataBase();
				_getch();
				PrintMenu();
				break;
			case 51:
				system("cls");
				DeleteVal();
				_getch();
				PrintMenu();
				break;
			case 52:
				system("cls");
				Save();
				_getch();
				PrintMenu();
				break;
		}
	}
}
	// enter=13 a=97 esc=27  1=49 2=50 3=51 4=52 5=53 0=48