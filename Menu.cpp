#include <iostream>
#include <string>
#include <stdlib.h>
#include "All_Transport.h"
#include <map>




class Menu
{
public:
	Menu() {}

	//void swap_mass(std::string** mass, int& left, int& right)//если левый элемент больше правого 
	//{
	//	std::string buf[1][3];


	//	for (int i = 0; i < 3; i++)
	//	{
	//		buf[0][i] = mass[left][i];
	//	}

	//	for (int i = 0; i < 3; i++)
	//	{
	//		mass[left][i] = mass[right][i];
	//		mass[right][i] = buf[0][i];
	//	}
	//}

	void menu1() const
	{
		std::cout << " 1. Гонка для наземного транспорта " << "\n" << " 2. Гонка для воздушного транспорта " << "\n" << " 3. Гонка для наземного и воздушного транспорта" << "\n" << " Выберите тип гонки: ";

	};

	bool menu1_in(std::string& buf_string, int& game_type)
	{
		int buf = 66;
		while (true)
		{
			menu1();
			std::cin >> buf;
			if (std::cin.fail())
			{
				std::cerr << "Неизвестный тип данных! \n";
				std::cin.clear();
				std::string buf_cin;
				getline(std::cin, buf_cin);
				std::cin.ignore();
				continue;
			}
			if ((buf != 1) && (buf != 2) && (buf != 3)) { return false; }
			else
			{
				buf_string = (buf == 1) ? +"Гонка для наземного транспорта" :
					(buf == 2) ? +"Гонка для воздушного транспорта" : +"Гонка для наземного и воздушного транспорта";
				game_type = (buf == 1) ? 1 :
					(buf == 2) ? 2 : 3;
			}
			break;

		}
		return true;
	};

	void menu2(std::string& buf_string) const
	{
		std::cout << buf_string << "\n" << "Укажите длину дистанции(должна быть положительная)" << "\n";
	}

	bool menu2_in(std::string& buf_string, int& distance)
	{

		int buf = 66;
		while (true)
		{

			menu2(buf_string);

			std::cin >> buf;
			if (std::cin.fail())
			{
				std::cerr << " Введен неверный формат данных! \n";
				std::cin.clear();
				std::string buf_cin;
				getline(std::cin, buf_cin);
				std::cin.ignore();
				continue;
			}
		

			if (buf <= 0) { return false; }
			else
			{
				distance = buf;
				buf_string = buf_string + " Расстояние: " + std::to_string(distance) + " ";
				break;
			}

		}
		return true;
	}

	void menu3() const
	{
		std::cout << "Должно быть зарегистрированно минимум 2 транспортных средства \n"
			"1. Зарегистрировать транспортное средство \n"
			"Выберите действие: ";
	}

	bool menu3_in()
	{
		int buf = 66;
		std::cin >> buf;
		if (std::cin.fail())
		{
			std::cerr << "Неизвестный тип данных! \n";
			std::cin.clear();
			std::string buf_cin;
			getline(std::cin, buf_cin);
			std::cin.ignore();
			return false;
		}
		if (buf == 1) { return true; }
		else
		{
			return false;
		}
	}

