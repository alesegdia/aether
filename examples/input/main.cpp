#include <aether/aether.h>

/*
class NormalScreen : public aether::core::IScreen
{
public:
    virtual int Load() final
    {
        if (false == m_texture.IsValid())
        {
            m_texture.Load("media/aether-logo.PNG");
        }

        m_position.Set(0, 0);
        return 0;
    }

    virtual int Unload() final
    {
        return 0;
    }

    virtual void Render() final
    {
        aether::graphics::clear(1.f, 0.f, 0.f);
        m_texture.Draw(m_position.GetX(), m_position.GetY());
    }

    virtual void Update(uint64_t delta) final
    {
        aether::math::Vec2f delta_pos(0, 0);

        if( aether::core::is_key_down(aether::core::KeyCode::Left) )
        {
            delta_pos.SetX(-1);
        }
        else if( aether::core::is_key_down(aether::core::KeyCode::Right) )
        {
            delta_pos.SetX(1);
        }

        if( aether::core::is_key_down(aether::core::KeyCode::Up) )
        {
            delta_pos.SetY(-1);
        }
        else if( aether::core::is_key_down(aether::core::KeyCode::Down) )
        {
            delta_pos.SetY(1);
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

    virtual int Init(const aether::core::CommandLineArguments& args) override { return 0; }
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
    return MyGame(200, 200).Exec(args);
}
*/