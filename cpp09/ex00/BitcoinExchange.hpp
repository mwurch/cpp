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

		BitcoinExchange(std::string inputFile);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();

		BitcoinExchange& operator=(BitcoinExchange const & src);

		void	analzyeInputfile(std::string inFile);
		Error		analyzeLine(std::string line);

};

bool	isValidDate(std::string date);
bool	isValidExt(std::string fileName);
void	errorMessage(Error errCode, std::string line);

#endif