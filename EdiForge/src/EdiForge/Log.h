#pragma once
#include "spdlog/spdlog.h"
#include "Core.h"
#include <Memory>

namespace EdiForge
{
    class Edi_API Log
    {
        

    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){ return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){ return s_ClientLogger; }
    private:
       static std::shared_ptr<spdlog::logger> s_CoreLogger;
       static std::shared_ptr<spdlog::logger> s_ClientLogger;
        
    
    };
}
