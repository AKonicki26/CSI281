//
//  CityTemperatureData.cpp
//
//  Implementation of CityTemperatureData
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

#include "CityTemperatureData.h"
#include <cassert>

using namespace std;

namespace csi281 {
    // Fill in all instance variables for CityTemperatureData.
    CityTemperatureData::CityTemperatureData(const string name, CityYear data[], int numYears) : _name(name), _data(data), _count(numYears) {
    }
    
    // Release any memory connected to CityTemperatureData.
    CityTemperatureData::~CityTemperatureData() {
    }
    
    // Look up a CityYear instance held by CityTemperatureData by its year.
    // Find the right CityYear in the array and return it
    const CityYear CityTemperatureData::operator[](const int year) const {
        // YOUR CODE HERE

        for (int i = 0; i < this->_count; i++) 
            if (_data[i].year == year) return _data[i];
    }
    
    // Get the average (mean) temperature of all time for this city
    // by averaging every CityYear.
    float CityTemperatureData::getAllTimeAverage() const {
        // YOUR CODE HERE
        float average = 0;

        for (int i = 0; i < this->_count; i++)
            average += _data[i].averageTemperature;

        average /= (float)this->_count;
        return average;
    }
    
    // Sum all of the days below 32 for all years.
    int CityTemperatureData::getTotalDaysBelow32() const {
        // YOUR CODE HERE

        int sum = 0;

        for (int i = 0; i < this->_count; i++)
            sum += _data[i].numDaysBelow32;

        return sum;
    }
    
    // Sum all of the days above 90 for all years.
    int CityTemperatureData::getTotalDaysAbove90() const {
        // YOUR CODE HERE

        int sum = 0;

        for (int i = 0; i < this->_count; i++)
            sum += _data[i].numDaysAbove90;

        return sum;
    }
}
