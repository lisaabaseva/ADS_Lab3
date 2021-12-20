#include "BrokenLine.h"
#include <conio.h>
#include <math.h>
#include <complex>

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int TypeMenu()
{
	system("cls");
	std::cout << "Choose the type you will work with" << std::endl;
	std::cout << "\n1.Work with IntPoint2\n2.Work with DoublePoint3\n3.Work with ComplexPoint\nEsc.Exit\n";
	while (true)
	{
		int key = GetKey();
		if ((key >= 49 && key <= 51) || (key == 27)) return key;
	}
}

int MainMenu()
{
	std::cout << "Hello! Select an action:\n1. Work with first line\n2. Work with second line\n3. View the lines\n";
	std::cout << "4. First line + second line(concatenation)\n5. Second line + first line(concatenation)\n";
	std::cout << "6. Checking for equality of lines.\n\nEsc. Back" << std::endl;
	while (true)
	{
		int key = GetKey();
		if (key >= 49 && key <= 54 || key == 27) return key;
	}
}

int PointMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "1. Change point by index\n2. Adding a point to the beginning of the line.\n";
		std::cout << "3. Adding a point to the end of the line.\n4. The length of the line.\nEsc. Back\n";
		int key = GetKey();
		if (key == 27 || key >= 49 && key <= 52)
			return key;
	}
}


