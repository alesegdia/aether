
#include <aether/aether.h>

class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}

    int Ready(const aether::core::CommandLineArguments& args) override
    {
		//m_textNode = aether::GEngine->CreateTextNode();
		//if (m_textNode == nullptr) return -1;

        //m_textNode->SetFont("examples/04-text/dafont.ttf");
		//m_textNode->SetText("Hello AETHER!");
        return 0;
    }

    void GameStep(uint64_t delta) override
    {
        int dx, dy;
        dx = dy = 0;
        static constexpr float speed = 3.f;
        if (aether::core::is_key_just_pressed(aether::core::KeyCode::Escape))
        {
            Quit();
        }

        if (aether::core::is_key_down(aether::core::KeyCode::Down))
        {
            dy = 1;
        }

        if (aether::core::is_key_down(aether::core::KeyCode::Up))
        {
            dy = -1;
        }

        if (aether::core::is_key_down(aether::core::KeyCode::Right))
        {
            dx = 1;
        }

        if (aether::core::is_key_down(aether::core::KeyCode::Left))
        {
            dx = -1;
        }
        //m_textNode->Move({ speed * dx, speed * dy });
    }

private:
    aether::scene::ITextNode* m_textNode;
	aether::render::Font* m_font;

};

int main(int argc, char** argv)
{
    aether::core::CommandLineArguments args(argc, argv);
    return MyGame(800, 600).Exec(args);
}
