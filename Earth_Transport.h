#pragma once
#include "Transport.h"
class Earth_Transport :protected Transport
{
public:
    Earth_Transport() 
    {
        type_transport = "Earth";
        name_transport = "uknow";
        speed_transport = 0;
    }
protected:
    Earth_Transport(std::string name, int speed, int stamina):Transport("Eart", name,speed)
    {
        stamina_transport = stamina;
    }
    
    int stamina_transport; // Время движения   до отдыха для наземного транспорта

    //int regeneration_transport; // Длительность отдыха для наземного транпорта
};

