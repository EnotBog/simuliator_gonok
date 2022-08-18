#pragma once
#include <string>
class Transport
{
public:
	// virtual int func_Time_Calculation (Transport* q, int distance)
	//return distance/ 
	/*virtual std::string get_type() 
	{
		return type_transport;
	}*/

	Transport() {
		type_transport = "uknow";
		name_transport = "uknow";
		speed_transport = 0;
	}
protected:
	std::string name_transport;
	std::string type_transport;
	int speed_transport;

	Transport(std::string type, std::string name, int speed)
	{
		type_transport = type;
		name_transport = name;
		speed_transport = speed;
	};

};

