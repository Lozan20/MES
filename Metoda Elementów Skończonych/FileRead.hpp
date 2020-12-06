#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileRead
{
public:
	static std::vector< float > file_read(const char* filepath)
	{
		std::vector<float> data;
		std::fstream file;
		std::string temp;
		try
		{
			file.open(filepath, std::ios::in);
			while (file >> temp)
			{
				data.push_back(std::stof(temp));
			}
		}
		catch (std::ifstream::failure& e)
		{
			std::cout << e.what();
		}
		return data;
	}
};
