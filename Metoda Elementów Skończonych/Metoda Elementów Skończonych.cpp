#include <fstream>
#include <iostream>
#include <string>
#include <vector>


#include "FemGrid.hpp"


constexpr auto FILEPATH = "data.txt";

int main()
{
	GlobalData gl(FILEPATH);
	FemGrid fg(gl);
	
}


