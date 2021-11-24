#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<vector>
using namespace std;
template<class T>
void readInfo(vector<T>& vec, string file);
int main() {
	setlocale(0, "rus");
	ifstream fin("TaskIn2.txt", std::ios::in);
	int counter=0;
	int coordinates = 0;
	char position;
	int td = 1;
	int laps = 1;
	int laps2=1;
	int step = 0;
	string str;

	while (!fin.eof()) {
		position = fin.get();
		if (position == '\n') {
		}
		else
		{
			coordinates++;
		}
		if (step > 3) {
			if ((td== 31-((31 * laps) - coordinates) )) {
				step = 0;
				td = 0;
				if (position == '#') {
					step++;
					counter++;
					cout <<"Номер символа - "<<coordinates << " - " << "Значение символа - " << position << endl;
				}
				if (position == '\n') {
					laps++;
					laps2 = laps;
				}
				if (position == '.') {
					step++;
				}
			}
			else {
				if (position == '\n') {
					laps++;
				}
			}
		}
		else {
			if (position == '#') {
				step++;
				counter++; 
				cout << "Номер символа - " << coordinates << " - " << "Значение символа - " << position << endl;
			}
			if (position == '\n') {
				laps++;
				laps2 = laps;
			}
			if (position == '.') {
				step++;
			}
			if (step >3) {
					td = 31-((31 * laps)- coordinates ) ;
			}
		}
	 }
	cout << counter << endl;
	system("pause");
	
}
template<class T>
void readInfo(vector<T>& vec, string file)
{
	ifstream file1;
	file1.open(file);
	if (file1.peek() == 0) {}
	else {
		while (!file1.eof()) {
			T obj;
			file1 >> obj;
			vec.push_back(obj);
		}
	}
	file1.close();
}