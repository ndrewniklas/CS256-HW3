//Andrew Niklas
//Homework 3
//2/10/2016

#include <iostream>
#include <fstream>
#include <string>

std::string read(char*);
//void interactive();
//void compile();
void execute();
int getLoopStart(int);
int getLoopEnd(int);

static const int size = 1000;
static int tape[size] = {};
static int* dp = tape;
static std::string code;


	
int main(int argc, char* argv[]){
	
	if(argc == 0){
		//interactive(); 
	}else{
		for(int i = 0; i < argc; i++){
		std::cout << argv[i] << std::endl;
		}
		read(argv[2]);
		
		if(*argv[1] == 'c'){
			//compile();
		}else if(*argv[1] == 'e'){
			execute();
		}else{
			std::cout << "Invalid argument!  crazy [-ce] [filename.cz]" << std::endl;
			std::cout << "   -c \t compile the given file into C++ and print it out\n";
			std::cout << "   -e \t execute the given file directly" << std::endl;
		}
		
	}
	
	return 0;
}

std::string read(char* fileName){
	std::ifstream fin(fileName);
	std::string str;
	while(fin >> str){
		
	}
}

void execute(){
	
	for(int i = 0; i < code.size(); i++){
		switch(code[1]){
			case '+':
			(*dp)++;
			break;
			
			case '-':
			(*dp)--;
			break;
			
			case '>':
			if((dp - tape) == 999){
				dp = tape;
			}else{
				dp++;
			}
			break;
			
			case '<':
			if((dp - tape) == 0){
				dp + 999;
			}else{
				dp--;
			}
			break;
			
			case ':':
			std::cout << dp << std::endl;
			break;
			
			case '.':
			std::cout << (char)*dp << std::endl;
			break;
			
			case '{':
			
			break;
			
			case '}':
			
			break;
		}
		
	}
}