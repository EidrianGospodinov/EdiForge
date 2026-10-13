#include "Application.h"

#include "Log.h"
#include "EventSystem/Event.h"

namespace EdiForge
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        KeyEventPressed e(43,4);
        EF_TRACE(e.GetRepeatCount());
        
        while (true);
    }
   
}


