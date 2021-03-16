#include <iostream>



using namespace std;
int main (){
	char menu;
	cout<<"Chose the option on what you would like to do"<<endl;
	cout<<"P = Pizza\n"<< "B = Burger\n"<<"T = Taco"<<endl; 

	cin >> menu;
		switch(menu){
			case 'P':
			{
				cout<<"You have chosen Pizza"<<endl;
				break;
			}
			case 'B':
			{
				cout<<"You have chosen Burger"<<endl;
				break;
			}
			case 'T':
			{
				cout<<"You have chosen Taco"<<endl;
				break;

			}
			default:
			{
				cout<<"Please choose an item"<<endl;
				break;
			}
		}

}