#include <iostream>
#include <fstream>
#include <string>

std::string find_and_replace(std::string line, std::string to_replace, std::string replace_with)
{
	size_t	pos = line.find(to_replace, 0);
	if (pos == std::string::npos)
		return (line);
	line.erase(pos, to_replace.length());
	line.insert(pos, replace_with);
	return (line);
}

int	open_files(std::string filename, std::ifstream &inputfile, std::ofstream &outputfile)
{
	inputfile.open(filename);
	if (!inputfile.is_open())
	{
		std::cerr << "Inputfile could not be opened" << std::endl;
		return (0);
	}
	outputfile.open(filename + ".replace");
	if (!outputfile.is_open())
	{
		inputfile.close();
		std::cerr << "Outputfile could not be opened" << std::endl;
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	std::string filename = argv[1];
	std::string line;
	std::ifstream inputfile;
	std::ofstream outputfile;

	if (argc != 4)
	{
		std::cerr << "Not ecough or too many inputs!" << std::endl;
		return (-1);
	}
	if (!open_files(filename, inputfile, outputfile))
		return (-1);
	while (!inputfile.eof())
	{
		std::getline(inputfile, line);
		line = find_and_replace(line, argv[2], argv[3]);
		outputfile << line;
	}
	outputfile.close();
	inputfile.close();
}