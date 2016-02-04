//Andrew Niklas
//Homework 3
//2/10/2016

#include <iostream>
#include <fstream>
#include <vector>

void read(std::ifstream, std::vector<char>);
void interactive();
void compile();
void execute();
bool test();
int getLoopStart(int);
int getLoopEnd(int);

static const int size = 1000;
static int tape[size] = {};
static int dp = 0;
static std::vector<char> code;

static int* ins;
static int* outs;
	
int main(int argc, char* argv[]){
	
	
	
	if(argc == 0){
		interactive(); 
	}else{
		std::ifstream fin(argv[2]);
		read(fin, code);
		if(test(code, ins, outs)){
			if(*argv[1] == 'c'){
				compile(tape, dp, code);
			}else if(*argv[1] == 'e'){
				execute(tape, dp, code);
			}else{
				std::cout << "Invalid argument!  crazy [-ce] [filename.cz]" << std::endl;
				std::cout << "   -c \t compile the given file into C++ and print it out\n";
				std::cout << "   -e \t execute the given file directly" << std::endl;
			}
		}
	}
	
	delete [] ins;
	delete [] outs;
	
	return 0;
}

void read(){
	
	while(fin){
		code.push_back(getc(fin));
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
	int outAt = 0;
	
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
				break;
		}
	}
	return true;
}

void execute(){
	
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
				dp = 999;
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
			
			break;
			
			case '}':
			
			break;
		}
		
	}
}