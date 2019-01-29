#include "Hero.h"

Hero::Hero(Environment& env)
:   GameObject(env, ObjectTypeManager::instance()->get(0))
{
    tick();
    m_env.getCamera().bind(this);
}

void Hero::tick()
{
    auto mp = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_env.getContext().window));
    Context& ctx = m_env.getContext();

    if (mp.x < 0 || mp.y < 0 || mp.x > ctx.config.width || mp.y > ctx.config.height)
    {
        return;
    }

    auto op = sf::Vector2f(ctx.config.width / 2,
                           ctx.config.height / 2);

    float rad = radBetween2Vec(op, mp);
    setAngle(deg2sfDeg(rad2Deg(rad)));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        attack();
    }

    handleKeys();
    GameObject::tick();
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

void Hero::handleKeys()
{
    float angle = getAngle();
    float speed = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        speed = m_attr.speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        speed *= 2;
    }

    float rad = deg2Rad(sfDeg2Deg(angle));
    sf::Vector2f newPos = polarProjection(getPosition(), speed, rad);
    m_env.getCamera().setPosition(newPos);
    setPosition(newPos);
}











