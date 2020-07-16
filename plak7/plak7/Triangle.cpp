#include "FunLib.h"

bool  Triangle::set_xy_keyboard(){

	system("cls");
	int i;

	for (i = 0; i < 3; i++)
	{
		cout << "Enter coordinates " << i + 1 << " points\n";
		try
		{
			cin >> x[i] >> y[i];
			cin.ignore(32767, '\n');
			if (cin.fail())
			{
				throw "The character entered is not a number!";
			}
		}
		catch (const char* exc)
		{
			cout << exc << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			return true;
		}

	}
	return false;
}

void  Triangle::set_xy_file(){

	system("cls");
	ifstream file("Triangles.txt");
	bool f = true;
	if (file.is_open())
	{
		int i = 0, j, choose, val;
		string line;
		cout << "\nTriangles:" << endl;

		while (!file.eof())
		{
			cout << "\nTriangle [" << ++i << "]";
			file >> val; cout << "\nx1 = " << val;
			file >> val; cout << " y1 = " << val;
			file >> val; cout << "\nx2 = " << val;
			file >> val; cout << " y2 = " << val;
			file >> val; cout << "\nx3 = " << val;
			file >> val; cout << " y3 = " << val;
		}

		while (f){
			cout << "\nChoose an action >> ";
			cin >> choose;

			if (choose <= i && choose > 0)
			{
				file.seekg(0, ios_base::beg);

				for (i = 1; i < choose; i++)
					for (j = 0; j < 6; j++)
						file >> val;

				for (i = 0; i < 3; i++)
				{
					file >> x[i];
					file >> y[i];
				}
				f = false;
			}
			else cout << "\nChoose again!\n";
		}
		file.close();
	}
	else cout << "File not found! :( \n";
}

bool Triangle::set_abc(){
	
	ofstream file;
	file.open("Results.txt", ios_base::app); 

	file << "x1 = " << x[0] << " y1 = " << y[0]
		<< "\nx2 = " << x[1] << " y2 = " << y[1]
		<< "\nx3 = " << x[2] << " y3 = " << y[2] << "\n";
	try
	{
	    if (x[0] == x[1] && x[1] == x[2] && y[0] == y[1] && y[1] == y[2])  throw "Triangle not exist\n";
		if ((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2]))  throw "Triangle not exist\n";
		if (((x[2] - x[0]) / (x[1] - x[0])) == ((y[2] - y[0]) / (y[1] - y[0])))  throw "Triangle not exist\n";
	}
	catch (const char* exc)
	{
		file << exc;
		cout << exc;
		return 1;
	}
	a = sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2));
	b = sqrt(pow(x[2] - x[1], 2) + pow(y[2] - y[1], 2));
	c = sqrt(pow(x[0] - x[2], 2) + pow(y[0] - y[2], 2));
	if (a == b || a == c || c == b) file << "Triangle isosceles\n", cout << "Triangle isosceles\n";  //Треугольник равнобедренный
	else if (a == b && b == c) file << "Equilateral triangle\n", cout << "Equilateral triangle\n"; // Треугольник равностроннией
	file.close();
	return 0;
}

void Triangle::set_angles(){

	float pi = 3.14159;
	bool f, f1;
	ofstream file;
	file.open("Results.txt", ios_base::app); 

	u1 = round((acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a*b))*(180 / pi)));
	u2 = round((acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a*c))*(180 / pi)));
	u3 = round((acos((pow(c, 2) + pow(b, 2) - pow(a, 2)) / (2 * c*b))*(180 / pi)));
	
	int s1 = u1, s2 = u2, s3 = u3;
 	__asm
	{
		mov f, 1
		mov eax, s1
		cmp eax, 90
		je m
		mov eax, s2
		cmp eax, 90
		je m
		mov eax, s3
		cmp eax, 90
		jne k
	m : 
		mov f, 0
	k : 
	}
	__asm{
		mov f1, 1
		mov eax, s1
		cmp eax, 90
		jge q
		mov eax, s2
		cmp eax, 90
		jge q
		mov eax, s3
		cmp eax, 90
		jl l
	q :
		mov f1, 0
	l :
	}

	if (!f) file << "The triangle is rectangular\n\n", cout << "The triangle is rectangular\n"; //Треугольник прямоугольный
	else if (f1) file << "Triangle acute\n\n", cout << "Triangle acute\n"; //Треугольник остроугольный
	else file << "Triangle obtuse\n\n", cout << "Triangle obtuse\n"; //Треугольник тупоугольный
	file.close();
}


