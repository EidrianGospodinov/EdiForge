#pragma once
#include "EdiForge/Window.h"
#include <GLfw/glfw3.h>

namespace EdiForge
{
    class WindowsWindow : public Window
    {
    public:
        void OnUpdate() override;

        inline void SetEventCallback(const EventCallbackFn& callback) override
        {
            _Data.EventCallBack = callback;
        }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        inline unsigned int GetWidth() const override{ return _Data.Width; }
        inline unsigned int GetHeight() const override{ return _Data.Height; }
                

    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
        
        GLFWwindow* _Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallBack;
        };

        WindowData _Data;
    };
}
