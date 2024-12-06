/*
In this file we define our test cases
*/

#include <iostream>
#include "barchartanimate.h"
using namespace std;

//function that tests the default constructor for the Bar class
bool testBarDefaultConstructor() {
	cout << "----------------------------------------" << endl;
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
	cout << GREEN;
    cout << "testBarDefaultConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
    return true;
}

//function that tests the parameterized constructor for the Bar class
bool testBarParamConstructor() {
	cout << "----------------------------------------" << endl;
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
	Bar b1("NAME", 0, "Category");
    if (b1.getName() != "NAME") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b1.getValue() != 0) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b1.getCategory() != "Category") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
	cout << GREEN;
    cout << "testBarParamConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
    return true;
}

//function that tests the < operator for the Bar class
bool testBarLessThanConstructor(){
	cout << "----------------------------------------" << endl;
	Bar b1("Chicago", 9234324, "US");
	Bar b2("New York", 100000000, "US");
	if(b1<b2 != true){
		cout << "testBarLessThanConstructor: '<' failed" << endl;
		return false;
	}
	Bar b3("Chicago", 0, "US");
	Bar b4("New York", 0, "US");
	if(b3 < b4 == true){
		cout << "testBarLessThanConstructor: '<' failed" << endl;
		return false;
	}
	Bar b5("Chicago", 5, "US");
	Bar b6("New York", 0, "US");
	if(b5 < b6 == true){
		cout << "testBarLessThanConstructor: '<' failed" << endl;
		return false;
	}
	cout << GREEN;
	cout << "testBarLessThanConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests the <= operator for the Bar class
bool testBarLessEqualConstructor(){
	cout << "----------------------------------------" << endl;
	Bar b1("Chicago", 9234324, "US");
	Bar b2("New York", 100000000, "US");
	Bar b3("Buenos Aires", 9234324, "US");
	if(b1<=b2 != true){
		cout << RED;
		cout << "testBarLessEqualConstructor: '<' failed" << endl;
		return false;
		cout << RESET;
	}
	else if(b1<=b3 != true){
		cout << RED;
		cout << "testBarLessEqualConstructor: '=' failed" << endl;
		return false;
		cout << RESET;
	}
	cout << GREEN;
	cout << "testBarLessEqualConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests the > operator for the Bar class
bool testBarGreaterThanConstructor(){
	cout << "----------------------------------------" << endl;
	Bar b1("Chicago", 9234324, "US");
	Bar b2("New York", 100000000, "US");
	if(b1>b2 == true){
		cout << "testBarGreaterThanConstructor: '>' failed" << endl;
		return false;
	}
	if(b2>b1 != true){
		cout << "testBarGreaterThanConstructor: '>' failed" << endl;
		return false;
	}
	cout << GREEN;
	cout << "testBarGreaterThanConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests the >= operator for the Bar class
bool testBarGreaterEqualConstructor(){
	cout << "----------------------------------------" << endl;
	Bar b1("Chicago", 9234324, "US");
	Bar b2("New York", 100000000, "US");
	Bar b3("Buenos Aires", 9234324, "US");
	if(b1>=b2 == true){
		cout << RED;
		cout << "testBarGreaterEqualConstructor: '<' failed" << endl;
		return false;
		cout << RESET;
	}
	else if(b1>=b3 != true){
		cout << RED;
		cout << "testBarGreaterEqualConstructor: '=' failed" << endl;
		return false;
		cout << RESET;
	}
	cout << GREEN;
	cout << "testBarGreaterEqualConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests getName() for the Bar class
bool testBarGetName(){
	Bar b;
	Bar b1("NAME", 1, "VALUE");
	if(b.getName() != ""){
		cout << RED;
		cout << "testBarGetName: getName() failed" << endl;
		cout << RESET;
		return false;
	}
	if(b1.getName() != "NAME"){
		cout << RED;
		cout << "testBarGetName: getName() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBarGetName: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests getValue() for the Bar class
bool testBarGetValue(){
	Bar b;
	Bar b1("NAME", 1, "VALUE");
	if(b.getValue() != 0){
		cout << RED;
		cout << "testBarGetValue: getValue() failed" << endl;
		cout << RESET;
		return false;
	}
	if(b1.getValue() != 1){
		cout << RED;
		cout << "testBarGetValue: getValue() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBarGetValue: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests getCategory() for the Bar class
bool testBarGetCategory(){
	Bar b;
	Bar b1("NAME", 1, "VALUE");
	if(b.getCategory() != ""){
		cout << RED;
		cout << "testBarGetCategory: getCategory() failed" << endl;
		cout << RESET;
		return false;
	}
	if(b1.getCategory() != "VALUE"){
		cout << RED;
		cout << "testBarGetCategory: getCategory() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBarGetCategory: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests the default constructor for the BarChart class
bool testBarChartDefaultConstructor() {
	BarChart bc;
    if(bc.getSize() != 0){
		cout << RED;
		cout << "testBarChartDefaultConstructor: getSize() failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc.getFrame() != ""){
		cout << RED;
		cout << "testBarChartDefaultConstructor: getFrame() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
    cout << "testBarChartDefaultConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
    return true;
}

//function that tests the parameterized constructor for the BarChart class
bool testBarChartParamConstructor() {
	BarChart bc(5);
    if(bc.getSize() != 0){
		cout << RED;
		cout << "testBarChartParamConstructor: getSize() failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc.getFrame() != ""){
		cout << RED;
		cout << "testBarChartParamConstructor: getFrame() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
    cout << "testBarChartParamConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
    return true;
}

//function that tests the copy constructor for the BarChart class
bool testBarChartCopyConstructor(){
	BarChart bc1(5);
	bc1.setFrame("100");
	bc1.addBar("name", 1, "category");
	BarChart bc2(bc1);
	if(bc1.getFrame() != bc2.getFrame()){
		cout << RED;
		cout << "testBarChartCopyConstructor: getFrame() failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc1.getSize() != bc2.getSize()){
		cout << RED;
		cout << "testBarChartCopyConstructor: getSize() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
    cout << "testBarChartCopyConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
    return true;
}

//function that tests the copy operator for the BarChart class
bool testBarChartCopyOperator(){
	BarChart bc1(5);
	bc1.setFrame("100");
	bc1.addBar("name", 1, "category");
	BarChart bc2 = (bc1);
	if(bc1.getFrame() != bc2.getFrame()){
		cout << RED;
		cout << "testBarChartCopyOperator: getFrame() failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc1.getSize() != bc2.getSize()){
		cout << RED;
		cout << "testBarChartCopyOperator: getSize() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
    cout << "testBarChartCopyOperator: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
    return true;
}

//function that tests the clear() function for the BarChart class
bool testBarChartClear(){
	BarChart bc1(5);
	bc1.setFrame("100");
	bc1.addBar("name", 1, "category");
	BarChart bc2;
	bc1.clear();
	if(bc1.getFrame() != bc2.getFrame()){
		cout << RED;
		cout << "testBarChartClear: getFrame() failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc1.getSize() != bc2.getSize()){
		cout << RED;
		cout << "testBarChartClear: getSize() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
    cout << "testBarChartClear: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
    return true;
}

//function that tests the setFrame() function for the BarChart class
bool testBarChartSetFrame(){
	BarChart bc1(5);
	BarChart bc2;
	bc1.setFrame("100");
	bc2.setFrame("");
	if(bc1.getFrame() != "100"){
		cout << RED;
		cout << "testBarChartSetFrame: setFrame() failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc2.getFrame() != ""){
		cout << RED;
		cout << "testBarChartSetFrame: setFrame() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
    cout << "testBarChartSetFrame: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
    return true;
}

//function that tests the getFrame() function for the BarChart class
bool testBarChartGetFrame(){
	BarChart bc1(5);
	BarChart bc2;
	bc1.setFrame("100");
	if(bc1.getFrame() != "100"){
		cout << RED;
		cout << "testBarChartSetFrame: getFrame() failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc2.getFrame() != ""){
		cout << RED;
		cout << "testBarChartSetFrame: getFrame() failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
    cout << "testBarChartSetFrame: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
    return true;
}

//function that tests the addBar() function for the BarChart class
bool testBarChartAddBar(){
	cout << "----------------------------------------" << endl;
	BarChart bc(3);
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	if(bc.getSize() != 3){
		cout << RED;
		cout << "testBarChartAddBar: 'getSize()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc[0].getCategory() != "US"){
		cout << RED;
		cout << "testBarChartAddBar: 'getCategory()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc[0].getName() != "Chicago"){
		cout << RED;
		cout << "testBarChartAddBar: 'getName()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc[0].getValue() != 1020){
		cout << RED;
		cout << "testBarChartAddBar: 'getValue()' failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBarChartAddBar: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests the [] operator for the BarChart class
bool testBarChartBrackets(){
	cout << "----------------------------------------" << endl;
	BarChart bc(3);
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	if(bc[1].getValue() != 1300){
		cout << RED;
		cout << "testBarChartBrackets: 'getValue()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc[2].getName() != "Paris"){
		cout << RED;
		cout << "testBarChartBrackets: 'getName()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc[0].getCategory() != "US"){
		cout << RED;
		cout << "testBarChartBrackets: 'getCategory()' failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBarChartAddBar: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests the dump() function for the BarChart class
bool testBarChartDump(){
	BarChart bc(3);
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	bc.setFrame("1950");
	stringstream ss("");
	bc.dump(ss);
	if(bc[0].getName() != "NYC"){
		cout << RED;
		cout << "testBarChartDump: sorting failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc[1].getName() != "Paris"){
		cout << RED;
		cout << "testBarChartDump: sorting failed" << endl;
		cout << RESET;
		return false;
	}
	if(bc[2].getName() != "Chicago"){
		cout << RED;
		cout << "testBarChartDump: sorting failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBarChartDump: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests the graph() function for the BarChart class
bool testBarChartGraph(){
	BarChart bc(3);
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	bc.setFrame("1950");
	string red("\033[1;36m");
	string blue("\033[1;33m");
	map<string, string> colorMap;
	colorMap["US"] = RED;
	colorMap["France"] = BLUE;
	stringstream ss("");
	bc.dump(ss);
	bc.graph(ss, colorMap, 3);
	if(bc[0].getName() != "NYC"){
		cout << RED;
		cout << "testBarChartGraph: sorting failed" << endl;
		cout << RESET;
		return false;
	}
	if(colorMap.at("US") != RED){
		cout << RED;
		cout << "testBarChartGraph: colorMap failed" << endl;
		cout << RESET;
		return false;
	}
	if(colorMap.at("France") != BLUE){
		cout << RED;
		cout << "testBarChartGraph: colorMap failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBarChartGraph: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//Function that tests the parameterized constructor for the BCA class
bool testBcaParamConstructor(){
	cout << "----------------------------------------" << endl;
	BarChartAnimate bca("title", "xlabel", "source");
	if(bca.getSize() != 0){
		cout << RED;
		cout << "testBcaParamConstructor: 'getSize()' failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBcaParamConstructor: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//Function that tests the addFrame() function for the BCA class
bool testBcaAddFrame(){
	ifstream inFile("cities.txt");
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
	BarChartAnimate bca(title, xlabel, source);
	bca.addFrame(inFile);
	bca.addFrame(inFile);
	bca.addFrame(inFile);
	if(bca[0].getSize() != 12 ){
		cout << RED;
		cout << "testBcaAddFrame: 'getSize()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bca.getSize() != 3){
		cout << RED;
		cout << "testBcaAddFrame: 'getSize()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bca[0][0].getName() != "Beijing"){
		cout << RED;
		cout << "testBcaAddFrame: 'getName()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bca[0][0].getValue() != 672){
		cout << RED;
		cout << "testBcaAddFrame: 'getValue()' failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBcaAddFrame: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//Function that tests the animate() function for the BCA class
bool testBcaAnimate(){
	ifstream inFile("cities.txt");
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
	stringstream ss("");
	bca.animate(ss, 12, 0);
	if(bca.getSize() != 519){
		cout << RED;
		cout << "testBcaAnimate: 'getSize()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bca[0].getFrame() != "1500"){
		cout << RED;
		cout << "testBcaAnimate: 'getFrame()' failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBcaAnimate: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//Function that tests the getSize() function for BCA class
bool testBcaGetSize(){
	ifstream inFile("cities.txt");
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
	BarChartAnimate bca(title, xlabel, source);
	BarChartAnimate bca2(title, xlabel, source);
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	stringstream ss("");
	bca.animate(ss, 12, 0);
	if(bca.getSize() != 519){
		cout << RED;
		cout << "testBcaGetSize: 'getSize()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bca2.getSize() != 0){
		cout << RED;
		cout << "testBcaGetSize: 'getSize()' failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBcaGetSize: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//function that tests [] operator for BCA class
bool testBcaBrackets(){
	ifstream inFile("cities.txt");
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
	BarChartAnimate bca(title, xlabel, source);
	BarChartAnimate bca2(title, xlabel, source);
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	stringstream ss("");
	bca.animate(ss, 12, 0);
	if(bca[0][0].getName() != "Beijing"){
		cout << RED;
		cout << "testBcaBrackets: 'getName()' failed" << endl;
		cout << RESET;
		return false;
	}
	if(bca[0][0].getValue() != 672){
		cout << RED;
		cout << "testBcaBrackets: 'getValue()' failed" << endl;
		cout << RESET;
		return false;
	}
	cout << GREEN;
	cout << "testBcaBrackets: all passed!" << endl;
	cout << RESET;
	cout << "----------------------------------------\n" << endl;
	return true;
}

//main function that runs tests
int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
	testBarGetName();
	testBarGetValue();
	testBarGetCategory();
	testBarLessThanConstructor();
	testBarLessEqualConstructor();
	testBarGreaterThanConstructor();
	testBarGreaterEqualConstructor();
	testBarChartDefaultConstructor();
	testBarChartParamConstructor();
	testBarChartCopyConstructor();
	testBarChartCopyOperator();
	testBarChartClear();
	testBarChartSetFrame();
	testBarChartGetFrame();
	testBarChartAddBar();
	testBarChartBrackets();
	testBarChartDump();
	testBarChartGraph();
	testBcaParamConstructor();
	testBcaAddFrame();
	testBcaAnimate();
	testBcaGetSize();
	testBcaBrackets();
    return 0;
}