// Write a program to count the number of days between two dates.

// The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.

// Example 1:
// Input: date1 = "2019-06-29", date2 = "2019-06-30"
// Output: 1

// Example 2:
// Input: date1 = "2020-01-15", date2 = "2019-12-31"
// Output: 15

class Solution {
    vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    void getDate(vector<int>& dateVec, string& dateStr)
    {
        istringstream ss(dateStr);
        string word;
        
        while(getline(ss, word, '-'))
        {
            dateVec.push_back(stoi(word));
        }
    }
    
    int countLeapYears(vector<int> d)
    {
        int yy = d[0];
        
        if(d[1] <= 2)
            yy--;
        
        int extraDays = yy / 4 - yy / 100 + yy / 400;
        
        return extraDays;
    }
    
public:
    int daysBetweenDates(string date1, string date2) {
        vector<int> d1, d2;
        
        // Get dates in vector (YYYY, MM, DD)
        getDate(d1, date1);
        getDate(d2, date2);
        
        // YYYY * 365 + DD
        int days1 = d1[0] * 365 + d1[2];
        
        // Add current year month days
        for(int i=0; i<d1[1]-1; i++)
            days1 += monthDays[i];
        
        // Add a day for every leap year
        days1 += countLeapYears(d1);
        
        // YYYY * 365 + DD
        int days2 = d2[0] * 365 + d2[2];
        
        // Add current year month days
        for(int i=0; i<d2[1]-1; i++)
            days2 += monthDays[i];
        
        // Add a day for every leap year
        days2 += countLeapYears(d2);
        
        return abs(days2 - days1);
    }
};