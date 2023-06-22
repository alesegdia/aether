#include <aether/aether.h>

class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}

    virtual int Init(int argc, char** argv) override
    {
        return 0;
    }

};

int main( int argc, char** argv )
{
    return MyGame(200, 200).Exec(argc, argv);
}
