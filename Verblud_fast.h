#pragma once
#include "Earth_Transport.h"
class Verblud_fast : protected Earth_Transport
{
public:

    Verblud_fast();

    double metod_finish(const int distance) override;

protected:
    Verblud_fast(const std::string &name,const int speed,const int stamina);

    double metod_relax(const int distance, const int times); //метод вычисления общего времени остановок

};

