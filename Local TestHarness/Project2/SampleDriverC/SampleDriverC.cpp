/////////////////////////////////////////////////////////////////////////////////////////////////
// SampleDriverC.cpp - Defines SampleDriverC test driver class, implements RunTest routine     //
//                     and also exports Create routine to create an instance of SampleDriverC  //
// ver 1.0                                                                                     //
// Language:      Visual C++ 2010, SP1                                                         //
// Application:   Project 1 CSE 687                                                            //
// Author:        John Schurman, Terence Lau                                                   //
/////////////////////////////////////////////////////////////////////////////////////////////////
#include "SampleDriverC.h"

using namespace std;

#ifdef SAMPLEDRIVERC_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

struct Foo { virtual ~Foo() {} };
struct Bar { virtual ~Bar() {} };

/******************************************************************************************************************
* Function: badCastF
* Notes:    This function generates a bad cast exception.
*
******************************************************************************************************************/
void _stdcall badCastF() 
{
   Bar b;
   Foo& f = dynamic_cast<Foo&>(b);
}

/******************************************************************************************************************
* Function: RunTest
* Notes:    This function is the test routine for SampleDriverC, it returns true but generates a bad cast
*           exception.
*
******************************************************************************************************************/
bool SampleDriverC::RunTest()
{
   cout << "SampleDriverC test routine invoked" << endl;
   badCastF();

   //No exceptions, test passed
   return true;
}

/******************************************************************************************************************
* Destructor: ~SampleDriverC
* Notes:      To demonstrate SampleDriverC properly cleaned up
*
******************************************************************************************************************/
SampleDriverC::~SampleDriverC()
{
   cout << "SampleDriverC Destructor was invoked" << endl;
}

/******************************************************************************************************************
* Function: Create
* Notes:    This function is an exported routine that creates an instance of SampleDriverC and returns a handle
*           to the object, meant to be invoked by TestFactory.
*
******************************************************************************************************************/
DLLEXPORT ITest* Create()
{
   ITest* testDriverC = new SampleDriverC();
   return testDriverC;
}



