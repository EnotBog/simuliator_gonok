#pragma once
#include "Air_Transport.h"
class Kover_Samolet :   protected Air_Transport
{

public:
    Kover_Samolet() : Kover_Samolet("kover_samolet", 10) {};

    double metod_finish(int distance)
    {
        return metod_sokrashenia(distance) / speed_transport;
    }
    double metod_sokrashenia(int distance)
    {
        double short_distance = 0;
        int shorts = (distance < 1000 && distance >0) ? 1 :
            (distance < 5000 && distance >= 1000) ? 2 :
            (distance >= 5000 && distance < 10000) ? 3 :
            (distance >= 10000) ? 4 :
            5;
        switch (shorts)
        {
        case 1: short_distance = 1; // если меньше 1000
            break;
        case 2: short_distance = 0.97; // если меньше 5000
            break;
        case 3: short_distance = 0.90; // если больше  5000 меньше 10000
            break;
        case 4: short_distance = 0.95; // если больше  10000
            break;
            //case 5: throw {};
        }
        return distance * short_distance;
    }
protected:
    Kover_Samolet(std::string name, int speed):Air_Transport(name, speed)
    {
      
    }
};

