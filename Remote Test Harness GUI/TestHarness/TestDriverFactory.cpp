////////////////////////////////////////////////////////////////////////////////////////
// TestFactory.cpp - Defines TestFactory class which makes use of singleton design    //
//                   pattern, only one instance of class should ever exist.           //
//                   TestFactory is used to instantiate instances of test drivers.    //
//                   Defines ITest interface to be implemented by every test driver.  //
// ver 1.0                                                                            //
// Language:      Visual C++ 2010, SP1                                                //
// Application:   Project 1 CSE 687                                                   //
// Author:        John Schurman, Terence Lau                                          //
////////////////////////////////////////////////////////////////////////////////////////
#include "TestDriverFactory.h"

/******************************************************************************************************************
* Member: p_factInstance
* Notes:  This class member is the pointer to the testFactory singleton, initially NULL
*
******************************************************************************************************************/
TestFactory* TestFactory::p_factInstance = NULL;

/******************************************************************************************************************
* Function: Instance
* Notes:    This function checks if the testFactory singleton has been created yet, if it has not it creates a 
*           new TestFactory object, if it has it returns a handle to existing testFactory object.
*
******************************************************************************************************************/
TestFactory* TestFactory::Instance()
{
   if (!p_factInstance)
      p_factInstance = new TestFactory;

   return p_factInstance;
}

/******************************************************************************************************************
* Function: CreateTestDriver
* Notes:    This function creates a test driver object given a test driver dll name. This function first attempts
*           to load the corresponding dll and import the "Create" function. This function then tries to create 
*           a test driver object by invoking the "Create" function and returns the handle to that object.
*
******************************************************************************************************************/
ITest* TestFactory::CreateTestDriver(std::string testDriverName)
{
   HINSTANCE hDLL = LoadLibraryA(testDriverName.c_str());
   ITest* testDriverHandle = nullptr;

   if (!hDLL)
   {
      //DLL failed to load
      std::cout << "Failed to load DLL" << std::endl;
   }
   else
   {
      //DLL load success, Import "Create", Create test driver object
      FARPROC funct = GetProcAddress(hDLL, "Create");
      testDriverHandle = (ITest*)funct();
   }   

   return testDriverHandle;
}

#ifdef TEST_TESTDRIVERFACTORY
int main()
{
   //Test TestDriver here
    return 0;
}
#endif

