#include <iostream>
#include <windows.h>
#include <locale.h>
#include "Menu.cpp"
#include <iomanip>   /// setw()


void sort2arr(std::string** arr)
{

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			std::string arr2[1][3];
			if (arr[i][1] < arr[j][1]) 
			{
				arr2[0][0] = arr[i][0];
				arr2[0][1] = arr[i][1];
				arr2[0][2] = arr[i][2];

				arr[i][0] = arr[j][0];
				arr[i][1] = arr[j][1];
				arr[i][2] = arr[j][2];

				arr[j][0] = arr2[0][0];
				arr[j][1] = arr2[0][1];
				arr[j][2] = arr2[0][2];

			}
		}
	}

}



int main(int argc, char** argv)
{

	//SetConsoleOutputCP(65001);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int rows = 7;
	const int colums = 3;

	std::string** p_transports = new std::string * [rows]; // 0 имя 1 результат 2 индикатор

	std::string transports2[7] = { "Ботинки-вездеходы","Метла", "Верблюд", "Кентавр", "Орел", "Верблюд-быстроход", "Ковёр-самолёт" };

	for (int i = 0; i < rows ; i++)
	{
		p_transports[i] = new std::string[colums];
	}

	for (int i = 0; i < rows; i++)
	{

		p_transports[i][0] = transports2[i];
	}

	std::string buf_string;

	int distance = 0;
	int count = 0; // счетчик зарегистрированных тс
	int game_type = 0;


		std::cout << " Добро пожаловать в гоночный симулятор! " << "\n";
		while (true)
		{
			int buf = 666;
		
			Menu menu;

			while (true)
			{
				if (menu.menu1_in(buf_string, game_type))
				{
					std::cout << std::endl;
					break;
				}
				else
				{
					std::cerr << "Неизвестный тип гонки! \n";
				};
			}
			//menu1

			while (true)
			{
				if (menu.menu2_in(buf_string, distance))
				{
					std::cout << std::endl;
					break;
				}
				else
				{
					std::cerr << "Дистанция не соответсвует условиям! \n";
				};

			}
			//menu2

			while (true)
			{
				menu.menu3();
				if (menu.menu3_in())
				{
					std::cout << std::endl;
					break;
				}
				else
				{
					std::cout <<"Неверный пункт меню!"<< std::endl;
				};
			}
			//menu3

			while (true)
			{

				if (menu.menu4_in(buf_string, distance, count, game_type, p_transports))
				{
					std::cout << std::endl;
					break;
				}
				else
				{
					std::cerr << "Неверный пунк меню! \n";
				};
			}
			// menu4
		

			while (true)
			{
			
			menu.menu5();

				unsigned buf_int = 66;
				buf_int = menu.menu5_in();

				if (buf_int == 1) 
				{ menu.menu4_in(buf_string, distance, count, game_type, p_transports); }
					else if (buf_int == 2) 
					{ std::cout << std::endl; break; }
		
			}
			//menu 5
			
		
			

			while (true)
			{
				std::cout << "Результаты гонки: \n";
				sort2arr(p_transports);
				
				for (int i = 0, count = 1; i < rows; i++)
				{
					if (p_transports[i][2] == "1")
					{
			std::cout << count << ". " << std::setiosflags(std::ios::left) << std::setw(20) <<  p_transports[i][0] <<  " has value " << "\t" << stod(p_transports[i][1]) << std::endl;
						count++;
					}
				}

			break;
			}
			//menu results
			std::cout << std::endl;

					while (true)
					{
						int buf_int = (menu.menu6_in());

						if (buf_int == 1)
						{
							for (int i = 0; i < rows; i++)
							{
								p_transports[i][1] = "0";
								p_transports[i][2] = "0";
								p_transports[i][0] = transports2[i];
							}

								count = 0;
								distance = 0;
								buf = 0;
								buf_string = "";
								game_type = 0;
								break;
						}
											
							// то запускаем очистку результатов

						else if (buf_int == 2)

						{
							for (int i = 0; i < rows-1; i++)
							{
								delete[]p_transports[i];
							}
							delete[]p_transports;

							// удаляем всё к чертям 
							return 0;
						}
						else 
						{
							std::cerr << "Неверный пунк меню! \n";
							continue;
						}
						break;
					}
		}
		
	return 0;
}
