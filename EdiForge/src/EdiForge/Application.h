#pragma once
#include "Core.h"
#include "Window.h"

namespace EdiForge
{
    class  EdiForge_API Application
    {
    public:
        Application();
        virtual ~Application();
        
        void Run();
    private:
        std::unique_ptr<Window> _Window;
        bool _Running = true;
    };

    // To be defined in CLIENT
    Application*CreateApplication();    
}
