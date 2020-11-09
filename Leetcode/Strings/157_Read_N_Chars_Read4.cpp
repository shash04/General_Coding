// Given a file and assume that you can only read the file using a given method read4, implement a method to read n characters.

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
// char[] buf4 = new char[4]; // Create buffer with enough space to store characters
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

// https://leetcode.com/problems/read-n-characters-given-read4/

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int bufIdx = 0;
        char tmpBuf[4];
        int tmpBufCount = 0;
        
        while(bufIdx < n)
        {
            // temp buf will keep pull chars using read4
            // tmp buf count takes care if less chars than n
            // call read4 only when all chars in tmp buf are copied
            int tmpBufIdx = 0;
            tmpBufCount = read4(tmpBuf);
            
            // if new chars read are 0, break
            if(tmpBufCount == 0)
                break;
            
            while(bufIdx < n && tmpBufCount > 0)
            {
                buf[bufIdx++] = tmpBuf[tmpBufIdx++];
                tmpBufCount--;
            }
        }
        
        return bufIdx;
    }
};