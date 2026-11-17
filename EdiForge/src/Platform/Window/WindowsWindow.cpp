#include "efpch.h"
#include "WindowsWindow.h"

#include "EdiForge/Log.h"

namespace EdiForge
{
    static bool s_GLFWInitialized = false;

    EdiForge::Window* EdiForge::Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    void EdiForge::WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(_Window);
    
    }



    void EdiForge::WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        _Data.VSync = enabled;
    }

    bool EdiForge::WindowsWindow::IsVSync() const
    {
        return _Data.VSync;
    }

    EdiForge::WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }

    EdiForge::WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void EdiForge::WindowsWindow::Init(const WindowProps& props)
    {
        _Data.Title = props.Title;
        _Data.Width = props.Width;
        _Data.Height = props.Height;

        //EF_CORE_INFO("Creating window {0} ({1}, {2}", props.Title, props.Width, props.Height);
        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            EF_CORE_INFO("Could not initialize GLFW-{0}",success );

            s_GLFWInitialized = true;
        
        }
        _Window = glfwCreateWindow((int)props.Width, (int)props.Height, _Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(_Window);
        glfwSetWindowUserPointer(_Window, &_Data);
        SetVSync(true);
    
    }

    void EdiForge::WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(_Window);
    }
}
