#include<iostream>
#include<fstream>

using namespace std;

class BoolMatrix
{
	int nrow, ncol;
	bool **elements;
	void buildHeap();
	void repair(int heapSize, int index);
	void swap(bool *& row1, bool *& row2);
	int compareRows(bool *row1, bool *row2);
public:
	BoolMatrix();
	BoolMatrix(int nrow_, int ncol_);
	BoolMatrix(const BoolMatrix & matrix);
	~BoolMatrix();
	int getNrow();
	int getNcol();
	void setElement(int irow, int icol, bool element);
	bool getElement(int irow, int icol);
	void print(ostream & out);
	void read(istream & in);
	BoolMatrix disjunction(BoolMatrix matrix);
	BoolMatrix conjunction(BoolMatrix matrix);
	BoolMatrix inverse();
	BoolMatrix & operator = (const BoolMatrix & matrix);
	BoolMatrix operator || (BoolMatrix matrix);
	BoolMatrix operator && (BoolMatrix matrix);
	BoolMatrix operator ! ();
	void sortRows();
	int countOnes();
};

BoolMatrix :: BoolMatrix():nrow(0),ncol(0),elements(0){}

BoolMatrix :: BoolMatrix(int nrow_, int ncol_):nrow(0),ncol(0),elements(0)
{
	elements = new bool* [nrow_]();
	for(int i = 0; i < nrow_; i++)
		elements[i] = new bool [ncol_]();
	nrow = nrow_;
	ncol = ncol_;
}

BoolMatrix :: BoolMatrix(const BoolMatrix & matrix):nrow(matrix.nrow),ncol(matrix.ncol),elements(0)
{
	elements = new bool* [nrow]();
	for(int i = 0; i < nrow; i++)
	{
		elements[i] = new bool [ncol]();
		for(int j = 0; j < ncol; j++)
			elements[i][j] = matrix.elements[i][j];
	}
}

BoolMatrix :: ~BoolMatrix()
{
	for(int i = 0; i < nrow; i++)
	{
		for(int j = 0; j < ncol; j++)
			elements[i][j] = 0;
		delete [] elements[i];
	}
	delete [] elements;
	elements = 0;
}

int BoolMatrix :: getNrow()
{
	return nrow;
}

int BoolMatrix :: getNcol()
{
	return ncol;
}

void BoolMatrix :: setElement(int irow, int icol, bool element)
{
	elements[irow][icol] = element;
}

bool BoolMatrix :: getElement(int irow, int icol)
{
	return elements[irow][icol];
}

void BoolMatrix :: print(ostream & out)
{
	out << nrow << " " << ncol << endl;
    for (int i = 0; i < nrow; i++)
	{
		for(int j = 0; j < ncol; j++)
			out << elements[i][j] << " ";
		out << endl;
	}
}

void BoolMatrix :: read(istream & in)
{
    if(elements)
	{
	    for(int i = 0; i < nrow; i++)
		{
			for(int j = 0; j < ncol; j++)
				elements[i][j] = 0;
			delete [] elements[i];
		}
		delete [] elements;
		elements = 0;
	}

	in >> nrow;
	in >> ncol;
	elements = new bool* [nrow]();
	for(int i = 0; i < nrow; i++)
	{
		elements[i] = new bool [ncol]();
		for(int j = 0; j < ncol; j++)
			in >> elements[i][j];
	}
}

BoolMatrix BoolMatrix :: disjunction(BoolMatrix matrix)
{
	if(nrow != matrix.nrow || ncol != matrix.ncol)
		return BoolMatrix();
	
	BoolMatrix temp(nrow, ncol);
	for(int i = 0; i < nrow; i++)
		for(int j = 0; j < ncol; j++)
			temp.elements[i][j] = elements[i][j] || matrix.elements[i][j];
	return temp;
}

BoolMatrix BoolMatrix :: conjunction(BoolMatrix matrix)
{
	if(nrow != matrix.nrow || ncol != matrix.ncol)
		return BoolMatrix();
	
	BoolMatrix temp(nrow, ncol);
	for(int i = 0; i < nrow; i++)
		for(int j = 0; j < ncol; j++)
			temp.elements[i][j] = elements[i][j] && matrix.elements[i][j];
	return temp;
}

