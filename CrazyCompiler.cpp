//Andrew Niklas
//Homework 3
//2/10/2016

#include <iostream>
#include <fstream>
#include <string>

std::string read(char*);
void interactive();
void print(int point);
void compile();
void execute(std::string);
int getLoopStart(int);
int getLoopEnd(int);

static const int size = 1000;
static int tape[size] = {0};
static int* dp = tape;
static std::string code;


	
int main(int argc, char* argv[]){
	//for(int i = 0; i < argc; i++){
	//	std::cout << argv[i] << std::endl;
	//}
	if(argc < 3){
		interactive(); 
	}else{
		
		code = read(argv[2]);
		
		if(std::string(argv[1]) == "-c"){
			compile();
		}else if(std::string(argv[1]) == "-e"){
			execute(code);
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
	return str;
}

void interactive(){
	std::string str;
	//std::cout << "\n entering interactive mode...\n" << std::endl;
	print(dp - tape);
	std::cout << "\n: ";
	std::getline(std::cin, str);
	if(str != "exit"){
		//std::cout << str << std::endl;
		execute(str);
		interactive();
	}
}

void print(int point){
	int min = point - 4;
	int max = min + 8;
	if(min < 0){
		min = 0;
		max = min + 8;
	}else if(max > 999){
		min = max - 8;
		max = 999;
	}
	printf("%-20s", "\nIndex:");
	for(int i = min; i < max; ++i){
		std::cout << i << "\t";
	}
	printf("%-20s", "\nChar values:");
	for(int i = min; i < max; ++i){
		if (tape[i] < 32){
			std::cout << "\\0\t";
		}else{
			std::cout << ((char)tape[i]) << "\t";
		}
	}
	printf("%-20s", "\nInt values:");
	for(int i = min; i < max; ++i){
		std::cout << tape[i] << "\t";
	}
	printf("%-20s", "\nData Pointer:");
	for(int i = min; i < max; ++i){
		if(i == point){
			std::cout << "^\t";
		}else{
			std::cout << " \t";
		}
	}
	std::cout << std::endl;
}

void compile(){
	//std::cout << "\n entering compile mode...\n" << std::endl;
	
	std::cout << "#include <iostream>\n" << std::endl;
	std::cout << "const int SIZE = 1000;\n";
	std::cout << "int tape[SIZE] = {0};\n";
	std::cout << "int* dp = tape;\n" << std::endl;
	std::cout << "int main(){" << std::endl;
	
	int count = 1;	
	for (int i = 0; i < code.length(); ++i){
		for(int t = count; t > 0; --t){
				std::cout << "\t";
		}
		switch(code[i]){
			case '+':
			std::cout << "++*dp;" << std::endl;
			break;
			
			case '-':
			std::cout << "--*dp;" << std::endl;
			break;
			
			case '>':
			std::cout << "++dp;" << std::endl;
			break;
			
			case '<':
			std::cout << "--dp;" << std::endl;
			break;
			
			case ':':
			std::cout << "std::cout << *dp << std::endl;" << std::endl;
			break;
			
			case '.':
			std::cout << "std::cout << ((char)*dp);" << std::endl;
			break;
			
			case '{':
			++count;
			std::cout << "while (*dp){" << std::endl;
			break;
			
			case '}':
			--count;
			std::cout << "}" << std::endl;
			break;
		}
	}
	std::cout << "\treturn 0;" << std::endl;
	std::cout << "}" << std::endl;
}


void execute(std::string codex){
	//std::cout << "\n entering execute mode...\n" << std::endl;
	int brkts = 0;
	for(int i = 0; i < codex.length(); i++){
		switch(codex[i]){
			case '+':
			++*dp;
			break;
			
			case '-':
			--*dp;
			break;
			
			case '>':
			++dp;
			break;
			
			case '<':
			--dp;
			break;
			
			case ':':
			std::cout << *dp;
			break;
			
			case '.':
			std::cout << ((char)*dp);
			break;
			
			case '{':{
				brkts = 0;
				int j = i;
				do{
					if(codex[j] == '{'){
						brkts++;
					}else if(codex[j] == '}'){
						brkts--;
					}
					j++;
				}while(brkts != 0);
				if(*dp == 0){
					i = j + 1;
				}else{
					execute(codex.substr(i + 1, (j - 1)));
				}
			}
			break;
			
			case '}':{
				brkts = 0;
				int j = i;
				do{
					if(codex[j] == '{'){
						++brkts;
					}else if(codex[j] == '}'){
						--brkts;
					}
					--j;
				}while(brkts != 0);
				i = j;
			}
			break;
		}
		
	}
}
