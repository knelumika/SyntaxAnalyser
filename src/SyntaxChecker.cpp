#include "SyntaxChecker.h"
#include "PatternAnalyser.h"
#include "Utiliser.h"
#include <iostream>

void SyntaxChecker::SyntaxErrorAnalyser::setInputFileName(std::string inputFileName)
{
    if (inputFileName.empty())
        std::cout << "Error: Please provide a valid file name" << std::endl;
    else
        _inptFileName = inputFileName;
}

int SyntaxChecker::SyntaxErrorAnalyser::calculateSyntaxErrorScore(CharactorCount &errChrCount)
{
    int totErrScore = 0;

    return totErrScore;
}

void SyntaxChecker::SyntaxErrorAnalyser::analyseSyntaxErrors(CharactorCount &errChrCount)
{

}


int main()
{
    std::string inptFileName = "/home/kasuni/PracticeCode/c++/SyntaxChecker/navigation_subsystem.txt"; //TODO temp
    //SyntaxChecker::SyntaxErrorAnalyser *sntxChkr_1 = new SyntaxChecker::SyntaxErrorAnalyser();
    SyntaxChecker::CharactorCount invalidChrCount;

    SyntaxChecker::SyntaxErrorAnalyser sntxErrAnalyser(inptFileName);
    sntxErrAnalyser.analyseSyntaxErrors(invalidChrCount);  

    return 0;
}