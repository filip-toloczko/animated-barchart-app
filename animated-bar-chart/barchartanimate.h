/*
In this file we define the BarChartAnimate class
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//Define the BarChartAnimate class
class BarChartAnimate {
 private:

    //private data members for BarChartAnimate class
    BarChart* barcharts;
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;

 public:

    //Parameterized constructor for the BarChartAnimate class:
    BarChartAnimate(string title, string xlabel, string source) {
        
        //Set private data members for BarChartAnimate class
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
        this->capacity = 4;
        barcharts = new BarChart[capacity];
        this->size = 0;
    }

    //Destructor used to free memory from the heap for the BarChartAnimate class
    virtual ~BarChartAnimate() {
        if(barcharts != nullptr){
            delete[] barcharts;
        }
    }

    //Function that adds a BarChart object into the BarChartAnimate object    
    void addFrame(ifstream &file) {
        int colorIndex = colorMap.size();
        string blankLine;
        getline(file, blankLine);
        string numLines;
        getline(file, numLines);
        if(numLines == ""){
            return;
        }
        size+=1;

        //Check if the array is full, if so double the array size
        if(size == capacity){
            int newCapacity = capacity * 2;
            BarChart* newBarCharts = new BarChart[newCapacity];
            for (int i = 0; i < size; ++i){
                newBarCharts[i] = barcharts[i];
            }
            delete[] barcharts;
            barcharts = newBarCharts;
            capacity = newCapacity;
        }
        int numLinesInt = stoi(numLines);
        BarChart bc(numLinesInt);

        //Loop through file for the number of lines specified in the first
        //line of the data segment
        for(int i = 0; i < numLinesInt; i++){
            string lineData;
            string substr;
            string barName;
            string barCategory;
            string barValue;
            int barValueInt;

            //get values for Bar object
            getline(file, lineData);
            stringstream ss(lineData);
            getline(ss, substr, ',');
            bc.setFrame(substr);
            getline(ss, substr, ',');
            barName = (substr);
            getline(ss, substr, ',');
            getline(ss, substr, ',');
            barValue = substr;
            barValueInt = stoi(barValue);
            getline(ss, substr);
            barCategory = substr;
            if(colorIndex>5){
                colorIndex = colorIndex-6;
            }
            if (colorMap.find(barCategory) == colorMap.end()) {
                colorMap.insert({barCategory, COLORS[colorIndex]});
                colorIndex++;
            }

            //add Bar into BarChart
            bc.addBar(barName, barValueInt, barCategory);
        }
        //add BarChart into barcharts
        barcharts[size-1] = bc;
    }

    //Function to animate the bar graphs
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
        
        //If the requested endIter is -1, loop through entire array
        if(endIter == -1){
            endIter = size;
        }
        
        //Loop and display specified amount of BarCharts
        for(int i = 0; i < endIter; i++){
            
            //Handles the instance where you want to display more bars than are
            //available, only graphs the amount of bars that are available
            if(barcharts[i].getSize() < top){
                int newTop;
                newTop = barcharts[i].getSize();
                usleep(3*microsecond);
                output << CLEARCONSOLE;
                output << title << endl;
                output << source << endl;
                barcharts[i].graph(cout, colorMap, newTop);
                output << xlabel << endl;
                output << "Frame: " << barcharts[i].getFrame() << endl;    
            }

            //Graphs the BarChart at i
            else{
                usleep(3*microsecond);
                output << CLEARCONSOLE;
                output << title << endl;
                output << source << endl;
                barcharts[i].graph(cout, colorMap, top);
                output << xlabel << endl;
                output << "Frame: " << barcharts[i].getFrame() << endl;
            }
        }		
	}

    //CREATIVE COMPONENT
    //Function to animate the bar graphs with a playback speed modifier
    void animate(ostream &output, int top, int endIter, int playbackSpeed) {
		//update playback speed
        unsigned int microsecond = 50000;
        microsecond = microsecond / playbackSpeed;
        
        //If the requested endIter is -1, loop through entire array
        if(endIter == -1){
            endIter = size;
        }
        
        //Loop and display specified amount of BarCharts
        for(int i = 0; i < endIter; i++){
            
            //Handles the instance where you want to display more bars than are
            //available, only graphs the amount of bars that are available
            if(barcharts[i].getSize() < top){
                int newTop;
                newTop = barcharts[i].getSize();
                usleep(3*microsecond);
                output << CLEARCONSOLE;
                output << title << endl;
                output << source << endl;
                barcharts[i].graph(cout, colorMap, newTop);
                output << xlabel << endl;
                output << "Frame: " << barcharts[i].getFrame() << endl;    
            }

            //Graphs the BarChart at i
            else{
                usleep(3*microsecond);
                output << CLEARCONSOLE;
                output << title << endl;
                output << source << endl;
                barcharts[i].graph(cout, colorMap, top);
                output << xlabel << endl;
                output << "Frame: " << barcharts[i].getFrame() << endl;
            }
        }			
	}

    // function that returns the size private data member of BarChartAnimate
    int getSize(){
        return size;
    }

    // function that defines the bracket operator for BarChartAnimate
    BarChart& operator[](int i){
        BarChart bc;

        if(i<capacity){
            return barcharts[i];
        }
        else{
            throw("BarChartAnimate: i out of bounds");
            return bc;
        }
    }
};