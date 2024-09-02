class Solution {
public:
    int operationCount(int mins) {
        int count = 0;
        
        count += mins / 60;   
        mins %= 60;           
        
        count += mins / 15;   
        mins %= 15;          
        
        count += mins / 5;    
        mins %= 5;            
        
        count += mins / 1;
        return count;
    }

    // Function to convert time string "HH:MM" to minutes since start of day
    int timeToMinutes(const string& time) {
        int hours = stoi(time.substr(0, 2));  
        int minutes = stoi(time.substr(3, 2));  
        return hours * 60 + minutes;  
    }

    // Function to get the time difference in minutes
    int getTimeDifference(const string& current, const string& correct) {
        int currentMinutes = timeToMinutes(current);  
        int correctMinutes = timeToMinutes(correct);  
        return abs(correctMinutes - currentMinutes);  
    }

    int convertTime(string current, string correct) {
        int timeDiff = getTimeDifference(current, correct);
        return operationCount(timeDiff);
    }
};
