#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#ifdef WIN32
#    ifdef example_EXPORTS                       // <libname>_EXPORTS is a macro added only for shared libraries
#        define DLLEXPORT __declspec(dllexport)  // Enabled as "export" while compiling the dll project
#    else
#        define DLLEXPORT __declspec(dllimport)  // Enabled as "import" in the Client side for using already created dll file
#    endif
#else
#    define DLLEXPORT
#endif

/**
 * Expose Library methods.
 *
 * extern "C" specifies that the function is defined
 * elsewhere and uses the C-language calling convention.
 */
extern "C"
{
    DLLEXPORT int GetRandom();
    DLLEXPORT int PreAllocTest(double* ppdoubleArrayReceiver);
    DLLEXPORT int AllocInTest(double* ppdoubleArrayReceiver);
    DLLEXPORT void MyFree(double* ppdoubleArrayReceiver);
    DLLEXPORT void Write();
};

#endif