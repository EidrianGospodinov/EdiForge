#pragma once
namespace EdiForge
{
    enum EventType
    {
        None = 0,
        KeyPress, KeyRelease,
        WindowResize
    };

    class EdiForge_API Event
    {
    public:
        virtual EventType GetEventType() = 0;
        virtual ~Event() = default;

    protected:
        EventType eventType;
    };

    class EventDispatcher
    {
    };

    class KeyEvent : public Event
    {
    public:
        int GetKeyCode() const
        {
            return _keycode;
        }

    protected:
        KeyEvent(int keycode) : _keycode(keycode)
        {
        }

    private:
        int _keycode;
    };

    class KeyEventPressed : public KeyEvent
    {
    public:
        KeyEventPressed(int keycode, int repeatCount) : KeyEvent(keycode), _repeatCount(repeatCount)
        {
        }

        int GetRepeatCount() const { return _repeatCount; }

        virtual EventType GetEventType() override { return EventType::KeyPress; }

    private:
        int _repeatCount;
    };

    class KeyEventReleased : public KeyEvent
    {
    public:
        KeyEventReleased(int keycode) : KeyEvent(keycode)
        {
        }

        virtual EventType GetEventType() override { return EventType::KeyRelease; }
    };
}
