//////////////////////////////////////////////////////////////////////////////////////
// Logger.cpp - Defines Logger class which contains functions to log the results of //
//              test runs. Logs are available at three levels of verbosity. Logs    //
//              can also be cleared.                                                //
// ver 2.0                                                                          //
// Language:      Visual C++ 2010, SP1                                              //
// Application:   Project 1 CSE 687                                                 //
// Author:        John Schurman, Terence Lau                                        //
//////////////////////////////////////////////////////////////////////////////////////
#include "Logger.h"

/******************************************************************************************************************
* Function: printLevelOneLog
* Notes:    This function prints the level one log results of an executor call. The level one log includes the
*           test number and the pass/fail result of each callable object.
*
******************************************************************************************************************/
void Logger::printLevelOneLog() {
   cout << "********************************" << endl;
   cout << "*    LEVEL ONE STATUS LOG      *" << endl;
   cout << "********************************" << endl;
   for (const std::string &s : levelOneLog) {
      cout << s << endl;
   }
   cout << endl;
}

/******************************************************************************************************************
* Function: printLevelTwoLog
* Notes:    This function prints the level two log results of an executor call. The level two log includes the
*           test number and the pass/fail result of each callable object. If failed, log will also include
*           exception message.
*
******************************************************************************************************************/
void Logger::printLevelTwoLog() {
   cout << "********************************" << endl;
   cout << "*    LEVEL TWO STATUS LOG      *" << endl;
   cout << "********************************" << endl;
   for (const std::string &s : levelTwoLog) {
      cout << s << endl;
   }
   cout << endl;
}

/******************************************************************************************************************
* Function: printLevelThreeLog
* Notes:    This function prints the level three log results of an executor call. The level three log includes the
*           test number and the pass/fail result of each callable object. If failed, log will also include
*           exception message, exception category and timestamp.
*
******************************************************************************************************************/
void Logger::printLevelThreeLog() {
   cout << "********************************" << endl;
   cout << "*    LEVEL THREE STATUS LOG    *" << endl;
   cout << "********************************" << endl;
   for (const std::string &s : levelThreeLog) {
      cout << s << endl;
   }
   cout << endl;
}

void Logger::clearlog()
{
   levelThreeLog.clear();
   levelTwoLog.clear();
   levelOneLog.clear();
}

/******************************************************************************************************************
* Function: logTestStatus (Overloaded)
* Notes:    This function calls an overloaded version of logTestStatus that passes in empty strings for
*           exception related parameters.
*
******************************************************************************************************************/
void Logger::logTestStatus(int testNumber, bool passed)
{
   //calls other overloaded method for simplicty
   Logger::logTestStatus(testNumber, passed, "", "");
}

/******************************************************************************************************************
* Function: logTestStatus (Overloaded)
* Notes:    This function builds test result logs from the arguments specified, there are three different logs
*           each with increasing verbosity. Level one log contains pass/fail status, level two adds log adds
*           exception message and level three log adds execption category and timestamp.
*
******************************************************************************************************************/
void Logger::logTestStatus(int testNumber, bool passed, string exMsg, string exDetail)
{
   std::string dateTime = getCurrDateTime();
   std::stringstream ss;
   ss << std::left << "TEST ";
   ss << std::to_string(testNumber) << ": ";

   if (passed)
   {
      ss << std::setw(10) << "PASSED";
      levelOneLog.emplace_back(ss.str());

      ss << std::setw(40) << "PASSED";
      levelTwoLog.emplace_back(ss.str());

      ss << dateTime << " ";
      ss << "PASSED";
      levelThreeLog.emplace_back(ss.str());
   }
   else
   {
      exMsg = exMsg.empty() ? "No exceptions" : exMsg;
      exDetail = exDetail.empty() ? "FAILED" : exDetail;

      ss << std::setw(10) << "FAILED";
      levelOneLog.emplace_back(ss.str());

      ss << std::setw(40) << exMsg;
      levelTwoLog.emplace_back(ss.str());

      ss << dateTime << " ";
      ss << exDetail;
      levelThreeLog.emplace_back(ss.str());
   }
}

/******************************************************************************************************************
* Function: getCurrDateTime
* Notes:    This function returns the current datetime in format M/D/Y-H:M:S 
*
******************************************************************************************************************/
string Logger::getCurrDateTime() 
{
   struct tm timeInfo;
   time_t now;
   char buffer[80];

   time(&now);
   localtime_s(&timeInfo, &now);
   strftime(buffer, 80, "[%D-%T]", &timeInfo);
   return buffer;

}

#ifdef TEST_LOGGER
int main()
{
   //Test TestDriver here
   return 0;
}
#endif

