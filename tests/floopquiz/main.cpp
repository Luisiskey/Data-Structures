/*Write a program that asks a user for five numbers.
**Print out the sum and average of the five numbers.
*/

#include <iostream>

int main(){
	std::cout<<"You'll be asked to enter 5 numbers"<<std::endl;
	// was having issues, noticed that if i dont assign sum = 0, for some reason it automatically does that by iteself and chooses a random number? 
	//not good to leave it empty, must remember to assign number;
	int sum = 0;
	int avg = 0;

	for(int i = 0; i < 5; i++){
		int number = 0;
		std::cout<<"please enter a number to add"<<std::endl;
		std::cin>>number;
		sum += number;
		std::cout<<"This is the sum: "<< sum <<std::endl;

	}
	
	avg = sum /5;
	std::cout<<"The average of these 5 numbers is: "<< avg<<std::endl;
}