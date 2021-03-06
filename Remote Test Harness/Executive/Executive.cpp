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
* Notes:    This function is meant to demonstrate the capabilities of the TestHarness. The testharness is first
*           started which spawns the child test threads and main message processing thread within the testHarness.
*           Ready messages from the child threads are posted to the screen as well as the response from the main
*           message processing thread. Clients are then created which invoke the AddTests function of the TestHarness. 
*           Each client adds an xmlTestRequest in quick succession of each other. The xmlTestRequests are parsed
*           into test driver objects and are run in parallel by the available child test threads. When the child
*           threads are finished with their testing they will post another test ready message to the console. 
*           After the tests have completed a final results log is printed. This is invoked after a delay but the 
*           results may be printed at any time.
*
******************************************************************************************************************/
void Executive::RunSampleTestSequence()
{
   cout << "\n*******************************************************";
   cout << "\n*  Executor starting test server and child processes  *";
   cout << "\n*******************************************************";
   testHarness.start();
   Sleep(1000); //Just so console is easier to read, can be removed

   cout << "\n";
   cout << "\n*******************************************************";
   cout << "\n*           Executor adding test requests             *";
   cout << "\n*******************************************************";

   Client client1(&testHarness);
   Client client2(&testHarness);
   Client client3(&testHarness);

   //SampleDriverA test routine returns false with no exceptions
   //SampleDriverB test routine returns true
   //SampleDriverC test routine returns true but generates badcast exception
   //SampleDriverD test routine returns true
   string xmlTestRequest1 = string("<testelement>SampleDriverA.dll</testelement>");
   string xmlTestRequest2 = string("<testelement>SampleDriverB.dll</testelement>") +
                            string("<testelement>SampleDriverC.dll</testelement>");
   string xmlTestRequest3 = string("<testelement>SampleDriverD.dll</testelement>");

   //Add TestRequests in quick succession
   client1.AddTests(xmlTestRequest1);
   client2.AddTests(xmlTestRequest2);
   client3.AddTests(xmlTestRequest3);
   Sleep(20000); //Wait for tests to complete

   cout << "\n";
   cout << "\n*******************************************************";
   cout << "\n*           Executor printing test results            *";
   cout << "\n*******************************************************";
   cout << "\n";
   testHarness.printLevelOneLog();
   testHarness.printLevelTwoLog();
   testHarness.printLevelThreeLog();
}

int main()
{
   SocketSystem ss;
   Executive executive(5);

   executive.RunSampleTestSequence();
   while (1) {};
}

