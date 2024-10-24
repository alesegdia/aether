
#include <aether/aether.h>

class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}

    int Ready(const aether::core::CommandLineArguments& args) override
    {
        auto texture = aether::GEngine->GetRenderer()->LoadTextureFromFile("media/aether-logo.png");
        auto scn = aether::get_scene();
        //auto sprite = scn.CreateSpriteNode();
        
        return 0;
    }

    void Render() override
    {
        aether::core::Application::Render();
        // m_texture.Draw(10, 10);
    }

private:
    aether::render::Texture* m_texture;

};

int main( int argc, char** argv )
{
    aether::core::CommandLineArguments args(argc, argv);
    return MyGame(200, 200).Exec(args);
}
