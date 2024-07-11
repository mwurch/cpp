#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::BitcoinExchange(std::string dataFile)
{
	std::string line;
	std::string date;
	std::string value;
	double		doubleValue;

	if (!isValidExt(dataFile))
		throw (std::runtime_error("Wrong datafile extention. *.csv file needed"));
	std::ifstream file(dataFile.c_str());
	if (!file.is_open())
		throw (std::runtime_error("Failed to open file: " + dataFile));
	std::getline(file, line);
	line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
	line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
	if (line != "date,exchange_rate")
		throw (std::runtime_error("Wrong Data Structure! Datafile must start with 'date,exchange_rate' and all following lines are data"));
	while (std::getline(file, line))
	{
		if (line[0]== 0)
		 continue;
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
		date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
		if (!isValidDate(date))
		{
			file.close();
			throw (std::logic_error("Fatal: Invalid Date in " + dataFile));
		}
		std::getline(ss, value);
		std::istringstream iss(value);
		if (iss>>doubleValue)
			_data[date] = doubleValue;
		else
		{
			file.close();
			throw (std::logic_error("Fatal: Non numeric data was found in " + dataFile ));
		}
		if (iss.peek() != EOF)
		{
			file.close();
			throw (std::logic_error("Fatal: excess data was found" + dataFile ));	
		}
	}
	file.close();
}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const & src)
{
	if (this != &src)
	{
		this->_data.clear();
		for (std::map<std::string, double>::const_iterator it = src._data.begin(); it != src._data.end(); ++it)
		{
			std::string date = it->first;
			double value = it->second;
			this->_data[date] = value;
		}
	}
	return (*this);
}

Error		BitcoinExchange::analyzeLine(std::string line)
{
	std::string date;
	std::string value;
	double		btc_Count;

	std::istringstream iss(line);

	std::getline(iss, date , '|');
	std::getline(iss, value);
	date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
	date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));

	std::istringstream ss(value);
	if (!(ss>>btc_Count))
		return BAD_IN;
	else if (ss.peek() != EOF)
		return BAD_IN;
	else if (btc_Count > 1000)
		return TOO_LARGE;
	else if (btc_Count < 0)
		return NEG;
	else if (!isValidDate(date))
		return BAD_IN;

	std::map<std::string, double>::iterator it = _data.lower_bound(date);
	if (it != _data.end())
	{
		if (it == _data.begin() && _data.begin()->first != date)
			return TOO_EARLY;
		if (it->first != date && it != _data.begin())
			it--;
	}
	else
		if (!_data.empty())
			it--;
	std::cout << it->first << " => " << btc_Count * it->second << std::endl;
	return OK;
}

void	BitcoinExchange::analzyeInputfile(std::string inFile)
{
	std::string line;
	Error	errCode;

	std::ifstream file(inFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Fatal: " + inFile + " was not found");
	if (std::getline(file, line))
	{
		line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
		line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
		if (line == "date | value")
		{
			while (std::getline(file, line))
			{
				errCode = analyzeLine(line);
				if (errCode != OK)
					errorMessage(errCode, line);
			}
		}
		else
			std::cerr << "Wrong or missing header row in inputfile" << std::endl;
	}
	else
		throw (std::runtime_error("Fatal: Inputfile is empty"));
	(void)errCode;
}

void	errorMessage(Error errCode, std::string line)
{
	switch (errCode)
	{
		case OK:
		case NEG:
			std::cout << "Error: not a positive number: " << line << std::endl;
			break;
		case BAD_IN:
			std::cout << "Error: bad input: " << line << std::endl; 
			break;
		case TOO_EARLY:
			std::cout << "Error: date too early: " << line << std::endl;
			break;
		case TOO_LARGE:
			std::cout << "Error: number over 1000: " << line << std::endl;
			break;
		default:
			break;
	}
}


bool	isValidDate(std::string date)
{
	int year, month, day;
	char c1, c2;
	int	monthLen = 31;

	std::istringstream iss(date);
	iss >> year >> c1 >> month >> c2 >> day;
	if (iss.fail() || c1 != '-' || c2 != '-')
		return false;
	if (iss.peek() != EOF)
		return false;
	if (year < 0 || month < 1 || day < 1 || month > 12)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		monthLen = 30;
	else if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			monthLen = 29;
		else
			monthLen = 28;
	}
	if (day > monthLen)
		return false;
	return true;
}

bool	isValidExt(std::string fileName)
{
	const std::string ext = ".csv";

	if (fileName.size() <= ext.size())
		return false;
	return (fileName.substr(fileName.size() - ext.size()) == ext);
}