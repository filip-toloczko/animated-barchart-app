/*
In this program, we use classes in order to create an animated bar chart,
showing a change of data over time as we read through a text file.

CREATIVE COMPONENT:
My creative component allows for the user of the program to change the speed
at which the bar chart is animated. The user is prompted to enter a playback 
speed, with whatever integer they enter being stored as playbackSpeed. This
overloads the animate() function from barchartanimate.h.The microsecond variable 
in the animate() function is then divided by the playbackSpeed variable, decreasing 
the amount of time it takes to run the animation.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() {
	string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	bca.animate(cout, 12, -1);

	//CREATIVE COMPONENT, UNCOMMENT LINES BELOW TO RUN
	// int playbackSpeed;
	// cout << "Enter playback speed: ";
	// cin >> playbackSpeed;
	// bca.animate(cout, 12, -1, playbackSpeed);
	
    return 0;
}