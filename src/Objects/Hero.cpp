#include "Hero.h"

Hero::Hero(Environment& env)
:   GameObject(env, ObjectTypeManager::instance()->get(0))
{
    tick();
}

void Hero::tick()
{
    auto mp = static_cast<sf::Vector2<double>>(sf::Mouse::getPosition(m_env.getContext().window));
    Context& ctx = m_env.getContext();

    if (mp.x < 0 || mp.y < 0 || mp.x > ctx.config.width || mp.y > ctx.config.height)
    {
        return;
    }

    auto op = sf::Vector2<double>(ctx.config.width / 2,
                                  ctx.config.height / 2);
    float rad = static_cast<float>(atan2(mp.y - op.y, mp.x - op.x));
    auto attr = getAttr();

    attr.angle = (rad / (PI / 180)) + 90;
    setAttr(attr);
    setPosition(m_env.getContext().camera.getPosition());

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        attack();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        m_env.getContext().camera.move(m_attr.speed, -PI / 2);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        m_env.getContext().camera.move(m_attr.speed, PI / 2);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_env.getContext().camera.move(m_attr.speed, PI);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_env.getContext().camera.move(m_attr.speed, 0);
    }
}

void Hero::attack()
{
    if (canAttack())
    {
        auto msl = new Missile(m_env, this);
        msl->setPosition(getPosition());
        GameObject::attack();
    }
}
