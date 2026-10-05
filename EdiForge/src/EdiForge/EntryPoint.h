#pragma once
#include "Application.h"
#include "Core.h"
#include "Log.h"

#ifdef EF_Platform_Windows

extern EdiForge::Application* EdiForge::CreateApplication();

int main(int argc, char** argv)
{
        
    auto app = EdiForge::CreateApplication();
    printf("EdiForge engine\n");
    EdiForge::Log::Init();
    EF_CORE_ERROR("Error");
    int a = 5;
    EF_WARN("Var={0}",a);
    app->Run();
    delete app;
}



#endif