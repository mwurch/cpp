#include <iostream>
#include <fstream>
#include <string>

std::string find_and_replace(std::string line, std::string to_replace, std::string replace_with)
{
	size_t	pos = line.find(to_replace, 0);
	while (pos != std::string::npos)
	{
		line.erase(pos, to_replace.length());
		line.insert(pos, replace_with);
		pos = line.find(to_replace, 0);
	}
	return (line);
}

int	open_files(char *filename, std::ifstream &inputfile, std::ofstream &outputfile)
{
	std::string _filename = filename;
	std::string outfile = _filename + ".replace";
	inputfile.open(filename);
	if (!inputfile.is_open())
	{
		std::cerr << "Inputfile could not be opened" << std::endl;
		return (0);
	}
	outputfile.open(outfile.c_str());
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
	std::string line;
	std::ifstream inputfile;
	std::ofstream outputfile;

	if (argc != 4)
	{
		std::cerr << "Not enough or too many inputs!" << std::endl;
		return (-1);
	}
	if (!open_files(argv[1], inputfile, outputfile))
		return (-1);
	while (std::getline(inputfile, line))
	{
		line = find_and_replace(line, argv[2], argv[3]);
		outputfile << line;;
		if (!inputfile.eof())
			outputfile << "\n";
	}
	outputfile.close();
	inputfile.close();
}