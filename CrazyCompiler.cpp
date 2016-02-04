//Andrew Niklas
//Homework 3
//2/10/2016

#include <iostream>
#include <fstream>
#include <string>

std::string read(char*);
void interactive();
void compile();
void execute();
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
	return str;
}

void interactive(){
	std::cout << "\n entering interactive mode...\n" << std::endl;
}

void compile(){
	std::cout << "\n entering compile mode...\n" << std::endl;
	
	std::cout << "#include <iostream>\n\n" << std::endl;
	std::cout << "static const int size = 1000;\n";
	std::cout << "static int tape[size] = {0};\n";
	std::cout << "static int* dp = tape;\n" << std::endl;
	std::cout << "int main(){" << std::endl;
	
	for (int i = 0; i < code.length(); ++i){
		switch(code[i]){
			case '+':
			std::cout << "\t(*dp)++;" << std::endl;
			break;
			
			case '-':
			std::cout << "\t(*dp)--;" << std::endl;
			break;
			
			case '>':
			std::cout << "\tif((dp - tape) == 999){\n\t\tdp = tape;\n";
			std::cout << "\t}else{\n\t\tdp++;\n\t}" << std::endl;
			break;
			
			case '<':
			std::cout << "\tif((dp - tape) == 0){\n\t\tdp += 999;\n";
			std::cout << "\t}else{\n\t\tdp--;\n\t}" << std::endl;
			break;
			
			case ':':
			std::cout << "\tstd::cout << dp << std::endl;" << std::endl;
			break;
			
			case '.':
			std::cout << "\tstd::cout << (char)*dp << std::endl;" << std::endl;
			break;
			
			case '{':
			std::cout << "\twhile (*dp == 0){" << std::endl;
			break;
			
			case '}':
			std::cout << "\t}" << std::endl;
			break;
		}
	}
	std::cout << "\treturn 0;" << std::endl;
	std::cout << "}" << std::endl;
}


void execute(){
	std::cout << "\n entering execute mode...\n" << std::endl;
	for(int i = 0; i < code.length(); i++){
		switch(code[i]){
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
				dp += 999;
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
				if(*dp == 0){
				
				}
			
			break;
			
			case '}':
			
			break;
		}
		
	}
}
