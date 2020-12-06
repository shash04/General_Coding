// Median is the middle value in an ordered integer list. If the size of the list is even, there is no
// middle value. So the median is the mean of the two middle value.

// For example,
// [2,3,4], the median is 3
// [2,3], the median is (2 + 3) / 2 = 2.5

// Design a data structure that supports the following two operations:
// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
 

// Example:
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2

// Follow up:
// If all integer numbers from the stream are between 0 and 100, how would you optimize it?
// If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

// https://leetcode.com/problems/find-median-from-data-stream/

// ******************************************************************************************
// Max Heap and Min Heap approach
// Max Heap keeps lower half of stream (left half)
// Min heap keeps upper half of stream (right half)
// Max heap has preferrence = thus for odd num of elements - top of left would be median
// ******************************************************************************************

class MedianFinder {
private:
    priority_queue<int> right;                                    // Max Heap
    priority_queue<int, vector<int>, greater<int>> left;          // Min Heap
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // first push the element in left sorted part so it gets placed correctly
        left.push(num);

        // push the top of left to right (max from left part)
        right.push(left.top());
        left.pop();
        
        // Keep left part size always equal or more than right part
        if(left.size() < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size())
            return ((left.top() + right.top()) / 2.0);
        else
            return (double)(left.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// ******************************************************************************************
// Alternate approach with multiset
// ******************************************************************************************
class MedianFinder {
private:
    multiset<int> ms;
    multiset<int>::iterator loPtr, hiPtr;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        loPtr = ms.end();
        hiPtr = ms.end();
    }
    
    void addNum(int num) {
        int msSize = ms.size();
        
        ms.insert(num);
        
        if(msSize == 0)
        {
            loPtr = hiPtr = ms.begin();
        }
        // Multiset has odd number of elements - lo and hi ptrs point to same median
        else if(msSize % 2 == 1)
        {
            int currMedian = *loPtr;
            
            // if num is less that curr median it would be add to lower half - decrement loPtr
            // else increment hiPtr
            if(num < currMedian)
                loPtr--;
            else
                hiPtr++;
        }
        // Multiset has even number of elements - lo and hi ptrs point to consecutive ele
        else
        {
            int loMedian = *loPtr;
            int hiMedian = *hiPtr;
            
            if(num > loMedian && num < hiMedian)
            {
                loPtr++;
                hiPtr--;
            }
            else if(num >= hiMedian)
                loPtr++;
            else
                loPtr = --hiPtr;                // Insertion at end of equal range would spoil loPtr
        }
    }
    
    double findMedian() {
        if(ms.size() % 2)
            return *loPtr;
        else
            return (double)(*loPtr + *hiPtr) * 0.5;
    }
};
