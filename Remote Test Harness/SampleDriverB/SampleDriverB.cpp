/////////////////////////////////////////////////////////////////////////////////////////////////
// SampleDriverB.cpp - Defines SampleDriverB test driver class, implements RunTest routine     //
//                     and also exports Create routine to create an instance of SampleDriverB  //
// ver 1.0                                                                                     //
// Language:      Visual C++ 2010, SP1                                                         //
// Application:   Project 1 CSE 687                                                            //
// Author:        John Schurman, Terence Lau                                                   //
/////////////////////////////////////////////////////////////////////////////////////////////////
#include "SampleDriverB.h"

using namespace std;

#ifdef SAMPLEDRIVERB_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

/******************************************************************************************************************
* Function: RunTest
* Notes:    This function is the test routine for SampleDriverB, it returns true with no exceptions generated.
*
******************************************************************************************************************/
bool SampleDriverB::RunTest()
{
   cout << "\nSampleDriverB test routine invoked";

   int testMsgs = 15;
   for (int i = 1; i <= testMsgs; i++)
   {
      cout << "\nDriverB test msg " + std::to_string(i) + " of " + std::to_string(testMsgs);
      Sleep(500);
   }

   //No exceptions, test passed
   return true;
}

/******************************************************************************************************************
* Destructor: ~SampleDriverB
* Notes:      To demonstrate SampleDriverB properly cleaned up
*
******************************************************************************************************************/
SampleDriverB::~SampleDriverB()
{
   cout << "SampleDriverB Destructor was invoked" << endl;
}

/******************************************************************************************************************
* Function: Create
* Notes:    This function is an exported routine that creates an instance of SampleDriverB and returns a handle
*           to the object, meant to be invoked by TestFactory.
*
******************************************************************************************************************/
DLLEXPORT ITest* Create()
{
   ITest* testDriverB = new SampleDriverB();
   return testDriverB;
}



