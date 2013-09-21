#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const int N = 256;

class Person
{
public:
	Person(){}
	Person(char* firstName, char* lastName, char* gender, char* education, int birthYear);
	void setFirstName(char* firstName);
	void setLastName(char* lastName);
	void setGender(char* gender);
	void setEducation(char* education);
	void setBirthYear(int birthYear);
	char* getFirstName();
	char* getLastName();
	char* getGender();
	char* getEducation();
	int getBirthYear();
	int compareTo(Person man);
	~Person(){}
private:
	char firstName[N], lastName[N], gender[N], education[N];
	int birthYear;
};

Person :: Person(char* firstName_, char* lastName_, char* gender_, char* education_, int birthYear_)
{
	strcpy(firstName,firstName_);
	strcpy(lastName,lastName_);
	strcpy(gender,gender_);
	strcpy(education,education_);
	birthYear = birthYear_;
}

void Person :: setFirstName(char* firstName_)
{
	strcpy(firstName,firstName_);
}

void Person :: setLastName(char* lastName_)
{
	strcpy(lastName,lastName_);
}

void Person :: setGender(char* gender_)
{
	strcpy(gender,gender_);
}

void Person :: setEducation(char* education_)
{
	strcpy(education,education_);
}

void Person :: setBirthYear(int birthYear_)
{
	birthYear = birthYear_;
}

char* Person :: getFirstName()
{
	return firstName;
}

char* Person :: getLastName()
{
	return lastName;
}

char* Person :: getGender()
{
	return gender;
}

char* Person :: getEducation()
{
	return education;
}

int Person :: getBirthYear()
{
	return birthYear;
}

int Person :: compareTo(Person man)
{
	return getBirthYear() - man.getBirthYear();
}


int initArraySize();
Person* initPeopleArray(int size);
void inputPeopleArray(Person* people, int size);

void swap(Person*& person1, Person*& person2);
void repair(Person* people, int size, int index);
void buildHeap(Person* people, int size);
void sortPeopleArray(Person* people, int size);

void initFileName(char* fileName);
void createFile(char* fileName, Person* people, int size);
void displayFile(char* fileName);





int main()
{
	char fileName[50];
	int size = initArraySize();
	initFileName(fileName);
	
	Person* people = initPeopleArray(size);
	if(people == NULL)
	{
		cout << "Out of memory exception!";
		return 0;
	}
	inputPeopleArray(people, size);
	system("cls");

	createFile(fileName, people, size);
	displayFile(fileName);
	
	sortPeopleArray(people, size);

	cout << "Sorted:\n\n";

	createFile(fileName, people, size);
	displayFile(fileName);

	delete [] people;
	system("pause");
	return 0;
}





Person* initPeopleArray(int size)
{
	Person* people = new Person[size];
	if(people == NULL)
		return NULL;
	return people;
}

void inputPeopleArray(Person* people, int size)
{
	char firstName[N] = "", lastName[N] = "", gender[N] = "", education[N] = "";
	int birthYear = 0;
	for(int i = 0; i < size; i++)
	{
		cin.ignore();
		cout << "Person #" << i+1 << endl;
		cout << "Enter the first name: ";
		cin.getline(firstName, N, '\n');
		cout << "Enter the last name: ";
		cin.getline(lastName, N, '\n');
		cout << "Enter the gender: ";
		cin.getline(gender, N, '\n');
		cout << "Enter the education: ";
		cin.getline(education, N, '\n');
		cout << "Enter the year of birth: ";
		cin >> birthYear;
		people[i] = Person(firstName, lastName, gender, education, birthYear);
		cout << endl;
	}
}

void sortPeopleArray(Person* people, int size) 
{
	buildHeap(people, size);
	for(int i = size - 1; i >= 0; --i) 
	{
	    swap(people[0], people[i]);
		repair(people, i-1, 0);
	}
}

void buildHeap(Person* people, int size)
{
	for(int i = size / 2; i >= 0; --i) 
		repair(people, size, i);
}

void repair(Person* people, int size, int i)
{
    int left = 2*i+1;
	int right = 2*i+2;
	
	int max = i;
	if(left < size && people[left].compareTo(people[max]) > 0) 
		max = left;
	if(right < size && people[right].compareTo(people[max]) > 0)
		max = right;

	if(max != i)
	{
		swap(people[max], people[i]);
		repair(people, size, max); 
	}
}

void swap(Person*& person1, Person*& person2)
{
	Person* temp = person1;
	person1 = person2;
	person2 = temp;
}

void createFile(char* fileName, Person* people, int size)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::trunc);
	if(!streamOut)
	{
		cout << "Can't open file " << fileName << " to write." << endl;
		system("pause");
		return ;
	}
	for(int i = 0; i < size; i++)
	{
		streamOut << people[i].getFirstName() << " " << people[i].getLastName() << ", " << people[i].getGender() <<
			", " << people[i].getEducation() << " education, born in " << people[i].getBirthYear() << "." << endl << endl;
	}

	streamOut.close();
}

void initFileName(char* fileName)
{
	cin.ignore();
	cout << "Enter the name of file:";
	cin.getline(fileName, N, '\n');
}

int initArraySize()
{
	int size;
	cout << "Enter the size of the array: ";
	cin >> size;
	return size;
}

void displayFile(char*fileName)
{
	ifstream streamIn;
	streamIn.open(fileName);
	if(!streamIn)
	{
		cout << "Can't open file " << fileName << " to read.";
		return;
	}
	char temp[N];
	while(!streamIn.eof())
	{
		streamIn.getline(temp, N);
		cout << temp << endl;
	}
	
	streamIn.close();
}