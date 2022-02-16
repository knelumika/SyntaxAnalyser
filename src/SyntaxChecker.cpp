#include "SyntaxChecker.h"
#include "PatternAnalyser.h"
#include "Utiliser.h"
#include <iostream>
#include <fstream>

void SyntaxChecker::SyntaxErrorAnalyser::setInputFileName(std::string inputFileName)
{
    if (inputFileName.empty())
        std::cout << "Error: Please provide a valid file name" << std::endl;
    else
        _inptFileName = inputFileName;
}

void SyntaxChecker::SyntaxErrorAnalyser::printSyntaxErrorScore(CharactorCount &errChrCount)
{
    std::cout << "Illegal Charactor Count:" << std::endl;
    std::cout << " ')' - " << errChrCount.brcktCount << std::endl;
    std::cout << " ']' - " << errChrCount.sqrBrcktCount << std::endl;
    std::cout << " '}' - " << errChrCount.crlyBrcktCount << std::endl;
    std::cout << " '>' - " << errChrCount.anglBrcktCount << std::endl;

    int errorScore = calculateSyntaxErrorScore(errChrCount);

    std::cout << "The total syntax error score for the file is: " << errorScore << std::endl;

}

int SyntaxChecker::SyntaxErrorAnalyser::calculateSyntaxErrorScore(CharactorCount &errChrCount)
{
    int totErrScore = 0;

    int brcktScore      = errChrCount.brcktCount * 3;
    int sqrBrcktScore   = errChrCount.sqrBrcktCount * 57;
    int crlyBrcktScore  = errChrCount.crlyBrcktCount * 1197;
    int anglBrcktScore  = errChrCount.anglBrcktCount * 25137;

    totErrScore = brcktScore + sqrBrcktScore + crlyBrcktScore + anglBrcktScore;
    return totErrScore;
}

void SyntaxChecker::SyntaxErrorAnalyser::analyseSyntaxErrors(CharactorCount &errChrCount)
{
    if (_inptFileName.empty())
    {
        std::cout << "Error: Please provide a valid file name" << std::endl;
        return;
    }

    //CharactorCount invalidChrCount{};
    errChrCount = {0};
    PatternAnalyser ptrnAnalyser;
    std::ifstream inptFile (_inptFileName);

    std::string line;
    int lineNumber = 0;
    while (std::getline(inptFile, line))
    {
        ptrnAnalyser.analyseLineForSyntaxErrors(line, errChrCount, ++lineNumber);
    }

}

int main(int argc,char* argv[])
{
    std::string inptFileName;

    if (argc > 1)
        inptFileName = argv[1];
    else
    {
        std::cout << "Error: Please provide a valid file name" << std::endl;
        return 1;
    }

    SyntaxChecker::CharactorCount invalidChrCount;

    SyntaxChecker::SyntaxErrorAnalyser sntxErrAnalyser(inptFileName);
    sntxErrAnalyser.analyseSyntaxErrors(invalidChrCount);
    sntxErrAnalyser.printSyntaxErrorScore(invalidChrCount); 

    return 0;
}