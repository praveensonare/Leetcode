#include "Utility.h"

// 359. Logger Rate Limiter
// Level - Easy
// 
// Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.
// 
// Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.
// 
// It is possible that several messages arrive roughly at the same time.
// 
// Example:
// 
// Logger logger = new Logger();
// 
// // logging string "foo" at timestamp 1
// logger.shouldPrintMessage(1, "foo"); returns true;
// 
// // logging string "bar" at timestamp 2
// logger.shouldPrintMessage(2,"bar"); returns true;
// 
// // logging string "foo" at timestamp 3
// logger.shouldPrintMessage(3,"foo"); returns false;
// 
// // logging string "bar" at timestamp 8
// logger.shouldPrintMessage(8,"bar"); returns false;
// 
// // logging string "foo" at timestamp 10
// logger.shouldPrintMessage(10,"foo"); returns false;
// 
// // logging string "foo" at timestamp 11
// logger.shouldPrintMessage(11,"foo"); returns true;

class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> H; // log->timestamp
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (H.find(message) != H.end() && H[message] > timestamp - 10) return false;

        H[message] = timestamp;
        return true;
    }
};
#define PAIR0 pair<int, string>
#define PAIR1 pair<string,PAIR0>

void test_LoggerRateLitter()
{
    vector<vector<PAIR1>> tc = {{PAIR1("Logger",PAIR0(0,"")), PAIR1("shouldPrintMessage",PAIR0(1,"foo")), PAIR1("shouldPrintMessage",PAIR0(2,"bar")), PAIR1("shouldPrintMessage",PAIR0(3,"foo")), PAIR1("shouldPrintMessage",PAIR0(8,"bar")), PAIR1("shouldPrintMessage",PAIR0(10,"foo")), PAIR1("shouldPrintMessage",PAIR0(11,"foo"))},
                               {PAIR1("Logger",PAIR0(0,"")), PAIR1("shouldPrintMessage",PAIR0(0,"A")), PAIR1("shouldPrintMessage",PAIR0(0,"B")), PAIR1("shouldPrintMessage",PAIR0(0,"C")), PAIR1("shouldPrintMessage",PAIR0(0,"A")), PAIR1("shouldPrintMessage",PAIR0(0,"B")), PAIR1("shouldPrintMessage",PAIR0(0,"C")), PAIR1("shouldPrintMessage",PAIR0(11,"A")), PAIR1("shouldPrintMessage",PAIR0(11,"B")), PAIR1("shouldPrintMessage",PAIR0(11,"C")), PAIR1("shouldPrintMessage",PAIR0(11,"A"))}
    };
    vector<vector<bool>> answers = {{true,true,true,false,false,false,true},
                                    {true,true,true,true,false,false,false,true,true,true,false}};

    for (int ti = 0; ti < tc.size(); ++ti)
    {
        Logger logr;
        vector<PAIR1> t = tc[ti];
        for (int i = 0; i < t.size(); ++i)
        {
            //cout << "praveen - " << __FUNCTION__ << " : " << __LINE__ << endl;;
            if (answers[ti][i] != logr.shouldPrintMessage(t[i].second.first, t[i].second.second))
                cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
        }
    }
}
