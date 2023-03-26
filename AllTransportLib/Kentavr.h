#pragma once
#include "Earth_Transport.h"
class  Kentavr : protected Earth_Transport
{
public:
    ALLTRANSPORTLIB_API   Kentavr();

    ALLTRANSPORTLIB_API   double metod_finish(const int distance) override;
protected:


    ALLTRANSPORTLIB_API   Kentavr(std::string name, int speed, int stamina);

    ALLTRANSPORTLIB_API   int metod_relax(const int distance, const int times);  //метод вычисления общего времени остановок
   
};

