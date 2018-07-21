#include <aether/aether.h>

class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}
};

int main( int argc, char** argv )
{
    MyGame(200, 200).exec(argc, argv);
}
