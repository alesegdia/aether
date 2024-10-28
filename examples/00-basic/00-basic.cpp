#include <aether/aether.h>

class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}

    virtual int Ready(const aether::core::CommandLineArguments& args) override
    {
        return 0;
    }

};

int main( int argc, char** argv )
{
    aether::core::CommandLineArguments args(argc, argv);
    return MyGame(200, 200).Exec(args);
}
