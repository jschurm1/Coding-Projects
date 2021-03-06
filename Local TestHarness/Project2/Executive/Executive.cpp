/////////////////////////////////////////////////////////////////////////////////////////////
// Executive.cpp - Defines Executive class which is meant to demonstrate the capabilities  //
//                 of the TestHarness class.                                               //
// ver 1.0                                                                                 //
// Language:      Visual C++ 2010, SP1                                                     //
// Application:   Project 1 CSE 687                                                        //
// Author:        John Schurman, Terence Lau                                               //
/////////////////////////////////////////////////////////////////////////////////////////////
#include "Executive.h"

/******************************************************************************************************************
* Function: CreateTests
* Notes:    This function invokes the testHarness addTests function which parses an xmlTestRequest string, loads
*           the corresponding test driver dlls and then creates a list of test driver objects.
*
******************************************************************************************************************/
void Executive::CreateTests(string xmlTestRequest)
{
   testHarness.addTests(xmlTestRequest);
}

/******************************************************************************************************************
* Function: RunSampleTestSequence
* Notes:    This function is meant to demonstrate the capabilities of the TestHarness. It starts by creating an
*           XML request consisting of the test driver dll's to load. The XML request is fed to the test harness
*           which then loads the corresponding dlls and then creates a list of corresponding test driver objects
*           by invoking its factory method. This function then invokes the test harness's runTestList function 
*           which runs through each of the RunTest methods defined by the TestDriver and logs the results at
*           three levels of verbosity which include pass/fail and time-stamp. Finally tests are cleared.
*
******************************************************************************************************************/
void Executive::RunSampleTestSequence()
{
   string xmlTestRequest;

   //SampleDriverA test routine returns false with no exceptions
   //SampleDriverB test routine returns true
   //SampleDriverC test routine returns true but generates badcast exception

   xmlTestRequest = string("<testelement>SampleDriverA.dll</testelement>") +
                    string("<testelement>SampleDriverB.dll</testelement>") +
                    string("<testelement>SampleDriverC.dll</testelement>");

   testHarness.addTests(xmlTestRequest);
   testHarness.runTestList();

   testHarness.printLevelOneLog();
   testHarness.printLevelTwoLog();
   testHarness.printLevelThreeLog();
   testHarness.clearTestList();
}

int main()
{
   Executive executive;
   executive.RunSampleTestSequence();
   system("pause");
}

