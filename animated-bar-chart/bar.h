/*
In this file we define the Bar class
*/

#include <iostream>
#include <string>
using namespace std;

//definition of the bar class
class Bar {
 private:
    
    // Private member variables for a Bar object
    string name;
    string category;
    int value;

 public:

    //This is the default constructor for the Bar class, setting it with default values
    Bar() {
        
        //setting values for private data members of the Bar class
        this->name = "";
        this->category = "";
        this->value = 0;        
    }

    //Parameterized constructor for the Bar class, setting it with specified values
    Bar(string name, int value, string category) {
        
        //setting values for private data members of the Bar class
        this->name = name;
        this->value = value;
        this->category = category;
        
    }

    //Destructor that frees allocated memory
    virtual ~Bar() {        
    }

    //Function that returns the name private data member of the Bar class
	string getName() {        
        return name;
	}

    //Function that returns the value private data member of the Bar class
	int getValue() {
        return value;
	}

    //Function that returns the category private data member of the Bar class
	string getCategory() {
        return category; 
	}

	//function that defines the less than operator for the Bar Class
	bool operator<(const Bar &other) const {
        if((this->value) < (&other)->value){
            return true;
        }
        else{
            return false;
        }
	}

    //function that defines the less than / equal to operator for the bar class
	bool operator<=(const Bar &other) const {
        if((this->value) <= (&other)->value){
            return true; 
        }
        else{
            return false;
        }
	}

    //function that defines the greater than operator for the bar class
	bool operator>(const Bar &other) const {
        if((this->value) > (&other)->value){
            return true;
        }
        else{
            return false;
        }
	}

    //function that defines the greater than / equal to operator for the bar class
	bool operator>=(const Bar &other) const {
        if((this->value) >= (&other)->value){
            return true;
        }
        else{
            return false;
        }
	}
};
