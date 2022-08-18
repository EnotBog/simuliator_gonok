#pragma once
#include "Transport.h"
class Air_Transport :  protected Transport
{
public: 
	Air_Transport() {
		type_transport = "Air";
		name_transport = "uknow";
		speed_transport = 0;
	}

protected:
	Air_Transport(std::string name, int speed)
	{
		type_transport = "Air";
		name_transport = name;
		speed_transport = speed;
	};


//protected:	int short_distance; // Коэффициент сокращения расстояния для воздушного транспорта

/*
* 
*virtual int metod_sokrashenia (int distance)
{

}
*/
};

