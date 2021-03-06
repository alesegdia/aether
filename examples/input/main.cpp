#include <aether/aether.h>

class NormalScreen : public aether::core::IScreen
{
public:
    void show() final
    {
        if( false == m_texture.valid() )
        {
            m_texture.load("media/aether-logo.PNG");
        }

        m_position.set(0, 0);
    }

    void hide() final
    {

    }

    void render() final
    {
        aether::graphics::clear(255, 0, 0);
        m_texture.draw(m_position.x(), m_position.y());
    }

    void update(uint64_t delta) final
    {
        aether::math::Vec2f delta_pos(0, 0);

        if( aether::core::is_key_down(aether::core::KeyCode::Left) )
        {
            delta_pos.x(-1);
        }
        else if( aether::core::is_key_down(aether::core::KeyCode::Right) )
        {
            delta_pos.x(1);
        }

        if( aether::core::is_key_down(aether::core::KeyCode::Up) )
        {
            delta_pos.y(-1);
        }
        else if( aether::core::is_key_down(aether::core::KeyCode::Down) )
        {
            delta_pos.y(1);
        }

        float d = float(delta) / 10e6;
        static constexpr float SPEED = 20.f;
        m_position = m_position + delta_pos * (d * SPEED);
    }

private:
    aether::graphics::Texture m_texture;
    aether::math::Vec2f m_position;

};


class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}

    int ready(int argc, char **argv) override
    {
        auto scr = std::static_pointer_cast<aether::core::IScreen>(std::make_shared<NormalScreen>());
        setScreen(scr);
        return 0;
    }

private:


};

int main( int argc, char** argv )
{
    return MyGame(200, 200).exec(argc, argv);
}
