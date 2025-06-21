#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <cctype>

 typedef enum Error
{
	OK,
	NEG,
	BAD_IN,
	TOO_LARGE,
	TOO_EARLY
} Error;

class	BitcoinExchange
{
	private:

		std::map<std::string, double> _data;
		BitcoinExchange();

	public:

		BitcoinExchange(const std::string& inputFile);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();

		BitcoinExchange& operator=(BitcoinExchange const & src);

		void	analyzeInputfile(const std::string& inFile);
		Error		analyzeLine(const std::string& line);

};

bool	isValidDate(const std::string& date);
bool	isValidExt(const std::string& fileName);
void	errorMessage(Error errCode, const std::string& line);

#endif