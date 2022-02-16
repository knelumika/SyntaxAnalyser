#ifndef _PATTERNANALYSER_H_
#define _PATTERNANALYSER_H_

#include <string>

namespace SyntaxChecker
{
	struct CharactorCount;
	
	class PatternAnalyser
	{
	public:
		//PatternAnalyser() { std::cout << "In PatternAnalyser constructor\n"; }
		void analyseLineForSyntaxErrors(std::string line, CharactorCount &errChrCount, int lineNumber);

	private:
		//std::string _inptFileName;
	};
}

#endif