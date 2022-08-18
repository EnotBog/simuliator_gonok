#pragma once
#include "Earth_Transport.h"
class Bot_skorohod :    protected Earth_Transport
{
public:
    //virtual std::string get_type() ;

    Bot_skorohod() :Bot_skorohod("verblud", 6, 60) {}

    int metod_finish(int distance)
    {
        int times = distance / (speed_transport); // чистое время без остановок
        return  times + metod_relax(distance, times);// добавляем время с остановками
    }
    int metod_relax(int distance, int times) //метод вычисления общего времени остановок
    {
        int time_relax = 0;
        int buf = times / stamina_transport; // колличество остановок
        int count = (buf == 0) ? 1 :
            (buf < 0 && buf <= 1) ? 2 :
            (buf >= 2) ? 3 :
            (distance >= 10000) ? 4 :
            5; // throw
        switch (count)
        {
        case 1: time_relax = 0; // если короткий маршрут и не было отдыха
            break;
        case 2: time_relax = 10; // если отдых был 1 раз (10 у.е)
            break;
        case 3: time_relax = (buf - 1) * 5 + 10; // если отдыха было более 1 раза 
            break;
                            //case 5: throw {};
        }
        return time_relax;
    }

protected:
    Bot_skorohod(std::string name, int speed, int stamina) :Earth_Transport(name, speed, stamina)
    {

    }
};

