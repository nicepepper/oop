// Rle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ParseComandLine.h"
#include "RLEFunctions.h"
#include <iostream>

bool DataCompressionAlgorithmRLE(const ProgramParameters& params)
{
	if (params.mode == Mode::PACK)
	{
		if (!RLEEncoding(params.inputFileName, params.outputFileName))
		{
			std::cout << "An error has happened encoding file" << std::endl;
			return false;
		}
		return true;
	}
	else
	{
		if (!RLEDecoding(params.inputFileName, params.outputFileName))
		{
			std::cout << "An error has happened dencoding file" << std::endl;
			return false;
		}
		return true;
	}
}

int main(int argc, char* argv[])
{
	if (auto params = ParseComandLine(argc, argv))
	{
		return DataCompressionAlgorithmRLE(*params) ? 0 : 1;
	}
	else
	{
		std::cout << "Enter the parameters correctly. Do not forget they should not be empty.\n"
				  << "Usage : Rle.exe pack <input file> <output file>\n"
				  << "        Or\n"
				  << "        Rle.exe unpack <input file> <output file> " << std::endl;
		return 1;
	}
}
