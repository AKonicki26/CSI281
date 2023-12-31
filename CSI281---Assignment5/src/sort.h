//
//  sort.h
//  
//  Functions for merge sort, quicksort, and a hybrid sort.
//  You SHOULD modify this file.
//
//  IMPORTANT NOTE: For this particular assignment you may not add
//  any additional utility functions.
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

#ifndef sort_hpp
#define sort_hpp

#include <algorithm> // for swap(), merge()
#include <random>

using namespace std;

namespace csi281 {
    
    // Performs an in-place ascending sort of *array*
    // using the merge sort algorithm
    // *start* is the first element of the array to start sorting from
    // *end* is the end element for the elements to be sorted
    // *end* will be the length of the array - 1 for a first run
    // NOTE: Your solution MUST use std::inplace_merge
    // http://www.cplusplus.com/reference/algorithm/inplace_merge/
    template <typename T>
    void mergeSort(T array[], const int start, const int end) {
        // YOUR CODE HERE
        int length = end - start + 1;
        if (length < 2)
            return;

        int middle = ((length - 1) / 2) + start;
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);

        inplace_merge(array + start, array + middle + 1, array + end + 1);
    }
    
    // setup random number generator
    static random_device rd;
    static mt19937 rng(rd());
    // you can use uniform_int_distribution and rng to create
    // a random int in a certain range
    
    // Performs an in-place ascending sort of *array*
    // using the quicksort algorithm
    // *start* is the first element of the array to start sorting from
    // *end* is the end element for the elements to be sorted
    // *end* will be the length of the array - 1 for a first run
    // NOTE: Your solution should use std::swap
    // http://www.cplusplus.com/reference/algorithm/swap/
    // NOTE: Your solution MUST use a random pivot
    // TIP: It may be helpful to swap the pivot to the end,
    // sort the center of the range, and then move the pivot back to
    // the appropriate place
    template <typename T>
    void quickSort(T array[], const int start, const int end) {
        // YOUR CODE HERE
        int length = end - start + 1;
        if (length < 2)
            return;
        
        uniform_int_distribution<int> MinMax(start, end);
        int randomIndex = MinMax(rd);
        T pivotElement = array[randomIndex];
        int pivotIndex = 0;

        swap(array[randomIndex], array[end]);

        int index = start - 1;

        for (int i = start; i < end; i++)
            if (array[i] <= pivotElement)
                swap(array[++index], array[i]);

        swap(array[++index], array[end]);
        pivotIndex = index;
        quickSort(array, start, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, end);
    }
    
    // Performs an in-place ascending sort of *array*
    // using the insertion sort algorithm
    // *start* is the first element of the array to start sorting from
    // *end* is the end element for the elements to be sorted
    // *end* will be the length of the array - 1 for a first run
    // NOTE: You can modify your old implementation from assignment 4
    // OR if you believe yours was incorrect, email me and I will
    // send you mine assuming you are done with assignment 4,
    // but you will still need to modify it for this assignment
    // as described below
    // NOTE: You will need to modify the implementation to only
    // sort part of the array as per the parameters of this version
    template <typename T>
    void insertionSort(T array[], const int start, const int end) {
        // YOUR CODE HERE
        for (int i = start + 1; i <= end; i++) {
            T element = array[i];
            int j = i - 1;
            
            while (j >= start && array[j] > element) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = element;
        }
    }
    
    // Performs an in-place ascending sort of *array*
    // using merge sort until there is less than 10 elements, and then
    // the insertion sort algorithm
    // *start* is the first element of the array to start sorting from
    // *end* is the end element for the elements to be sorted
    // *end* will be the length of the array - 1 for a first run
    // TIP: You can copy your implementation of merge sort in here, and
    // should be able to call the insertionSort above
    template <typename T>
    void hybridSort(T array[], const int start, const int end) {
        // YOUR CODE HERE
        int length = end - start + 1;
        if (length < 10) {
            insertionSort(array, start, end);
            return;
        }

        int middle = ((length - 1) / 2) + start;
        hybridSort(array, start, middle);
        hybridSort(array, middle + 1, end);

        inplace_merge(array + start, array + middle + 1, array + end + 1);
    }
}

#endif /* sort_hpp */
