#include "efpch.h"
#include "Application.h"

#include "Log.h"
#include "EventSystem/Event.h"
#include <GLFW//glfw3.h>

namespace EdiForge
{
    Application::Application()
    {
        _Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        EF_TRACE("Hello");
        
        while (_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            _Window->OnUpdate();
        }
        /*KeyEventPressed e(43,4);
        EF_TRACE(e.GetRepeatCount());
        
        while (true);*/
    }
}
