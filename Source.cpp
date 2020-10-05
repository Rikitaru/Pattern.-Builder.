#include<iostream>
#include<fstream>
#include<string>
#include <locale.h>
#include<windows.h>

using namespace std;

class Auto
{
public:

	Auto() :color(" "), price(0), engtype(" "), engsize(0) {};
	void setColor()
	{
		cout << "введите цвет машины: ";
		SetConsoleCP(1251);
		cin>>color;
		SetConsoleCP(866);
	}
	void setPrice()
	{
		cout << "введите цену : ";
		cin >> price;
	}
	void setType()
	{
		cout << "введите тип двигателя(бензиновый или дизельный): ";
		SetConsoleCP(1251);
		cin>>engtype;
		SetConsoleCP(866);
	}
	void setSize()
	{
		cout << "введите объём двигателя в литрах: ";
		cin >> engsize;
	}

	void setModel()
	{
		cout << "введите модель: ";
		SetConsoleCP(1251);
		cin>>model;
		SetConsoleCP(866);
	}

	void setType_steering()
	{
		cout << "введите тип рулевого управления(винтовой,реечный,червячный): ";
		SetConsoleCP(1251);
		cin>>type_steering;
		SetConsoleCP(866);
	}

	void setYear()
	{
		cout << "введите год выпуска: ";
		cin >> year_manufac;
	}

	void setMake()
	{
		cout << "введите марку: ";
		SetConsoleCP(1251);
		cin>>make;
		SetConsoleCP(866);
	}

	void setDimensions()
	{
		cout << "введите размеры в метрах(1.2*2.1*3.6): ";
		SetConsoleCP(1251);
		cin>>dimensions;
		SetConsoleCP(866);
	}

	void setTrunk_vol()
	{
		cout << "введите объём багажника в м^3: ";
		cin >> trunk_volume;
	}

	void setFuel()
	{
		cout << "введите вид топлива(Дизельное, АИ-91, АИ-92, АИ-93, АИ-95, АИ-98): ";
		SetConsoleCP(1251);
		cin>>fuel;
		SetConsoleCP(866);
	}

	void show(int c)
	{
		cout << "    Заказ: " << endl
			<< "цвет: " << color << endl
			<< " объём двигателя в литрах: " << engsize << endl
			<< " цена авто: " << price << endl
			<< " тип двигателя: " << engtype << endl
			<< "модель: " << model << endl
			<< "тип рулевого управления: " << type_steering << endl
			<< "год выпуска: " << year_manufac << endl
			<< "марка: " << make << endl
			<< "размеры(длина,ширина,высота): " << dimensions << endl;
			if(c==0){ cout << "объём багажника в м^3: " << trunk_volume << endl; }
			else{ cout << "объём багажника в м^3: " << "отсутствует"<< endl; }
			cout<< "топливо: " << fuel << endl;
	}
	string color;
	float price;
	string engtype ;
	float engsize ;
	string model;
	string type_steering;
	double year_manufac;
	string make;
	string dimensions;
	double trunk_volume;
	string  fuel;
};

class AutoBuilder:public Auto
{
public:
	AutoBuilder() :aut(0) {}
	virtual void CreateNewElem() = 0;
	virtual void PriceBuilder() = 0;
	virtual void ColorBuilder() = 0;
	virtual void EngtypeBuilder() = 0;
	virtual void EngsizeBuilder() = 0;
	virtual void ModelBuilder() = 0;
	virtual void TypesteeringBuilder() = 0;
	virtual void YearBuilder() = 0;
	virtual void MakeBuilder() = 0;
	virtual void DimensionsBuilder() = 0;
	virtual void TrunkvolBuilder() = 0;
	virtual void  FuelBuilder() = 0;
	virtual void read() = 0;
	virtual void write(int) = 0;
	Auto* GetAuto() { return aut; }

	~AutoBuilder() { delete aut; }

protected:
	Auto *aut;
};

class CarMashinBuilder :public AutoBuilder
{
public:
	fstream file;
	void CreateNewElem() override { aut = new Auto; }
	void PriceBuilder() override { aut->setPrice(); }
	void ColorBuilder() override { aut->setColor(); }
	void EngtypeBuilder() override { aut->setType(); }
	void EngsizeBuilder() override { aut->setSize(); }
	void ModelBuilder() override { aut->setModel(); }
	void TypesteeringBuilder() override { aut->setType_steering(); }
	void YearBuilder() override { aut->setYear(); }
	void MakeBuilder() override { aut->setMake(); }
	void DimensionsBuilder() override { aut->setDimensions();}
	void TrunkvolBuilder() override { aut->setTrunk_vol(); }
	void FuelBuilder() override { aut->setFuel(); }
	~CarMashinBuilder() { delete aut; }
	void read() override
	{
		file.open("D://c++//car.txt", fstream::app);
		if (file.is_open())
		{
			SetConsoleCP(1251);
			file << "    Заказ: " << endl
				<< "цвет: " << aut->color << endl
				<< "объём двигателя: " << aut->engsize << endl
				<< "цена: " << aut->price << endl
				<< "тип двигателя: " << aut->engtype << endl
				<< "модель: " << aut->model << endl
				<< "тип рулевого управления: " << aut->type_steering << endl
				<< "год выпуска: " << aut->year_manufac << endl
				<< "марка: " << aut->make << endl
				<< "размеры(длина,ширина,высота): " << aut->dimensions << endl
				<< "объём багажника: " << aut->trunk_volume << endl
				<< "топливо: " << aut->fuel << endl
				<< "------------------------" << endl;
			SetConsoleCP(866);
		}
		file.close();
	}

