#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
	int size, weight;
	string name;
public:
	Car()
	{
		size = 0;
		weight = 0;
		name = "";
	}
	Car(int size, int weight, string name)
	{
		this->size = size;
		this->weight = weight;
		this->name = name;
	}
	~Car()
	{}
	void display()
	{
		cout << "Name: " << name << "\nSize: " << size << "\nWeight: " << weight << endl;
	}

};
class Student
{
public:
	Student();
	~Student();
	Student(int age, string name, string rank);
	void display()
	{
		cout << "Name: " << name << endl << "Age: " << age << endl << "Rank: " << rank << endl;
	}
	void upage()
	{
		age = age + 1;
	}
	void uprank()
	{
		if (rank == "D") rank = "C";
		else if (rank == "C") rank = "B";
		else if (rank == "B") rank = "A";
	}
	Student& Student::operator++(){
		this->uprank();
		return *this;
	}
private:
	int age;
	string name, rank;
};

Student::Student()
{
	age = 0;
	name = "";
	rank = "D";
}
Student::Student(int age, string name, string rank)
{
	this->age = age;
	this->name = name;
	this->rank = rank;

}

Student::~Student()
{
}
int main()
{
	Student A;
	A.display();
	A++;
	A.display();
	Student B(1, "B", "A");
	B.display();
	return 0;

}

