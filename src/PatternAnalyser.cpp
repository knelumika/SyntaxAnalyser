#include "PatternAnalyser.h"
#include "Utiliser.h"
#include <iostream>
#include <stack>

void SyntaxChecker::PatternAnalyser::analyseLineForSyntaxErrors(std::string line, 
																CharactorCount &errChrCount,
																int lineNumber)
{
	std::stack<char> chrSyntaxStack;
	const char *chrLine = line.c_str();

	for (char chr = *chrLine; chr; chr=*++chrLine)
	{
		switch(chr) 
		{
        case ')':
        	//std::cout<<"It is )\n";//TODO
        	if ( (chrSyntaxStack.empty()) || (chrSyntaxStack.top()!='(') )
        	{
            	std::cout << "Line #" << lineNumber << ": Invalid ) found\n";
				errChrCount.brcktCount++;
            	return;
        	}
        	chrSyntaxStack.pop();
        	break;
    	case ']':
        	//std::cout<<"It is ]\n";//TODO
        	if ( (chrSyntaxStack.empty()) || (chrSyntaxStack.top()!='[') )
        	{
            	std::cout << "Line #" << lineNumber << ": Invalid ] found\n";
				errChrCount.sqrBrcktCount++;
            	return;
        	}
        	chrSyntaxStack.pop();
        	break;
        case '}':
        	//std::cout<<"It is }\n";//TODO
        	if ( (chrSyntaxStack.empty()) || (chrSyntaxStack.top()!='{') )
        	{
            	std::cout << "Line #" << lineNumber << ": Invalid } found\n";
				errChrCount.crlyBrcktCount++;
            	return;
        	}
        	chrSyntaxStack.pop();
        	break;
    	case '>':
        	//std::cout<<"It is >\n";//TODO
        	if ( (chrSyntaxStack.empty()) || (chrSyntaxStack.top()!='<') )
        	{
            	std::cout << "Line #" << lineNumber << ": Invalid > found\n";
				errChrCount.anglBrcktCount++;
            	return;
        	}
        	chrSyntaxStack.pop();
        	break;    
        default:
        	chrSyntaxStack.push(chr);
        	//std::cout<<"It is neither\n";//TODO
    	}
	}
}