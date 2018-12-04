#pragma once


namespace aether {
namespace core {

class Handle
{
public:
    Handle();

    Handle(const Handle& other);

    bool valid();
    bool notValid()
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
