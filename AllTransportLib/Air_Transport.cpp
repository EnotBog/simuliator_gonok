﻿#include "Air_Transport.h"

Air_Transport::Air_Transport() {
	type_transport = "Air";
	name_transport = "uknow";
	speed_transport = 0;
}

ALLTRANSPORTLIB_API double Air_Transport::metod_finish(int distance)
{
	return 0;
}

Air_Transport::Air_Transport(std::string name, int speed)
{
	type_transport = "Air";
	name_transport = name;
	speed_transport = speed;
};
