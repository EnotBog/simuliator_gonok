#pragma once
#include "Transport.h"
class Earth_Transport :protected Transport
{
public:
    Earth_Transport();

   virtual double metod_finish(const int distance);

protected:
    Earth_Transport(std::string name, int speed, int stamina);
    
    int stamina_transport; // ����� ��������   �� ������ ��� ��������� ����������

  
};

