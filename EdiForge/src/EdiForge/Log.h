#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"
#include <Memory>

namespace EdiForge
{
    class EdiForge_API Log
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
//macros
//core log
#define EF_CORE_INFO(...)   ::EdiForge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EF_CORE_ERROR(...)  ::EdiForge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EF_CORE_WARN(...)   ::EdiForge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EF_CORE_TRACE(...)  ::EdiForge::Log::GetCoreLogger()->trace(__VA_ARGS__)

//client log
#define EF_INFO(...)        ::EdiForge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EF_ERROR(...)       ::EdiForge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EF_WARN(...)        ::EdiForge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EF_TRACE(...)       ::EdiForge::Log::GetCoreLogger()->trace(__VA_ARGS__)
