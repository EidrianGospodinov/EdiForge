#pragma once
#include "Application.h"
#include "Core.h"
#include "Log.h"

#ifdef EF_Platform_Windows

extern EdiForge::Application* EdiForge::CreateApplication();

int main(int argc, char** argv)
{
    printf("EdiForge engine\n");
        
    auto app = EdiForge::CreateApplication();
    app->Run();
    EdiForge::Log::Init();
    EdiForge::Log::GetClientLogger()->warn("Init successfully");
    EdiForge::Log::GetCoreLogger()->info("Init successfully");
    delete app;
}



#endif