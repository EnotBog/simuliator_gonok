#pragma once
#include "Earth_Transport.h"
class Kentavr : protected Earth_Transport
{
public:
    Kentavr() :Kentavr("kentavr", 15, 8) {}
    int metod_finish(int distance)
    {
        int times = distance / (speed_transport); // чистое время без остановок
        return  times + metod_relax(distance, times);// добавляем время с остановками
    }
    int metod_relax(int distance, int times) //метод вычисления общего времени остановок
    {
        int time_relax = 0;
        int buf = times / stamina_transport; // колличество остановок
        time_relax = buf * 2;
        return time_relax;
    }
protected:
    Kentavr(std::string name, int speed, int stamina) :Earth_Transport(name, speed, stamina)
    {

    }
};

