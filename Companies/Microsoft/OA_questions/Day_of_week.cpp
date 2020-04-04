// Write a function that, given a string S representing day of the week and an integer K
// (between 0 and 500 inclusive), returns the day of the week that is K days later

// For example, given S = "Wed" and K = 2, should return "Fri"
// Given S = "Sat" and K=23, should return "Mon"

// https://leetcode.com/discuss/interview-question/398047/

string calcDayAfterKdays(string start, int k)
{
    if(k == 0)
        return start;
    
    vector<string> days = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    
    int startId = 0;
    for(string& day : days)
    {
        if(day == start)
            break;
        startId++;
    }
    
    int endId = (startId + k) % 7;
    
    return days[endId];
}

int main() {
    cout<<calcDayAfterKdays("Sat", 23);
}