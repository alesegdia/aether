#pragma once


namespace aether::core
{

    class ModuleObject
    {
    public:
        ModuleObject* GetOwner() const { return owner; }

    protected:
        ModuleObject* owner;

        ModuleObject(ModuleObject* o) { owner = o; }

    };

}