	void write(int a) override
	{
		if (a == 1)
		{
			file.open("D://c++//car.txt", fstream::app);
			if (file.is_open())
			{
				SetConsoleCP(1251);
				file >> aut->color >> aut->price >> aut->engsize >> aut->engtype>> aut->model>> aut->type_steering>>
					aut->year_manufac>> aut->make>> aut->dimensions>> aut->trunk_volume>> aut->fuel;
				SetConsoleCP(866);
				cout << "    Заказ: " << endl
					<< "цвет: " << aut->color << endl
					<< "объём двигателя: " << aut->engsize << endl
					<< "цена: " << aut->price << endl
					<< "тип двигателя: " << aut->engtype << endl
					<< "модель: " << aut->model << endl
					<< "тип рулевого управления: " << aut->type_steering << endl
					<< "год выпуска: " << aut->year_manufac << endl
					<< "марка: " << aut->make << endl
					<< "размеры(длина,ширина,высота): " << aut->dimensions << endl
					<< "объём багажника: " << aut->trunk_volume << endl
					<< "топливо: " << aut->fuel << endl
					<< "------------------------" << endl;
			}
			file.close();
		}
	}
};

class MotorbikeMashinBuilder :public AutoBuilder
{
public:
	fstream file1;
	void CreateNewElem() override { aut = new Auto; }
	void PriceBuilder() override { aut->setPrice(); }
	void ColorBuilder() override { aut->setColor(); }
	void EngtypeBuilder() override { aut->setType(); }
	void EngsizeBuilder() override { aut->setSize(); }
	void ModelBuilder() override { aut->setModel(); }
	void TypesteeringBuilder() override { aut->setType_steering(); }
	void YearBuilder() override { aut->setYear(); }
	void MakeBuilder() override { aut->setMake(); }
	void DimensionsBuilder() override { aut->setDimensions(); }
	void TrunkvolBuilder() override { aut->setTrunk_vol(); }
	void FuelBuilder() override { aut->setFuel(); }
	void read() override
	{
		file1.open("D://c++//motobike.txt", fstream::app);
		if (file1.is_open())
		{
			SetConsoleCP(1251);
			file1 << "    Заказ: " << endl
				<< "цвет: " << aut->color << endl
				<< "объём двигателя: " << aut->engsize << endl
				<< "цена: " << aut->price << endl
				<< "тип двигателя: " << aut->engtype << endl
				<< "модель: " << aut->model << endl
				<< "тип рулевого управления: " << aut->type_steering << endl
				<< "год выпуска: " << aut->year_manufac << endl
				<< "марка: " << aut->make << endl
				<< "размеры(длина,ширина,высота): " << aut->dimensions << endl
				<< "топливо: " << aut->fuel << endl
				<< "------------------------" << endl;
			SetConsoleCP(866);
		}
		file1.close();
	}

	void write(int a) override
	{
		if (a == 1)
		{
			file1.open("D://c++//motobike.txt", fstream::app);
			if (file1.is_open())
			{
				SetConsoleCP(1251);
				file1 >> aut->color >> aut->price >> aut->engsize >> aut->engtype >> aut->model >> aut->type_steering >>
					aut->year_manufac >> aut->make >> aut->dimensions >> aut->fuel;
				SetConsoleCP(866);
				cout << "    Заказ: " << endl
					<< "цвет: " << aut->color << endl
					<< "объём двигателя: " << aut->engsize << endl
					<< "цена: " << aut->price << endl
					<< "тип двигателя: " << aut->engtype << endl
					<< "модель: " << aut->model << endl
					<< "тип рулевого управления: " << aut->type_steering << endl
					<< "год выпуска: " << aut->year_manufac << endl
					<< "марка: " << aut->make << endl
					<< "размеры(длина,ширина,высота): " << aut->dimensions << endl
					<< "размер багажника: " <<  "отсутствует" << endl
					<< "топливо: " << aut->fuel << endl
					<< "------------------------" << endl;
			}
			file1.close();
		}
	}
	~MotorbikeMashinBuilder() { delete aut; }
};

