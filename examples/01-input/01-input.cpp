#include <aether/aether.h>

class NormalScreen : public aether::core::IScreen
{
public:

    virtual int Load() final
    {
        m_spriteNode = aether::GEngine->CreateSpriteNode("media/aether-logo.png");
        m_spriteNode->SetRelativePosition({ 400, 300, 0 });
		aether::GEngine->GetRenderModuleAccessor()->SetClearColor({ 1.f, 0.f, 1.f, 1.f });
        return 0;
    }

    virtual void Update(uint64_t delta) final
    {
        glm::vec3 delta_pos(0, 0, 0);

        if( aether::core::is_key_down(aether::core::KeyCode::Left) )
        {
            delta_pos.x = -1;
        }
        else if( aether::core::is_key_down(aether::core::KeyCode::Right) )
        {
            delta_pos.x = 1;
        }

        if( aether::core::is_key_down(aether::core::KeyCode::Up) )
        {
            delta_pos.y = -1;
        }
        else if( aether::core::is_key_down(aether::core::KeyCode::Down) )
        {
            delta_pos.y = 1;
        }

        float d = float(delta) / 10e4;
        static constexpr float SPEED = 20.f;
        m_spriteNode->SetRelativePosition(m_spriteNode->GetRelativePosition() + delta_pos * (d * SPEED));
    }

private:
    aether::scene::ISpriteNode* m_spriteNode;

};


class MyGame : public aether::core::Application
{
public:
    std::vector<std::string> GetAssetPaths() const override
    {
        return { "media/" };
    }

    MyGame(int w, int h) : aether::core::Application(w, h) {}

    virtual int Ready(const aether::core::CommandLineArguments& args) override
    {
        auto scr = std::static_pointer_cast<aether::core::IScreen>(std::make_shared<NormalScreen>());
        SetScreen(scr);
        return 0;
    }

private:

};


int main( int argc, char** argv )
{
    aether::core::CommandLineArguments args(argc, argv);
    return MyGame(800, 600).Exec(args);
}


