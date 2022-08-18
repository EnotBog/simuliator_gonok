#pragma once
#include "Air_Transport.h"
class Orel : protected Air_Transport
{
public:
	Orel():Orel("orel", 8) {}

    double metod_finish(int distance) 
    {
        return metod_sokrashenia(distance)/ speed_transport;
    }


    double metod_sokrashenia(int distance)
    {
       return distance * 0.94;
    }

protected:
	Orel(std::string name, int speed) :Air_Transport(name, speed)
    {
	 
	}

};

