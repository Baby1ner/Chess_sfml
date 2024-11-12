#pragma once

#include <vector>
class Coordinates
{

	

public:

	int xcoor;
	int ycoor;

	Coordinates(int C_xcoor, int C_ycoor) {
		xcoor = C_xcoor;
		ycoor = C_ycoor;
	}

	Coordinates(int coor) {
		xcoor = coor % 8;
		ycoor = coor / 8;
	}
	Coordinates() {	}


	int GetInt() {
		return xcoor + ycoor * 8;
	}


	









};

