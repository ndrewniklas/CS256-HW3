#include <iostream>


static const int size = 1000;
static int tape[size] = {0};
static int* dp = tape;

int main(){
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	while (*dp == 0){
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	while (*dp == 0){
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	(*dp)++;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	(*dp)++;
	(*dp)++;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	(*dp)++;
	(*dp)++;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	if((dp - tape) == 0){
		dp += 999;
	}else{
		dp--;
	}
	if((dp - tape) == 0){
		dp += 999;
	}else{
		dp--;
	}
	if((dp - tape) == 0){
		dp += 999;
	}else{
		dp--;
	}
	if((dp - tape) == 0){
		dp += 999;
	}else{
		dp--;
	}
	(*dp)--;
	}
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)--;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	while (*dp == 0){
	if((dp - tape) == 0){
		dp += 999;
	}else{
		dp--;
	}
	}
	if((dp - tape) == 0){
		dp += 999;
	}else{
		dp--;
	}
	(*dp)--;
	}
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	std::cout << (char)*dp << std::endl;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)--;
	(*dp)--;
	(*dp)--;
	std::cout << (char)*dp << std::endl;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	std::cout << (char)*dp << std::endl;
	std::cout << (char)*dp << std::endl;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	std::cout << (char)*dp << std::endl;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	std::cout << (char)*dp << std::endl;
	if((dp - tape) == 0){
		dp += 999;
	}else{
		dp--;
	}
	(*dp)--;
	std::cout << (char)*dp << std::endl;
	if((dp - tape) == 0){
		dp += 999;
	}else{
		dp--;
	}
	std::cout << (char)*dp << std::endl;
	(*dp)++;
	(*dp)++;
	(*dp)++;
	std::cout << (char)*dp << std::endl;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	std::cout << (char)*dp << std::endl;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	(*dp)--;
	std::cout << (char)*dp << std::endl;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	std::cout << (char)*dp << std::endl;
	if((dp - tape) == 999){
		dp = tape;
	}else{
		dp++;
	}
	(*dp)++;
	(*dp)++;
	std::cout << (char)*dp << std::endl;
	return 0;
}
