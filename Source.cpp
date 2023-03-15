#include <iostream>
#include <windows.h>
#include <locale.h>
#include "Menu.cpp"

/// поменять местами ключ и занчение стоит



int main(int argc, char** argv)
{


	//SetConsoleOutputCP(65001);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int rows = 7;
	const int colums = 3;

	std::map <std::string, std::string> map_transports; // 

	std::string** p_transports = new std::string * [rows]; // 1 имя 2 результат 3 индикатор

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

				if (menu.menu4_in(buf_string, distance, count, game_type, p_transports, map_transports))
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
				{ menu.menu4_in(buf_string, distance, count, game_type, p_transports, map_transports); }
					else if (buf_int == 2) 
					{ std::cout << std::endl; break; }
		
			}
			//menu 5
			
		
			

			while (true)
			{
				std::cout << "Результаты гонки: \n";
				unsigned i = 1;
				for (const auto& kv : map_transports) /// ПЕРЕПИСАТЬ ЧТО БЫ БЫЛ ИНКРЕМЕН I
				{
					
					std::cout << i<<". " << kv.first << " has value " << kv.second << std::endl;
					i++;
				}


			/*	if (menu.menu_results(p_transports, rows))
				{
					break;
				};*/
				break;
			}
			//menu results
			std::cout << std::endl;

					while (true)
					{
						int buf_int = (menu.menu6_in());

						if (buf_int == 1)
						{
							for (int i = 0; i < rows - 1; i++)
							{
								p_transports[i][1] = "0";
								p_transports[i][2] = "0";
							}

								count = 0;
								distance = 0;
								buf = 0;
								buf_string = "";
								game_type = 0;
								map_transports.clear();
						break;
						}
											
							// то запускаем очистку результатов

						else if (buf_int == 2)

						{
							for (int i = 0; i < rows-1; i++)
							{
								delete[]p_transports[i];
							}

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
