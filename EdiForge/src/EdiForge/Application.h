#pragma once
#include "Core.h"

namespace EdiForge
{
    class  EdiForge_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // To be defined in CLIENT
    Application*CreateApplication();    
}
