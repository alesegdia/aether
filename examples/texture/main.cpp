#include <aether/aether.h>

class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}

    int Ready(int argc, char **argv) override
    {
        m_texture.Load("media/aether-logo.png");
        return 0;
    }

    void Render() override
    {
        aether::core::Application::Render();
        m_texture.Draw(10, 10);
    }

    virtual int Init(int argc, char** argv) override { return 0; }

private:
    aether::graphics::Texture m_texture;


};

int main( int argc, char** argv )
{
    return MyGame(200, 200).Exec(argc, argv);
}
