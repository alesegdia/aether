#pragma once


namespace aether {
namespace core {

class Handle
{
public:
    Handle();

    Handle(const Handle& other);
    Handle(int handle);

    bool IsValid() const;
    bool IsNotValid() const;

protected:
	int GetHandle() const;
    void SetHandle(int h);
    void Invalidate();

private:
    int m_handle;


};
}
}
