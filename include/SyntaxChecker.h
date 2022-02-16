#ifndef _SYNTAXCHECKER_H_
#define _SYNTAXCHECKER_H_

#include <string>

namespace SyntaxChecker
{
	struct CharactorCount;

	class SyntaxErrorAnalyser
	{
	public:
		SyntaxErrorAnalyser() {}
		SyntaxErrorAnalyser(std::string inputFileName):_inptFileName(inputFileName) {}
		void setInputFileName(std::string inputFileName);
		void analyseSyntaxErrors(CharactorCount &errChrCount);
		void printSyntaxErrorScore(CharactorCount &errChrCount);

	private:
		int calculateSyntaxErrorScore(CharactorCount &errChrCount);

		std::string _inptFileName;
	};
}

#endif