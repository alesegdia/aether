
#include <aether/aether.h>

class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}

    int Ready(const aether::core::CommandLineArguments& args) override
    {
		auto asepriteAnimData = aether::render::AsepriteAnimationLoader().Load("media/dknight.json");
		m_spriteNode = aether::GEngine->CreateSpriteNode(glm::fvec2{32, 32});
        m_spriteNode->SetRelativePosition({ 400, 300, 0 });
		m_spriteNode->LoadAllAnimations(asepriteAnimData);
        m_spriteNode->PlayAnimation("front");
        return 0;
    }

    void GameStep(uint64_t delta) override
    {
		if (aether::core::is_key_just_pressed(aether::core::KeyCode::Q))
		{
            m_spriteNode->PlayAnimation("front");
        }
        else if (aether::core::is_key_down(aether::core::KeyCode::W))
        {
            m_spriteNode->PlayAnimation("back");
        }
        else if (aether::core::is_key_down(aether::core::KeyCode::E))
        {
            m_spriteNode->PlayAnimation("side");
        }
    }

private:
    aether::scene::ISpriteNode* m_spriteNode;

};

int main( int argc, char** argv )
{
    aether::core::CommandLineArguments args(argc, argv);
    return MyGame(800, 600).Exec(args);
}