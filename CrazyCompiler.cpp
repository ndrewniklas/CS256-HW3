//Andrew Niklas
//Homework 3
//2/10/2016

#include <iostream>
#include <fstream>
#include <vector>

void read(ifstream, vector<char>);
void interactive();
void compile(vector);
void execute(vector);
bool test();
int getLoopStart(int);
int getLoopEnd(int);

int main(int argc, char** argv){
	
	const int size = 1000;
	int tape[size] = {};
	int dp = 0;
	std::vector<char> code;
	
	int* ins;
	int* outs;
	
	if(argc == 0){
		interactive(); 
	}else{
		switch(argv[1]){
			case 'c':
			std::ifstream fin(argv[2]);
			read(fin);
			if(test()){
				compile(code);
			}
			break;
			
			case 'e':
			std::ifstream fin(argv[2]);
			read(fin);
			if(test()){
				execute(code);
			}
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

void read(ifstream fin, vector<char> code){
	std::vector<char> code;
	while(fin){
		code.push_back(getc(fin))
	}
}

bool test(){
	int x = 0;
	int inB = 0;
	int outB = 0;
	
	for(int i = 0; i < code.size(); i++){
		switch(code[i]){
			case '{':
				x++;
				inB++;
				break;
			
			case '}':
				outB++;
				break;
		}
		if(outB > inB){
			return false;
		}
	}
	
	ins = new int[x];
	outs = new int[x];
	int inAt = 0;
	ont outAt = 0;
	
	for(int i = 0; i < code.size(); i++){
		switch(code[i]){
			case '{':
				ins[inAt] = i;
				outAt = inAt;
				inAt++;
				break;
				
			case '}':
				for(int j = outAt; j >= 0; j--){
					if(outs[j] == 0){
						outs[j] = i;
						break;
					}
				}
				break:
		}
	}
	return true;
}

void compile(code){
	
	
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
			}else{
				inPoint = i;
			}
			break;
			
			case '}':
			
		}
		
	}
}