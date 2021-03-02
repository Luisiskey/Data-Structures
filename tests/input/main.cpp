#include <iostream>
#include <string>
#include<sstream>
using namespace std;


int main(){
	string name,movie;
	int year;
	int age;
	string stringInches;
	int inch;

	cout <<"How old are you?"<<endl;
	cin >> age;
	cout<<"You are "<< age << " years old"<<endl;
	//i had to do a cin ignore here to be able to use line 20, it looks like it was grabbing info from line 16
	cin.ignore();
	cout<<"What is your name? ";
	getline(cin, name);
	cout <<"Your name is "<< name <<endl;
	cout<<"What is your favorite movie"<<endl;
	getline(cin, movie);
	cout<<"your favorite movie is "<< movie<<endl;
	cout<<"how many inches is your hand? "<<endl;
	getline(cin, stringInches);
	//stringstream converts strin into a numeric value
	stringstream(stringInches) >> inch;
	cout<<"your hand is "<< inch <<" inches"<<endl;

}