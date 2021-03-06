/////////////////////////////////////////////////////////////////////////////////////////////////
// SampleDriverD.cpp - Defines SampleDriverD test driver class, implements RunTest routine     //
//                     and also exports Create routine to create an instance of SampleDriverD  //
// ver 1.0                                                                                     //
// Language:      Visual C++ 2010, SP1                                                         //
// Application:   Project 1 CSE 687                                                            //
// Author:        John Schurman, Terence Lau                                                   //
/////////////////////////////////////////////////////////////////////////////////////////////////
#include "SampleDriverD.h"

using namespace std;

#ifdef SAMPLEDRIVERD_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

/******************************************************************************************************************
* Function: RunTest
* Notes:    This function is the test routine for SampleDriverD, it returns true but generates a bad cast
*           exception.
*
******************************************************************************************************************/
bool SampleDriverD::RunTest()
{
   cout << "\nSampleDriverD test routine invoked";

   int testMsgs = 5;
   for (int i = 1; i <= testMsgs; i++)
   {
      cout << "\nDriverD test msg " + std::to_string(i) + " of " + std::to_string(testMsgs);
      Sleep(200);
   }

   //No exceptions, test passed
   return true;
}

/******************************************************************************************************************
* Destructor: ~SampleDriverD
* Notes:      To demonstrate SampleDriverD properly cleaned up
*
******************************************************************************************************************/
SampleDriverD::~SampleDriverD()
{
   cout << "SampleDriverD Destructor was invoked" << endl;
}

/******************************************************************************************************************
* Function: Create
* Notes:    This function is an exported routine that creates an instance of SampleDriverD and returns a handle
*           to the object, meant to be invoked by TestFactory.
*
******************************************************************************************************************/
DLLEXPORT ITest* Create()
{
   ITest* testDriverD = new SampleDriverD();
   return testDriverD;
}