BoolMatrix BoolMatrix :: inverse()
{	
	BoolMatrix temp(nrow, ncol);
	for(int i = 0; i < nrow; i++)
		for(int j = 0; j < ncol; j++)
			temp.elements[i][j] = !elements[i][j];
	return temp;
}

BoolMatrix & BoolMatrix :: operator = (const BoolMatrix & matrix) 
{
	if(this != &matrix)
	{
		for(int i = 0; i < nrow; i++)
		{
			for(int j = 0; j < ncol; j++)
				elements[i][j] = 0;
			delete [] elements[i];
		}
		elements = 0;
		delete [] elements;

		nrow = matrix.nrow;
		ncol = matrix.ncol;
		elements = new bool* [nrow]();
		for(int i = 0; i < nrow; i++)
		{
			elements[i] = new bool [ncol]();
			for(int j = 0; j < ncol; j++)
				elements[i][j] = matrix.elements[i][j];
		}
	}
	return *this;
}

BoolMatrix BoolMatrix :: operator || (BoolMatrix matrix)
{
	return disjunction(matrix);
}

BoolMatrix BoolMatrix :: operator && (BoolMatrix matrix)
{
	return conjunction(matrix);
}

BoolMatrix BoolMatrix :: operator ! ()
{
	return inverse();
}

int BoolMatrix :: countOnes()
{
	int count = 0;
	for(int i = 0; i < nrow; i++)
		for(int j = 0; j < ncol; j++)
			if(elements[i][j] == 1)
				count++;
	return count;
}

void BoolMatrix :: swap(bool *& row1, bool *& row2)
{
	bool *temp = row1;
	row1 = row2;
	row2 = temp;
}

int BoolMatrix :: compareRows(bool *row1, bool *row2)
{
	for(int i = 0; i < ncol; i++)
	{
		if(row1[i] > row2[i])
			return 1;
		else if(row1[i] < row2[i])
			return -1;
	}
	return 0;
}

void BoolMatrix :: repair(int heapSize, int index)
{
	int left = 2*index+1;
	int right = 2*index+2;
	
	int max = index;
	if(left < heapSize && compareRows(elements[left], elements[max]) > 0) 
		max = left;
	if(right < heapSize && compareRows(elements[right], elements[max]) > 0)
		max = right;

	if(max != index)
	{
		swap(elements[max], elements[index]);
		repair(heapSize, max); 
	}
}

void BoolMatrix :: buildHeap()
{
	for(int i = nrow / 2; i >= 0; --i) 
		repair(nrow, i);
}

void BoolMatrix :: sortRows()
{
	buildHeap();
	for(int i = nrow - 1; i >= 0; --i) 
	{
	    swap(elements[0], elements[i]);
		repair(i, 0);
	}
}




void inputFileName(char* fileName);
void readArray(char *fileName, int & size, BoolMatrix *& matrices);
void complementsSum(BoolMatrix & first, BoolMatrix & second);





int main()
{
	int size = 0;
	BoolMatrix *matrices = 0;

	char fileName[256];
	inputFileName(fileName);

	readArray(fileName, size, matrices);
	
	cout << "Source matrices: " << endl;
	for(int i = 0; i < size; i++)
		matrices[i].print(cout);

	complementsSum(matrices[0], matrices[1]);

	cout << "\ncomplementsSum(matrices[0], matrices[1]): " << endl;
	matrices[0].print(cout);

	for(int i = 0; i < size; i++)
		cout << "Number of 1 in M" << i << ": " << matrices[i].countOnes() << endl;

	for(int i = 0; i < size; i++)
	{
		matrices[i].sortRows();
		cout << "Sorted m" << i << ": " << endl;
		matrices[i].print(cout);
	}

	delete [] matrices;
	system("pause");
	return 0;
}

void inputFileName(char* fileName)
{
	cout << "Enter the name of the file: ";
	cin.getline(fileName, 256, '\n');
}

void readArray(char *fileName, int & size, BoolMatrix *& matrices)
{
	ifstream fin(fileName);
	if (!fin)
	{
		cout << "Fail to read file " << fileName << endl;
		return;
	}

	fin >> size;
	matrices = new BoolMatrix[size]();
	for(int i = 0; i < size; i++)
	{
		matrices[i] = BoolMatrix();
		matrices[i].read(fin);
	}

	fin.close();
}

void complementsSum(BoolMatrix & first, BoolMatrix & second)
{
	first = !first || !second;
}