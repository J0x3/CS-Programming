#pragma once
class parseTools
{
public:
	std::string str;
	parseTools();
	~parseTools();
	void parseString(std::string str);
	int getSize();
	void checkStack();
	void cleanStack();
};

