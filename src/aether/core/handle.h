#pragma once


namespace aether {
namespace core {

class Handle
{
public:
    Handle();

    Handle(const Handle& other);

    bool valid() const;
    bool notValid() const
    {
        return ! valid();
    }

protected:
	int handle() const;
    void handle(int h);
    void invalidate();

private:
    int m_handle;


};
}
}
