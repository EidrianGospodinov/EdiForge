#pragma once


#include "efpch.h"

#include <spdlog/fmt/bundled/base.h>

#include "EdiForge/Core.h"
#include "EdiForge/EventSystem/Event.h"

namespace EdiForge
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;


        WindowProps(const std::string& title = "Edi Forge", unsigned int width = 1280, unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {
        }
    };

    class EdiForge_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}
        virtual void OnUpdate() = 0;
        virtual unsigned int GetCharWidth() const = 0;
        virtual unsigned int GetCharHeight() const = 0;


        virtual void SetEventCallback(const std::function<void(Event&)>& callback) = 0;

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
        
        
    };
}
