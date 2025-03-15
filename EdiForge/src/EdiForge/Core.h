#pragma once

namespace EdiForge
{
    
#ifdef EF_Platform_Windows
    #ifdef EF_BUILD_DLL
        #define EdiForge_API __declspec(dllexport)
    #else
        #define EdiForge_API __declspec(dllimport)
    #endif
#else
    #error Only Windows is surrported
#endif
}
