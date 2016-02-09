#include <iostream>

const int SIZE = 1000;
int tape[SIZE] = {0};
int* dp = tape;

int main(){
	++*dp;
	++*dp;
	++*dp;
	++*dp;
	++*dp;
	while (*dp){
		--*dp;
		++dp;
		++*dp;
		++dp;
		++*dp;
		--dp;
		--dp;
		}
	++dp;
	++dp;
	--*dp;
	while (*dp){
		--*dp;
		--dp;
		--dp;
		++*dp;
		++dp;
		++dp;
		}
	--dp;
	--dp;
	while (*dp){
		++dp;
		while (*dp){
			--*dp;
			--dp;
			while (*dp){
				--*dp;
				++dp;
				++dp;
				++*dp;
				++dp;
				++*dp;
				--dp;
				--dp;
				--dp;
				}
			++dp;
			++dp;
			++dp;
			while (*dp){
				--*dp;
				--dp;
				--dp;
				--dp;
				++*dp;
				++dp;
				++dp;
				++dp;
				}
			--dp;
			--dp;
			}
		++dp;
		while (*dp){
			--*dp;
			--dp;
			++*dp;
			++dp;
			}
		--dp;
		--dp;
		--*dp;
		}
	++dp;
	while (*dp){
		--*dp;
		--dp;
		++*dp;
		++dp;
		}
	--dp;
	std::cout << *dp << std::endl;
	++dp;
	++*dp;
	++*dp;
	++*dp;
	++*dp;
	++*dp;
	++*dp;
	++*dp;
	++*dp;
	++*dp;
	++*dp;
	std::cout << ((char)*dp);
	return 0;
}
