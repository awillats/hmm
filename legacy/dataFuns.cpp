#include "dataFuns.h"

std::vector<double> pullParamLine(std::ifstream& paramFile)
{
	//takes a string which looks like "z = [1,2,3,4] and returns "1,2,3,4" as juice
	//and "z = " as label. It's really looking for what's inside the [] and what's before it
	std::string line;
	std::string label;
	std::string juice;


	std::getline(paramFile,line);
	std::stringstream iss(line);
	std::getline(iss, label,'[');
	std::getline(iss, juice,']');
	std::cout << label << juice <<"\n";
	
	std::stringstream sstream(juice);
	if (!sstream.good())
	{
		std::cout << "\n\nERROR:stream bad, probably got to the end of the file??\n\n";
	}

	double num;
	std::vector<double> nums;
	
	while(sstream >> num)
	{
		//std::cout << num << "\n";
		nums.push_back(num);
		//A<<num;
	}
	return nums;
}

