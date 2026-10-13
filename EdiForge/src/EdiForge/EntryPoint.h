#pragma once
#include "Application.h"
#include "Core.h"
#include "Log.h"
#include "EventSystem/Event.h"

#ifdef EF_Platform_Windows

extern EdiForge::Application* EdiForge::CreateApplication();

int main(int argc, char** argv)
{
        
    auto app = EdiForge::CreateApplication();
    EdiForge::Log::Init();
    EF_CORE_ERROR("EdiForge engine\n");
    app->Run();
    delete app;
}



#endif