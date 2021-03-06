/////////////////////////////////////////////////////////////////////////////////////////////////
// SampleDriverA.cpp - Defines SampleDriverA test driver class, implements RunTest routine     //
//                   and also exports Create routine to create an instance of SampleDriverA    //
// ver 1.0                                                                                     //
// Language:      Visual C++ 2010, SP1                                                         //
// Application:   Project 1 CSE 687                                                            //
// Author:        John Schurman, Terence Lau                                                   //
/////////////////////////////////////////////////////////////////////////////////////////////////
#include "SampleDriverA.h"

using namespace std;

#ifdef SAMPLEDRIVERA_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

/******************************************************************************************************************
* Function: RunTest
* Notes:    This function is the test routine for SampleDriverA, it returns false and generates no exceptions.
*
******************************************************************************************************************/
bool SampleDriverA::RunTest()
{
   cout << "\nSampleDriverA test routine invoked";
   int testMsgs = 15;
   for (int i = 1; i <= testMsgs; i++)
   {
      cout << "\nDriverA test msg " + std::to_string(i) + " of " + std::to_string(testMsgs);
      Sleep(1000);
   }

   //Fail Test with no exceptions
   return false;
}

/******************************************************************************************************************
* Destructor: ~SampleDriverA
* Notes:      To demonstrate SampleDriverA properly cleaned up
*
******************************************************************************************************************/
SampleDriverA::~SampleDriverA()
{
   cout << "SampleDriverA Destructor was invoked" << endl;
}

/******************************************************************************************************************
* Function: Create
* Notes:    This function is an exported routine that creates an instance of SampleDriverA and returns a handle
*           to the object, meant to be invoked by TestFactory.
*
******************************************************************************************************************/
DLLEXPORT ITest* Create()
{
   ITest* testDriverA = new SampleDriverA();
   return testDriverA;
}



