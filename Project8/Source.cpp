#include <iostream>
using namespace std;
class Car {
	char* model;
	char* country;
	double price;
	static int count;
public:
	Car();
	Car(const char* m, const char* c, double p);
	~Car();
	void Input();
	void Print();
	const char* GetModel();
	void SetModel(const char* m);
	static int GetCount();
};
int Car::count = 0;
Car::Car()
{
	model = nullptr;
	country = nullptr;
	price = 0;
	count++;
}
Car::Car(const char* m, const char* c, double p)
{
	model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);
	country = new char[strlen(c) + 1];
	strcpy_s(country, strlen(c) + 1, c);
	price = p;
	count++;
}

void Car::Input()
{
	char buff[20];
	cout << "Enter model -> ";
	cin.getline(buff, 20);
	if (model != nullptr)
	{
		delete[]model;
		model = new char[strlen(buff) + 1];
		strcpy_s(model, strlen(buff) + 1, buff);
	}
	model = new char[strlen(buff) + 1];
	strcpy_s(model, strlen(buff) + 1, buff);
	cout << "Enter country -> ";
	cin.getline(buff, 20);
	if (country != nullptr)
	{
		delete[]country;
	}
	country = new char[strlen(buff) + 1];
	strcpy_s(country, strlen(buff) + 1, buff);
	cout << "Enter price-> ";
	cin >> price;
	cin.ignore();
}

void Car::Print()
{
	cout <<endl<< "Model: " << model << "\t Country: " << country <<"\t Price: "<<price<< endl<<endl;
}

const char* Car::GetModel()
{
	return model;
}

void Car::SetModel(const char* m)
{
	if (model != nullptr)
	{
		delete[] model;
	}
	model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);
}

int Car::GetCount()
{
	return count;
}
Car::~Car()
{
	delete[] model;
	delete[] country;
}
int main() {
	int count;
	cout << "Enter count: ";
	cin >> count;
	cin.ignore();
	Car* shop = new Car[count];
	//ввод, вывод, вывод кол-во автомобилей
	for (int i = 0; i < count; i++)
	{
		shop[i].Input();
	}
	for (int i = 0; i < count; i++)
	{
		shop[i].Print();
	}
	cout <<endl<< "Count: " << shop[0].GetCount();
	delete[]shop;
}