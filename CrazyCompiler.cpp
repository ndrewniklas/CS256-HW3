//Andrew Niklas
//Homework 3
//2/10/2016

#include <iostream>
#include <fstream>

void interactive();
void compile(ifstream);
void execute(ifstream);

int main(int argc, char** argv){
	
	int size = 1000;
	int tape[size] = {};
	int dp = 0;
	
	if(argc == 0){
		interactive(); 
	}else{
		switch(argv[1])
			case: 'c'
			std::ifstream fin(argv[2]);
			compile(fin);
			break;
			
			case: 'e'
			std::ifstream fin(argv[2]);
			execute(fin);
			break;
	}
	
	return 0;
}