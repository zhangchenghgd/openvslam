/**
* @brief: helper_exports.h
* @author: Zhang Cheng
*/

#ifndef OPENVSLAM_TEST_HELPER_EXPORTS_H
#define OPENVSLAM_TEST_HELPER_EXPORTS_H
 
#if !defined _CRT_SECURE_NO_DEPRECATE && _MSC_VER > 1300
    #define _CRT_SECURE_NO_DEPRECATE /* to avoid multiple Visual Studio 2005 warnings */
#endif

#if (defined WIN32 || defined _WIN32 || defined WINCE)
    
    #if defined(OPENVSLAM_TEST_HELPER_DLL_EXPORT)
        #define OPENVSLAM_TEST_HELPER_API __declspec(dllexport)
    #else
        #define OPENVSLAM_TEST_HELPER_API __declspec(dllimport)
    #endif

    #pragma warning ( disable : 4251 ) //disable warning to templates with dll linkage.
    #pragma warning ( disable : 4290 ) //disable warning due to exception specifications.
    #pragma warning ( disable : 4996 ) //disable warning regarding unsafe vsprintf.
    #pragma warning ( disable : 4244 ) //disable warning convesions with lost of data.
#else
    #define OPENVSLAM_TEST_HELPER_API
#endif



#endif // OPENVSLAM_TEST_HELPER_EXPORTS_H