	void menu4(std::string& buf_string) const
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
	}

	bool menu4_in(std::string& buf_string,const int& distance, int& count,const int& game_type, std::string** transports, std::map<std::string, std::string> &map_transports )
	{


		while (true)
		{
			menu4(buf_string);
			int buf = 66;
			std::cin >> buf;

			if (std::cin.fail())
			{
				std::cerr << " Введен неверный формат данных! \n";
				std::cin.clear();
				std::string buf_cin;
				getline(std::cin, buf_cin);
				std::cin.ignore();
				continue;
			}

			if (buf == 0)
			{
				if (count > 1) { return true; }
				else { std::cerr << " Недостаточно транспортных средств для начала гонки! \n"; continue; }
			} // выход из цикла если условин норм 


			if (buf == 1)  //добавить провверку на тип гонки
			{
				if (game_type == 2)
				{
					std::cerr << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
					continue;
				}
				if (transports[0][2] != "1")
				{
					Bot_skorohod botinok; transports[0][1] = std::to_string(botinok.metod_finish(distance)); buf_string = buf_string + " " + transports[0][0]; transports[0][2] = "1";
					std::cout << transports[0][0] << " успешно зарегистрированны! \n "; count += 1;

					map_transports[std::to_string(botinok.metod_finish(distance))] =  transports[0][0];//// СМОТРИ СЮДА ТУТ МАП.

					continue;
				}
				else
				{
					std::cerr << transports[0][0] << " уже зарегистрирован \n";
					continue;
				}
			}



			if (buf == 2)
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
					
					map_transports[std::to_string(metla.metod_finish(distance))] =  transports[1][0];

					continue;
				}
				else
				{
					std::cerr << transports[1][0] << " уже зарегистрирован \n";
					continue;
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
					
					map_transports[std::to_string(verblud.metod_finish(distance))] = transports[2][0];

					continue;
				}
				else
				{
					std::cerr << transports[2][0] << " уже зарегистрирован \n";
				}
			}



			if (buf == 4)
			{
				if (game_type == 2)
				{
					std::cerr << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
					continue;
				}

				if (transports[3][2] != "1")
				{
					Kentavr kentavr;  transports[3][1] = std::to_string(kentavr.metod_finish(distance)); buf_string = buf_string + " " + transports[3][0]; transports[3][2] = "1";
					std::cout << transports[3][0] << " успешно зарегистрированны! \n "; count += 1;
					
					map_transports[std::to_string(kentavr.metod_finish(distance))] = transports[3][0];

					continue;
				}
				else
				{
					std::cerr << transports[3][0] << " уже зарегистрирован \n";
				}
			}

			if (buf == 5)
			{
				if (game_type == 1)
				{
					std::cerr << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
					continue;
				}
				if (transports[4][2] != "1")
				{
					Orel orel;  transports[4][1] = std::to_string(orel.metod_finish(distance)); buf_string = buf_string + " " + transports[4][0]; transports[4][2] = "1";
					std::cout << transports[4][0] << " успешно зарегистрированны! \n "; count += 1;
					
					map_transports[std::to_string(orel.metod_finish(distance))] =  transports[4][0];

					continue;
				}
				else
				{
					std::cerr << transports[4][0] << " уже зарегистрирован \n";
					continue;
				}
			}


			if (buf == 6)
			{
				if (game_type == 2)
				{
					std::cerr << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
					continue;
				}

				if (transports[5][2] != "1")
				{
					Verblud_fast verblud_fast;  transports[5][1] = std::to_string(verblud_fast.metod_finish(distance)); buf_string = buf_string + " " + transports[5][0]; transports[5][2] = "1";
					std::cout << transports[5][0] << " успешно зарегистрированны! \n "; count += 1;
					
					map_transports[std::to_string(verblud_fast.metod_finish(distance))] =  transports[5][0];

					continue;
				}
				else
				{
					std::cerr << transports[5][0] << " уже зарегистрирован \n";
				}
			}

			if (buf == 7)
			{
				if (game_type == 1)
				{
					std::cerr << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
					continue;
				}
				if (transports[6][2] != "1")
				{
					Kover_Samolet kover_samolet;  transports[6][1] = std::to_string(kover_samolet.metod_finish(distance)); buf_string = buf_string + " " + transports[6][0]; transports[6][2] = "1";
					std::cout << transports[1][0] << " успешно зарегистрированны! \n "; count += 1;
					
					map_transports[std::to_string(kover_samolet.metod_finish(distance))] =  transports[6][0];

					continue;
				}
				else
				{
					std::cerr << transports[6][0] << " уже зарегистрирован \n";
					continue;
				}
			}


			if (buf < 0 || buf>8)
			{
				std::cerr << "Неверный пункт меню \n";
				continue;
			}

		}

	}



	void menu5() const
	{
		std::cout << "1. Зарегистрировать транспорт \n"
			"2. Начать гонку  \n"
			"Выберите действие: ";
	}


	int menu5_in()
	{
		int buf = 66;
		while (true)
		{
			std::cin >> buf;
			if (std::cin.fail())
			{
				std::cerr << "Неверный формат данных! \n";
				std::cin.clear();
				std::string buf_cin;
				getline(std::cin, buf_cin);
				std::cin.ignore();
				continue;

			}
			if (buf == 1) { return 1; }
			if (buf == 2) { return 2; }
			else
			{
				std::cerr << "Неверный пунк меню! \n";
				continue;
			}

		}

	}


		/*
		for (int i = 0; i < rows - 1; i++)
	bool menu_results(std::string** transports, int rows) const   
	{
		//func_sort(transports);

	

		
		{
			if (transports[i][2] == "1") { std::cout << transports[i][0] << " " << transports[i][1] << std::endl; }
		}

		std::cout << std::endl;
	}
		return true;
		*/
	int menu6_in()
	{
		int buf = 66;
		while (true)
		{
			std::cout << "1. Провести еще одну гонку \n2. Выйти \n";
			std::cin >> buf;

			if (std::cin.fail())
			{
				std::cerr << " Введен неверный формат данных! \n";
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			return buf;
		}
	}
};





	



