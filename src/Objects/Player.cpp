#include "Player.h"

Player::Player(Environment& env)
:   GameObject(env, Team::PLAYER)
{
    m_attr.team = Team::PLAYER;
    m_attr.missileSpeed = 10;
    m_attr.damage = 5;
    m_attr.attackSpeed = 0.25;
    m_attr.scale = 5.f;
}

void Player::tick()
{
    auto mp = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_env.getContext().window));
    auto op = sf::Vector2f(m_env.getContext().config.width / 2,
                           m_env.getContext().config.height / 2);
    float rad = atan2(mp.y - op.y, mp.x - op.x);

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
        m_env.getContext().camera.move(5, rad);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        m_env.getContext().camera.move(5, rad - PI);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_env.getContext().camera.move(5, rad - PI / 2);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_env.getContext().camera.move(5, rad + PI / 2);
    }
}

void Player::attack()
{
    if (canAttack())
    {
        auto msl = new Missile(m_env, m_attr);
        msl->setPosition(getPosition());
        GameObject::attack();
    }
}
