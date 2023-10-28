//
//  test.cpp
//
//  Tests to prove your code works.
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

#include "Queue.h"
#include "Stack.h"
#include "catch.h"
#include <string>

using namespace std;
using namespace csi281;

TEST_CASE( "Queue Tests", "[queue]" ) {
    SECTION( "Queue w/ int tests" ) {
        Queue<int> q1 = Queue<int>();
        // Ensure that push(), pop(), and peek()
        // work properly in concert with getCount()
        // and remove()
        // YOUR CODE HERE
        int sampleIntArray1[6] = {23, 4, 11, 4, 7, 8};
        for (int element : sampleIntArray1)
            q1.push(element);
        CHECK(q1.peek() == 23);
        CHECK(q1.pop() == 23);
        CHECK (q1.pop() == 4);
        q1.push(500);
        CHECK (q1.peek() != 500);
        
    }
    
    SECTION( "Queue w/ string tests" ) {
        Queue<string> q2 = Queue<string>();
        // Ensure that push(), pop(), and peek()
        // work properly in concert with getCount()
        // and remove()
        // YOUR CODE HERE
        for (int i = 1; i < 10; i++) 
            q2.push(string(i, 'a'));
        CHECK(q2.peek() == "a");
        for (int i = 1; i <= 6; i++)
            CHECK(q2.pop() == string(i, 'a'));
        CHECK(q2.pop() == "aaaaaaa");
    }
}

TEST_CASE( "Stack Tests", "[stack]" ) {
    SECTION( "Stack w/ int tests" ) {
        Stack<int> s1 = Stack<int>();
        // Ensure that push(), pop(), and peek()
        // work properly in concert with getCount()
        // and remove()
        // YOUR CODE HERE
        int sampleIntArray1[6] = { 23, 4, 11, 4, 7, 8 };
        for (int element : sampleIntArray1)
            s1.push(element);
        CHECK(s1.peek() == 8);
        CHECK(s1.pop() == 8);
        CHECK(s1.pop() == 7);
        s1.push(500);
        CHECK(s1.peek() == 500);
    }
    
    SECTION( "Stack w/ string tests" ) {
        Stack<string> s2 = Stack<string>();
        // Ensure that push(), pop(), and peek()
        // work properly in concert with getCount()
        // and remove()
        // YOUR CODE HERE
        for (int i = 1; i < 10; i++)
            s2.push(string(i, 'a'));
        CHECK(s2.peek() == "aaaaaaaaa");
        for (int i = 9; i >= 3; i--)
            CHECK(s2.pop() == string(i, 'a'));
        CHECK(s2.pop() == "aa");
    }
}

