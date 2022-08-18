#include <iostream>
#include <windows.h>
#include <locale.h>
#include <list>
#include "Transport.h"
#include "Kover_Samolet.h"
#include "Orel.h"
#include "Metla.h"
#include "Verblud.h"
#include "Verblud_fast.h"
#include "Kentavr.h"
#include "Bot_skorohod.h"



int main(int argc, char** argv)
{

	//SetConsoleOutputCP(65001);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	//int a = 0, b = 1;
	//int q = (a-- + b) + a;

	//Kover_Samolet kovrik;
	//Orel orlik;
	//Metla metelka;
	//Verblud ubludok;
	//Verblud_fast verblud_fast;
	//Kentavr kentavrik;
	//Bot_skorohod shlepak;




	std::cout << " Добро пожаловать в гоночный симулятор! " << "\n";
	while (true)
	{
		std::string buf_string;
		int buf = 666;
		int distance = 0;
		int count = 0; // счетчик зарегистрированных тс
		int game_type = 0;

		std::string transports[7][3] = { {"Ботинки-вездеходы","0","0"},{"Метла","0","0"}, {"Верблюд","0","0"}, {"Кентавр","0","0"}, {"Орел","0","0"}, {"Верблюд-быстроход","0","0"}, {"Ковёр-самолёт","0","0"} };

		while (true)
		{
			std::cout << " 1. Гонка для наземного транспорта " << "\n" << " 2. Гонка для воздушного транспорта " << "\n" << " 3. Гонка для наземного и воздушного транспорта" << "\n" << " Выберите тип гонки: ";
			std::cin >> buf;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
			}
			if ((buf != 1) && (buf != 2) && (buf != 3)) { std::cerr << "Неизвестный тип гонки!" << "\n"; continue; }
			else
			{
				buf_string = (buf == 1) ? +"Гонка для наземного транспорта"  :
					(buf == 2) ? +"Гонка для воздушного транспорта" : +"Гонка для наземного и воздушного транспорта";
				game_type = (buf == 1) ? 1:
							(buf == 2) ? 2: 3;
			}

			break;
		}


		while (true)
		{
			std::cout << buf_string << "\n" << "Укажите длину дистанции(должна быть положительная)" << "\n";
			std::cin >> buf;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
			}
			if (buf <= 0) { std::cerr << "Неправильно введены данные! \n";  continue; }
			else
			{
				distance = buf;
				buf_string = buf_string + " Расстояние: " + std::to_string(distance)+ " ";
			}
			break;
		}

		while (true)
		{
			while (true)
			{
				std::cout << "Должно быть зарегистрированно минимум 2 транспортных средства \n"
					"1. Зарегистрировать транспортное средство \n"
					"Выберите действие: ";

				std::cin >> buf;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
				}
				if (buf == 1) { break; }
				else
				{
					continue;
				}
				

			}

			while (true)
			{

				std::cout << buf_string << std::endl;

				std::cout <<
					"1. Ботинки-вездеходы \n"
					"2. Метла \n"
					"3. Верблюд \n"
					"4. Кентавр \n"
					"5. Орел \n"
					"6. Верблюд-быстроход \n"
					"7. Ковёр-самолёт \n"
					"0. Закончить регистрацию\n"
					"Выберите транспорт или 0 для окончания процесса регистрации: \n";

				/*while (true)
				{

				}*/

				std::cin >> buf;

				if (std::cin.fail())
				{
					std::cout << " Введен неверный формат данных! \n";
					std::cin.clear();
					std::cin.ignore();
				}

				if (buf == 0)
				{
					if (count > 1) { break; }
					else { std::cout << " Недостаточно транспортных средств для начала гонки! \n"; continue; }
				} // выход из цикла если условин норм 


				if (buf == 1)  //добавить провверку на тип гонки
				{
					if (game_type==2) 
					{
						std::cerr << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
						continue;
					}
					if(transports[0][2] != "1")
					{
						Bot_skorohod botinok; transports[0][1] = std::to_string(botinok.metod_finish(distance)); buf_string = buf_string + " " + transports[0][0]; transports[0][2] = "1";
						std::cout << transports[0][0] << " успешно зарегистрированны! \n "; count+=1;
					}
					else
					{
						std::cerr << transports[0][0] << " уже зарегистрирован \n";
					}
				}

				if (buf==2) 
				{
					if (game_type == 1)
					{
						std::cerr << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
						continue;
					} 
					if (transports[1][2] != "1")
					{
						Metla metla;  transports[1][1] = std::to_string(metla.metod_finish(distance)); buf_string = buf_string + " " + transports[1][0]; transports[1][2] = "1";
						std::cout << transports[1][0] << " успешно зарегистрированны! \n "; count += 1;
					}
					else
					{
						std::cerr << transports[1][0] << " уже зарегистрирован \n";
					}
				}

					if (buf == 3)
					{
					if (game_type == 2)
							{
							std::cerr << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
							continue;
						}

					if (transports[2][2] != "1")
					{
						Verblud verblud;  transports[2][1] = std::to_string(verblud.metod_finish(distance)); buf_string = buf_string + " " + transports[2][0]; transports[2][2] = "1";
						std::cout << transports[2][0] << " успешно зарегистрированны! \n "; count += 1;
					}
					else
					{
						std::cerr << transports[2][0] << " уже зарегистрирован \n"; 
					}
					}


				/////////////////////


			}
			
				std::cout << "Результаты гонки: \n";

				for (int i = 0; i < 8; i++)
				{
					if (transports[i][2] == "1") { std::cout << transports[i][0] << " " << transports[i][1] << std::endl; }
				}
				break;


			
		}

		std::cout << "1. Провести еще одну гонку \n2. Выйти \n";
		std::cin >> buf;

		if (std::cin.fail())
		{
			std::cout << " Введен неверный формат данных! \n";
			std::cin.clear();
			std::cin.ignore();
		}

		if (buf == 2) { break; }
		else 
		{
			for (int i = 0;  i < 7; i++)
			{
				transports[i][1] = "0";
			}
			count = 0;
			distance = 0;
			buf = 0;
			buf_string = "";
		}
		
	}




	//std::cout << kovrik.metod_finish(distance) << " kovrik "<< std::endl << orlik.metod_finish(distance) << " orlik "<< std::endl 
	//		  << metelka.metod_finish(distance)<<" metelka " << std::endl;
	//std::cout << ubludok.metod_finish(distance) << "ubludok" << std::endl << verblud_fast.metod_finish(distance) << "verb fast " << std::endl 
	//		  << kentavrik.metod_finish(distance) << " kentavrik " << std::endl<< shlepak.metod_finish(distance)<<" shlepak ";
	//


	return 0;

}