void IntPoints2()
{
	BrokenLine<IntPoint2> line_1, line_2;
	while (true)
	{
		system("cls");
		int m1 = MainMenu();
		if (m1 == 27) break;
		if (m1 == 49)
		{
			while (true)
			{
				system("cls");
				std::cout << line_1 << std::endl;
				int m2 = PointMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					int index = 0;
					std::cout << "Enter index of element:" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_1[index]._x << "," << line_1[index]._y << ")" << std::endl;
						IntPoint2 p;
						std::cout << "Enter the coordinates" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p._y;
						line_1[index]._x = p._x;
						line_1[index]._y = p._y;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_1 = p + line_1;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point:" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_1 = line_1 + p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_1.SizeLine() << std::endl;
						//std::cout << "Return type: " << typeid(line_1.SizeLine()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 50)
		{
			while (true)
			{
				system("cls");
				std::cout << line_2 << std::endl;
				int m2 = PointMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					int index = 0;
					std::cout << "Enter index of element:" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_2[index]._x << "," << line_2[index]._y << ")" << std::endl;
						IntPoint2 p;
						std::cout << "Enter the coordinates" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p._y;
						line_2[index]._x = p._x;
						line_2[index]._y = p._y;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_2 = p + line_2;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point:" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_2 = line_2 + p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_2.SizeLine() << std::endl;
						//std::cout << "Return type: " << typeid(line_1.SizeLine()).name() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 51)
		{
			system("cls");
			std::cout << line_1 << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 52)
		{
			system("cls");
			line_1 = line_1 + line_2;
			std::cout << "Successfully" << std::endl;
			std::cout << line_1 << std::endl;
			system("pause");
		}
		if (m1 == 53)
		{
			system("cls");
			line_2 = line_2 + line_1;
			std::cout << "Successfully" << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 54)
		{
			system("cls");
			if (line_1 == line_2) std::cout << "Lines are equal" << std::endl;
			else std::cout << "Lines aren't equal" << std::endl;
			system("pause");
		}
	}
}

void DoublePoints3()
{
	BrokenLine<DoublePoint3> line_1, line_2;
	while (true)
	{
		system("cls");
		int m1 = MainMenu();
		if (m1 == 27) break;
		if (m1 == 49)
		{
			while (true)
			{
				system("cls");
				std::cout << line_1 << std::endl;
				int m2 = PointMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					int index = 0;
					std::cout << "Enter index of element:" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_1[index]._x << "," << line_1[index]._y << "," << line_1[index]._z << ")" << std::endl;
						DoublePoint3 p;
						std::cout << "Enter the coordinates" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p._y;
						std::cout << "Enter z: " << std::endl;
						std::cin >> p._z;
						line_1[index]._x = p._x;
						line_1[index]._y = p._y;
						line_1[index]._y = p._z;

					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					DoublePoint3 p;
					std::cout << "Enter the coordinates" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					std::cout << "Enter z: " << std::endl;
					std::cin >> p._z;
					try
					{
						line_1 = p + line_1;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					DoublePoint3 p;
					std::cout << "Enter the coordinates" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					std::cout << "Enter z: " << std::endl;
					std::cin >> p._z;
					try
					{
						line_1 = line_1 + p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_1.SizeLine() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 50)
		{
			while (true)
			{
				system("cls");
				std::cout << line_2 << std::endl;
				int m2 = PointMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					int index = 0;
					std::cout << "Enter index of element:" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_1[index]._x << "," << line_1[index]._y << "," << line_1[index]._z << ")" << std::endl;
						DoublePoint3 p;
						std::cout << "Enter the coordinates" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p._y;
						std::cout << "Enter z: " << std::endl;
						std::cin >> p._z;
						line_2[index]._x = p._x;
						line_2[index]._y = p._y;
						line_2[index]._y = p._z;

					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					system("cls");
					DoublePoint3 p;
					std::cout << "Enter the coordinates" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					std::cout << "Enter z: " << std::endl;
					std::cin >> p._z;
					try
					{
						line_2 = p + line_2;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					DoublePoint3 p;
					std::cout << "Enter the coordinates" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					std::cout << "Enter z: " << std::endl;
					std::cin >> p._z;
					try
					{
						line_2 = line_2 + p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_2.SizeLine() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 51)
		{
			system("cls");
			std::cout << line_1 << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 52)
		{
			system("cls");
			line_1 = line_1 + line_2;
			std::cout << "Successfully" << std::endl;
			std::cout << line_1 << std::endl;
			system("pause");
		}
		if (m1 == 53)
		{
			system("cls");
			line_2 = line_2 + line_1;
			std::cout << "Successfully" << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 54)
		{
			system("cls");
			if (line_1 == line_2) std::cout << "Lines are equal" << std::endl;
			else std::cout << "Lines aren't equal" << std::endl;
			system("pause");
		}
	}
}

void PolylineOfComplex()
{
	BrokenLine<StdComplexPoint> line_1, line_2;
	while (true)
	{
		system("cls");
		int m1 = MainMenu();
		if (m1 == 27) break;
		if (m1 == 49)
		{
			while (true)
			{
				system("cls");
				std::cout << line_1 << std::endl;
				int m2 = PointMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					try
					{
						int index = 0;
						std::cout << "Enter index:" << std::endl;
						std::cin >> index;
						std::cout << "(" << line_1[index]._x << "," << line_1[index]._y << ")" << std::endl;
						StdComplexPoint p;
						std::cout << "Enter the coordinates: " << std::endl;
						std::cout << "Enter real part: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter imag part: " << std::endl;
						std::cin >> p._y;
						line_1[index] = p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					
				}
				if (m2 == 50)
				{
					system("cls");
					StdComplexPoint p;
					std::cout << "Enter the coordinates: " << std::endl;
					std::cout << "Enter real part: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter imag part: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_1 = p + line_1;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					StdComplexPoint p;
					std::cout << "Enter the coordinates: " << std::endl;
					std::cout << "Enter real part: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter imag part: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_1 = line_1 + p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_1.SizeLine() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 50)
		{
			while (true)
			{
				system("cls");
				std::cout << line_2 << std::endl;
				int m2 = PointMenu();
				if (m2 == 27) break;
				if (m2 == 49)
				{
					system("cls");
					try
					{
						int index = 0;
						std::cout << "Enter index:" << std::endl;
						std::cin >> index;
						std::cout << "(" << line_2[index]._x << "," << line_2[index]._y << ")" << std::endl;
						StdComplexPoint p;
						std::cout << "Enter the coordinates: " << std::endl;
						std::cout << "Enter real part: " << std::endl;
						std::cin >> p._x;
						std::cout << "Enter imag part: " << std::endl;
						std::cin >> p._y;
						line_2[index] = p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}

				}
				if (m2 == 50)
				{
					system("cls");
					StdComplexPoint p;
					std::cout << "Enter the coordinates: " << std::endl;
					std::cout << "Enter real part: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter imag part: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_2 = p + line_2;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					system("cls");
					StdComplexPoint p;
					std::cout << "Enter the coordinates: " << std::endl;
					std::cout << "Enter real part: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter imag part: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_2 = line_2 + p;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 52)
				{
					try
					{
						system("cls");
						std::cout << "Polyline lenght: " << line_2.SizeLine() << std::endl;
						system("pause");
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
			}
		}
		if (m1 == 51)
		{
			system("cls");
			std::cout << line_1 << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 52)
		{
			system("cls");
			line_1 = line_1 + line_2;
			std::cout << "Successfully" << std::endl;
			std::cout << line_1 << std::endl;
			system("pause");
		}
		if (m1 == 53)
		{
			system("cls");
			line_2 = line_2 + line_1;
			std::cout << "Successfully" << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}
		if (m1 == 54)
		{
			system("cls");
			if (line_1 == line_2) std::cout << "Lines are equal" << std::endl;
			else std::cout << "Lines aren't equal" << std::endl;
			system("pause");
		}
	}
}


int main() {
	while (true)
	{
		system("cls");
		int m = TypeMenu();
		if (m == 27) break;
		if (m == 49) IntPoints2();
		if (m == 50) DoublePoints3();
		if (m == 51) PolylineOfComplex();
	}
	return 0;
}