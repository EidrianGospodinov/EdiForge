#pragma once
#include "Application.h"
#include "Core.h"

#ifdef EF_Platform_Windows

extern EdiForge::Application* EdiForge::CreateApplication();

int main(int argc, char** argv)
{
    auto app = EdiForge::CreateApplication();
    app->Run();
    delete app;
}



#endif