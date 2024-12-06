/*
In this file we define the BarChart class
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "bar.h"


using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


//
// NOTE: COMMENT AND UNCOMMENT AS NEEDED BASED ON YOUR TERMINAL
//
// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
// const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};



//Definitions for the BarChart class
class BarChart {
 private:
    
    //Private data members for the BarChart class
    Bar* bars;
    int capacity;
    int size;
    string frame;
    
 public:
    
    //Default constructor for the BarChart class:
    BarChart() {

        //setting values for private data members of the BarChart class
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
    }
    
    // parameterized constructor for the BarChart class:
    BarChart(int n) {
        
        //setting values for private data members of the BarChart class
        bars = new Bar[n];
        capacity = n;
        size = 0;
        frame = "";
        
    }

    //Copy constructor for the BarChart class, copies on object into another
    BarChart(const BarChart& other) {
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
        this->frame = other.frame;

        for(int i = 0; i<other.size; i++){
            this->bars[i] = other.bars[i];
        }
    }
    
    //Copy operator for the BarChart class, used to copy one object into another
    BarChart& operator=(const BarChart& other) {
        if(this == &other){
            return *this;
        }

        delete[] bars;
        
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
        this->frame = other.frame;

        for(int i = 0; i<other.size; i++){
            this->bars[i] = other.bars[i];
        }

        return *this;
    }

    //Function to clear a BarChart object and reset it to standard values
    void clear() {
        delete[] bars;
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = ""; 
    }
    
    //Destructor used to free memory allocated on the heap
    virtual ~BarChart() {
        if(bars != nullptr){
            delete[] bars;
        }    
    }
    
    //Function to set frame private data member of BarChart
    void setFrame(string frame) {
        this->frame = frame;  
    }
    
    // Function that returns the frame of the BarChart oboject.
    string getFrame() {        
        return frame;
    }

    //Function that adds a Bar object to the BarChart object
    bool addBar(string name, int value, string category) {
        
        //Check if there is room in the array for another object
        if(size < capacity){
            Bar b(name, value, category);
            bars[size] = b;
            size++;
            return true;
        }
        else{
            return false;
        }
    }
    
    // Function that returns the size (number of bars) of the BarChart object.
    int getSize() {
        return size;
    }
    
    //Function that defines the bracket operator for the BarChart object
    Bar& operator[](int i) {
        Bar b;
        
        if(i < capacity){
            return bars[i];
        }
        else{
            throw("BarChart: i out of bounds");
            return b;
        }
    }
    
    //Function that displays the contents of the BarChart Object
    void dump(ostream &output) {
        Bar b;

        //Sort the Bars in BarChart
        for (int i = 0; i < size - 1; i++){
            for (int j = 0; j < size - i - 1; j++){
                if (bars[j] < bars[j + 1]){
                    swap(bars[j], bars[j + 1]);
                }
            }
        }

        //Display the BarChart
        output << "frame: " << frame << endl;
        for (int i = 0; i < size; i++){
            output << bars[i].getName()<< " " <<
                      bars[i].getValue() << " " <<
                      bars[i].getCategory() << endl; 
        }
    }
    
    //Function that displays the BarChart object
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;
        output << RESET;

        //Sort the BarChart object        
        for (int i = 0; i < size - 1; i++){
            for (int j = 0; j < size - i - 1; j++){
                if (bars[j] < bars[j + 1]){
                    swap(bars[j], bars[j + 1]);
                }
            }
        }
        int maxValue = bars[0].getValue();

        //Loop through the BarChart object, displaying each Bar object
        for(int i = 0; i < top; i++){
            string color = colorMap.at(bars[i].getCategory());
            string barstr = "";
            double currentValue;
            currentValue = bars[i].getValue();
            double ratioBoxes = ((currentValue / maxValue)*60);
            lenMax = floor(ratioBoxes);
            for (int i = 0; i < lenMax; i++) {
                barstr += BOX;
            }
            barstr += " " + bars[i].getName() + " " + to_string(bars[i].getValue()); 
            output << color << barstr << endl;
            output << RESET;                                  
        }
    }
};
