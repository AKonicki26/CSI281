//
//  csv.cpp
//
//  Functions for reading CSV files.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#include <algorithm> // for remove_if()
#include <sstream>
#include <iostream>
#include "csv.h"

using namespace std;

namespace csi281 {

    // Remove extraneous characters from string so it can
    // be converted into a number
    void clean(string &str) {
        string unwanted = "\"\' \t\n";
        str.erase(remove_if(str.begin(), str.end(), [&](char &c){
            return !unwanted.find_first_of(c);
        }));
    }

    // Read from a input string stream we hit the next comma, or the end
    // and try to convert it into the float we seek.
    float readFloatCell(istringstream &iss) {
        string holder;
        getline(iss, holder, ',');
        clean(holder);
        return stof(holder);
    }
    
    // Read from a input string stream we hit the next comma, or the end
    // and try to convert it into the int we seek.
    int readIntCell(istringstream &iss) {
        string holder;
        getline(iss, holder, ',');
        clean(holder);
        return stoi(holder);
    }

    // Read from a input string stream we hit the next comma, or the end
    // and try to convert it into the string we seek.
    string readStringCell(istringstream &iss) {
        string holder;
        getline(iss, holder, ',');
        return holder;
    }
    
    // Read a single line from a file stream and turn it into a CityYear
    // You'll want to use the standard library function getline()
    // and the readCell() functions above
    // You'll also want to construct a CityYear from what you have read from the file
    CityYear readLine(ifstream &file) {
        // YOUR CODE HERE

        string line;
        getline(file, line);
        istringstream lineSS(line);

        string station = readStringCell(lineSS);
        string name = readStringCell(lineSS);
        int date = readIntCell(lineSS);
        int daysUnder32 = readIntCell(lineSS);
        int daysOver90 = readIntCell(lineSS);
        float temperatureAverage = readFloatCell(lineSS);
        float temperatureMaxAverage = readFloatCell(lineSS);
        float temperatureMinAverage = readFloatCell(lineSS);

        CityYear data = {date, daysUnder32, daysOver90, 
                        temperatureAverage, temperatureMaxAverage, temperatureMinAverage};
        return data;
    }
    
    // Read city by looking at the specified lines in the CSV
    // You'll need to open an ifstream to fileName
    // You'll need to read CityYears from the file using readLine() until there
    // is nothing left to read
    // The ifstream method good() may be useful
    // Make sure to just read between startLine and endLine (inclusive of endLine)
    // Construct a CityTemperatureData and return it
    CityTemperatureData readCity(string cityName, string fileName, int startLine, int endLine)  {
        // YOUR CODE HERE

        ifstream file;
        file.open(fileName);

        // Dispose of the first line in the file since its the headers
        string trash;
        getline(file, trash);

        int lineCount = endLine - startLine + 1;

        CityYear *data = new CityYear[lineCount]();
        CityYear tempData;

        for (int i = 1; i < startLine; i++)
            readLine(file);
        for (int i = 0; i < lineCount; i++)
            data[i] = readLine(file);

        CityTemperatureData cityData(cityName, data, lineCount);
        return cityData;
    }
}

