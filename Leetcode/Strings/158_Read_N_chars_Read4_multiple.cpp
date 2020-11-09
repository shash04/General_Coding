// Given a file and assume that you can only read the file using a given method read4, implement a method read to read n characters.
// Your method read may be called multiple times.

// Method read4:
// The API read4 reads 4 consecutive characters from the file, then writes those characters into the buffer array buf.
// The return value is the number of actual characters read.
// Note that read4() has its own file pointer, much like FILE *fp in C.

// Definition of read4:

//     Parameter:  char[] buf4
//     Returns:    int

// Note: buf4[] is destination not source, the results from read4 will be copied to buf4[]
// Below is a high level example of how read4 works:


// File file("abcde"); // File is "abcde", initially file pointer (fp) points to 'a'
// char[] buf = new char[4]; // Create buffer with enough space to store characters
// read4(buf4); // read4 returns 4. Now buf = "abcd", fp points to 'e'
// read4(buf4); // read4 returns 1. Now buf = "e", fp points to end of file
// read4(buf4); // read4 returns 0. Now buf = "", fp points to end of file
 

// Method read:

// By using the read4 method, implement the method read that reads n characters from the file and store it in the buffer array buf.
// Consider that you cannot manipulate the file directly.
// The return value is the number of actual characters read.

// Definition of read:

//     Parameters:	char[] buf, int n
//     Returns:	int

// Note: buf[] is destination not source, you will need to write the results to buf[]

// https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    // temp buf to store 4 chars from read4
    char tmpBuf[4];
    // index for temp buf
    int tmpBufIdx = 0;
    // num of chars left to be read from temp buf
    int tmpBufCount = 0;
public:
    /*
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int bufIdx = 0;
        
        // Keep checking if we have read n chars
        // Terminate with break if n is greater than num chars in buf
        while(bufIdx < n)
        {
            // Empty the temp buf before reading more chars
            while(bufIdx < n && tmpBufCount > 0)
            {
                buf[bufIdx++] = tmpBuf[tmpBufIdx++];
                tmpBufCount--;
            }
            
            // Temp buf is empty, reset temp buf idx and count and call read4
            if(bufIdx < n)
            {
                tmpBufIdx = 0;
                tmpBufCount = read4(tmpBuf);
                
                if(tmpBufCount == 0)
                    break;
            }
        }
        
        return bufIdx;
    }
};