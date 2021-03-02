/*Goal: practice using stringstream
/*Goal: practice getting string inputs and 
 **converting them to numeric variables using
 **stringstream.
 **
 **Prompt the user for the length of a room. 
 **Then prompt for the width of the room.
 **Print out the area of the room. 
 */
 
 #include <iostream>
 #include<string>
 #include<sstream>
 using namespace std;
 
 int main(){
     string stringLength, stringWidth;
     float length, width, area;
     
     cout<<"what is the length in this room (in feet)?? "<<endl;
     getline(cin, stringLength);
     stringstream(stringLength)>> length;
     
     cout<<"what is the widthh in this room (in feet)?? "<<endl;
     getline(cin, stringWidth);
     stringstream(stringWidth)>> width;
     area = length * width;
     
     cout<<"The area of this room is "<< area<<" sqft";
     
 }
