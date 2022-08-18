#pragma once
#include "Air_Transport.h"
class Metla : protected Air_Transport
{
public:Metla():Metla("metla",20) {}

      double metod_finish(int distance)
      {
          return metod_sokrashenia(distance) / speed_transport;
      }


      double metod_sokrashenia(int distance)
      {
          return ((100.00 - floor((distance / 1000))) / 100) * distance;  //увеличивается на 1% за каждую 1000 у.е. расстояния  например, для расстояния 5600 коэффициент будет 5 %
      }

protected:
	Metla(std::string name, int speed) :Air_Transport(name, speed) {}
};

