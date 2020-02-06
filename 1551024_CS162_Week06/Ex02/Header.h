#include <string>
#include <fstream>
#include <ctime>


using namespace std;

struct Student
{
	Student();
	int ID;
	string Name;
	Student *Next;
	Student *Prev;
};

class Table
{
public:
	Table();
	~Table();
	void LuckyMan();
private:
	int N;
	Student *Head;
};