class QuadbikeMashinBuilder :public AutoBuilder
{
public:
	fstream file2;
	void CreateNewElem() override { aut = new Auto; }
	void PriceBuilder() override { aut->setPrice(); }
	void ColorBuilder() override { aut->setColor(); }
	void EngtypeBuilder() override { aut->setType(); }
	void EngsizeBuilder() override { aut->setSize(); }
	void ModelBuilder() override { aut->setModel(); }
	void TypesteeringBuilder() override { aut->setType_steering(); }
	void YearBuilder() override { aut->setYear(); }
	void MakeBuilder() override { aut->setMake(); }
	void DimensionsBuilder() override { aut->setDimensions(); }
	void TrunkvolBuilder() override { aut->setTrunk_vol(); }
	void FuelBuilder() override { aut->setFuel(); }
	void read()override
	{
		file2.open("D://c++//quadbike.txt", fstream::app);
		if (file2.is_open())
		{
			SetConsoleCP(1251);
			file2 << "    Заказ: " << endl
				<< "цвет: " << aut->color << endl
				<< "объём двигателя: " << aut->engsize << endl
				<< "цена: " << aut->price << endl
				<< "тип двигателя: " << aut->engtype << endl
				<< "модель: " << aut->model << endl
				<< "тип рулевого управления: " << aut->type_steering << endl
				<< "год выпуска: " << aut->year_manufac << endl
				<< "марка: " << aut->make << endl
				<< "размеры(длина,ширина,высота): " << aut->dimensions << endl
				<< "топливо: " << aut->fuel << endl
				<< "------------------------" << endl;
			SetConsoleCP(866);
		}
		file2.close();
	}

	void write(int a) override
	{
		if (a == 1)
		{
			file2.open("D://c++//quadbike.txt", fstream::app);
			if (file2.is_open())
			{
				SetConsoleCP(1251);
				file2 >> aut->color >> aut->price >> aut->engsize >> aut->engtype >> aut->model >> aut->type_steering >>
					aut->year_manufac >> aut->make >> aut->dimensions >> aut->fuel;
				SetConsoleCP(866);
				cout << "    Заказ: " << endl
					<< "цвет: " << aut->color << endl
					<< "объём двигателя: " << aut->engsize << endl
					<< "цена: " << aut->price << endl
					<< "тип двигателя: " << aut->engtype << endl
					<< "модель: " << aut->model << endl
					<< "тип рулевого управления: " << aut->type_steering << endl
					<< "год выпуска: " << aut->year_manufac << endl
					<< "марка: " << aut->make << endl
					<< "размеры(длина,ширина,высота): " << aut->dimensions << endl
					<< "размер багажника: " << "отсутствует" << endl
					<< "топливо: " << aut->fuel << endl
					<< "------------------------" << endl;
			}
			file2.close();
		}
	}
	~QuadbikeMashinBuilder() { delete aut; }
};

class Director
{
public:
	Auto* createAuto(AutoBuilder & object,int a,int b)
	{
		object.CreateNewElem();
		object.EngsizeBuilder();
		object.PriceBuilder();
		object.ColorBuilder();
		object.EngtypeBuilder();
		object.ModelBuilder();
		object.TypesteeringBuilder();
		object.YearBuilder();
		object.MakeBuilder();
		object.DimensionsBuilder();
		if (a != b)
		{
			object.TrunkvolBuilder();
		}
		object.FuelBuilder();
		object.read();
		object.write(a);
		return object.GetAuto();
	}

};

void main()
{
	setlocale(LC_ALL, "Rus");
	CarMashinBuilder cmb;
	MotorbikeMashinBuilder mmb;
	QuadbikeMashinBuilder qmb;
	Director dir;
	Auto* automob;

	int index = 0;
	int flag = 0;
	cout << "0-выход из программы " << endl
		<< "1-построить легковой автомобиль" << endl
		<< "2-построить мотоцикл " << endl
		<< "3-построить квадроцикл" << endl;
	cout << "введите номер действия:";
	cin >> index;
	while (index != 0)
	{
		switch (index)
		{
		case(1):
			cout << "введите 1-для вывода с из файла, 2- из консоли: " << endl;
			cin>> flag;
			if (flag == 2)
			{
				automob = dir.createAuto(cmb,0,1);
				automob->show(0);
			}
			else if(flag==1){ automob = dir.createAuto(cmb, 1,2); }
			cout << "введите номер действия: " << endl;
			cin >> index;
			break;
		case(2):
			cout << "введите 1-для вывода с из файла, 2- из консоли: " << endl;
			cin >> flag;
			if (flag == 2)
			{
				automob = dir.createAuto(mmb, 0,0);
				automob->show(1);
			}
			else if (flag == 1) { automob = dir.createAuto(mmb, 1,1); }
			cout << "введите номер действия: " << endl;
			cin >> index;
			break;
		case(3):
			cout << "введите 1-для вывода с из файла, 2- из консоли: " << endl;
			cin >> flag;
			if (flag == 2)
			{
				automob = dir.createAuto(qmb, 0,0);
				automob->show(1);
			}
			else if (flag == 1) { automob = dir.createAuto(qmb, 1,1); }
			cout << "введите номер действия: " << endl;
			cin >> index;
			break;
		default:
			cout << "введено неверое значение, попробуйте снова: ";
			cin >> index;
			break;
		}
	}
}