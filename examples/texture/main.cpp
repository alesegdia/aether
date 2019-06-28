#include <aether/aether.h>

class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}

    int ready(int argc, char **argv) override
    {
        m_texture.load("media/aether-logo.png");
        return 0;
    }

    void render() override
    {
        aether::core::Application::render();
        m_texture.draw(10, 10);
    }

private:
    aether::graphics::Texture m_texture;


};

int main( int argc, char** argv )
{
    MyGame(200, 200).exec(argc, argv);
}
