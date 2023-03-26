#pragma once
#include "Transport.h"
class    Earth_Transport :protected Transport
{
public:
    ALLTRANSPORTLIB_API  Earth_Transport();

    ALLTRANSPORTLIB_API  virtual double metod_finish(const int distance);

protected:
    ALLTRANSPORTLIB_API   Earth_Transport(std::string name, int speed, int stamina);
    
    int stamina_transport; // Время движения   до отдыха для наземного транспорта

  
};

