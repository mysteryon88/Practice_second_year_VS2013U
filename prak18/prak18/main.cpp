#include "LibFun.h"

int main()
{
	setlocale(LC_ALL, "Russian"); 
	srand(time(0));
	const short n = 3;
	ofstream file1("F1.txt");
	float mat[n][n], max, srav;
	int count, i, j, l;
	cout << fixed;
	cout.precision(4);
	cout << "¬ведите кол-во матриц\n";
	cin >> count;
	for (l = 0; l < count; l++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				mat[i][j] = float(rand()) / RAND_MAX + rand() % 10;
				cout << mat[i][j] << " ";
				file1 << mat[i][j] << " ";
			}
			cout << endl;
		}
		file1 << endl;
		cout << endl;
	}
	file1.close();	
	ifstream file2("F1.txt");
	ofstream file3("F2.txt");
	for (l = 0; l < count; l++){
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				file2 >> mat[i][j];
	
		for (i = 0; i < n; i++){
				max = mat[i][0];
			for (j = 0; j < n; j++){
				srav = mat[i][j];
				__asm{
					fld srav
					fcom max
					fstsw ax
					and ax, 0700h
					cmp ah, 1h
					je a
					fstp max
				a :
					nop
					fstp srav
				}
			}
			file3 << max << " ";
		}
		file3 << endl;
	}

	file1.close();
	file3.close();
	system("pause");
	return 0;
}