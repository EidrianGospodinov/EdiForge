#include <EdiForge.h>

class Sandbox : public EdiForge::Application
{
    public:
    Sandbox()
    {
        
    }
    ~Sandbox()
    {
        
    }
};
EdiForge::Application* EdiForge::CreateApplication()
{
    return new Sandbox();
}