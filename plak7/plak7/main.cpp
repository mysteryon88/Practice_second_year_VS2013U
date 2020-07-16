#include "FunLib.h"

int main()
{
	Triangle triangle;
	ofstream file;
	time_t seconds = time(NULL);
	bool exit = true;
	char choose = ' ', startTime[80];

	strftime(startTime, 80, "%A %d %B %Y %H:%M:%S", localtime(&seconds)); // logs

	file.open("Results.txt", ios_base::app);
	file << startTime << "\n\n";
	file.close();

	while (exit)
	{
		cout <<
			"| 1.Enter coordinates from the keyboard\n"
			"| 2.Take coordinates from file\n"
			"| 3.Exit\n";

		cout << "\nChoose an action >> ";
		choose = _getch();
		switch (choose)
		{
		case '1':
			if (triangle.set_xy_keyboard()) break;
			else 
				if (triangle.set_abc()) break;
				else triangle.set_angles();
			break;
		case '2':
			triangle.set_xy_file();
			if (triangle.set_abc()) break;
			else triangle.set_angles();
			break;
		case '3':
			exit = false;
			cout << "\nEXIT\n";
			break;
		default:
			cout << "\nChoose again!\n";
			break;
		}
	}

	system("pause");
	return 0;
}