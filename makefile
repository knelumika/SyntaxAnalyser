# Makefile for Syntax Checker Project
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
#change the PROJECT_HOME path accordingly
PROJECT_HOME = /home/kasuni/AdventOfCode/SyntaxAnalyser/
CFLAGS = -I $(PROJECT_HOME)/include/
 
# ****************************************************
# Rules to make target

$(PROJECT_HOME)/bin/SyntaxChecker: $(PROJECT_HOME)/src/PatternAnalyser.cpp $(PROJECT_HOME)/src/SyntaxChecker.cpp 
	$(CC) -o $(PROJECT_HOME)/bin/SyntaxChecker $(PROJECT_HOME)/src/PatternAnalyser.cpp $(PROJECT_HOME)/src/SyntaxChecker.cpp $(CFLAGS)
 
