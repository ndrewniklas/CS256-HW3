//Andrew Niklas
//Homework 3
//2/10/2016

#include <iostream>
#include <fstream>
#include <vector>

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
		switch(argv[1]){
			case 'c':
			std::ifstream fin(argv[2]);
			compile(fin);
			break;
			
			case 'e':
			std::ifstream fin(argv[2]);
			execute(fin);
			break;
			
			default:
			std::cout << "Invalid argument!  crazy [-ce] [filename.cz]" << std::endl;
			std::cout << "   -c \t compile the given file into C++ and print it out\n";
			std::cout << "   -e \t execute the given file directly" << std::endl;
			break;
		}
	}
	return 0;
}

void compile(ifstream fin){
	
	int brackets = 0;
	
	std::vector<char> code;
	while(fin){
		code.push_back(getc(fin))
	}
	for(int i = 0; i < code.size(); i++){
		switch(code[1]){
			case '+':
			tape[dp]++;
			break;
			
			case '-':
			tape[dp]--;
			break;
			
			case '>':
			if(dp == 999){
				dp = 0;
			}else{
				dp++;
			}
			break;
			
			case '<':
			if(dp == 0){
				dp = 999
			}else{
				dp--;
			}
			break;
			
			case ':':
			std::cout << tape[dp] << std::endl;
			break;
			
			case '.':
			std::cout << (char)tape[dp] << std::endl;
			break;
			
			case '{':
			if(tape[dp] == 0){
				while(brackets != 0){
					if (code[i] == '{'){
						brackets++;
					}else if(code[i] == '}'){
						brackets--
					}
					i++;
				}
			}
			break;
			
			case '}':
			
		}
		
	}
}