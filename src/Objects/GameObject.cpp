#include "GameObject.h"

GameObject::GameObject(Environment & environment, const Attributes& attr)
:   m_env(environment)
,   m_index(m_env.add(this))
,   m_attr(attr)
{
    static TextureManager* mng = TextureManager::instance();

    m_hpBar.setTexture(mng->get("hpbar.png"));
    m_hpBar.setScale(1.f, 0.5);
    m_hpBarBack.setTexture(mng->get("hpbar_back.png"));
    m_hpBarBack.setScale(1.f, 0.5);
    m_hpText.setCharacterSize(12);
    m_hpText.setFillColor(sf::Color::White);
    m_hpText.setStyle(sf::Text::Bold);
    m_hpText.setFont(m_env.getContext().font);
    m_sprite.setTexture(mng->get(m_attr.texture.c_str()));
    m_sprite.setOrigin(getSpriteSize().x / 2, getSpriteSize().y / 2);

    update();
}

void GameObject::tick()
{
    EnvironmentObject::tick();

    if (m_env.getContext().camera.isChanged())
    {
        update();
    }

    if (m_attr.hitpoints <= 0 && m_decayTime <= 0)
    {
        m_env.del(m_index);
    }
}

void GameObject::render(sf::RenderWindow & window)
{
    if (m_attr.showHP)
    {
        window.draw(m_hpBarBack);
        window.draw(m_hpBar);
        window.draw(m_hpText);
    }

    window.draw(m_sprite);
}

void GameObject::update()
{
    correctAttr();
    m_sprite.setColor(getColor());
    m_sprite.setRotation(m_attr.angle);
    m_sprite.setScale(m_attr.scale, m_attr.scale);
    m_sprite.setPosition(m_env.getContext().camera.transform(m_position));

    if (m_attr.showHP)
    {
        updateHpBar();
        updateHpText();
    }
}

void GameObject::updateHpBar()
{
    sf::FloatRect rect = m_hpBarBack.getGlobalBounds();
    sf::Vector2f pos;
    sf::Color color = sf::Color::White;

    pos.x = m_position.x - rect.width / 2;
    pos.y = m_position.y - getSpriteSize().y * m_attr.scale - 7;
    pos = m_env.getContext().camera.transform(pos);

    color.a = m_attr.color.a;

    m_hpBar.setPosition(pos);
    m_hpBarBack.setPosition(pos);
    m_hpBar.setColor(color);
    m_hpBarBack.setColor(color);

    sf::IntRect trect = m_hpBarBack.getTextureRect();
    trect.width = static_cast<int>(trect.width * m_attr.hitpoints / m_attr.maxHitpoints);
    m_hpBar.setTextureRect(trect);
}

void GameObject::updateHpText()
{
    std::string str;
    str += std::to_string(m_attr.hitpoints);
    str += "/";
    str += std::to_string(m_attr.maxHitpoints);
    m_hpText.setString(str);

    sf::FloatRect rect = m_hpText.getGlobalBounds();
    sf::Vector2f pos;
    sf::Color color = sf::Color::White;

    pos.x = m_position.x - rect.width / 2;
    pos.y = m_position.y - getSpriteSize().y * m_attr.scale - 11;
    pos = m_env.getContext().camera.transform(pos);

    color.a = m_attr.color.a;

    m_hpText.setPosition(pos);
    m_hpText.setFillColor(color);
}

bool GameObject::isDead()
{
    return m_attr.hitpoints == 0;
}

void GameObject::attack()
{
    if (canAttack())
    {
        m_attackClock.restart();
    }
}

void GameObject::del()
{
    m_env.del(m_index);
}

void GameObject::beHit(DamageType type, int dmg)
{
    switch(type)
    {
        case DamageType::NUCLEAR:
            dmg = static_cast<int>(dmg * 4.f);
            break;

        case DamageType::FIRE:
            dmg = static_cast<int>(dmg * 1.5f);
            break;

        default:
            break;
    }

    if (m_attr.hitpoints - dmg >= 0)
    {
        m_attr.hitpoints -= dmg;
    }
    else
    {
        m_attr.hitpoints = 0;
    }

    update();
}

void GameObject::correctAttr()
{
    if (m_attr.hitpoints < 0)
        m_attr.hitpoints = 0;

    if (m_attr.hitpoints > m_attr.maxHitpoints)
        m_attr.hitpoints = m_attr.maxHitpoints;

    if (m_attr.attackSpeed < 0)
        m_attr.attackSpeed = 0;

    if (m_attr.damage < 0)
        m_attr.damage = 0;

    if (m_attr.missileSpeed < 0)
        m_attr.missileSpeed = 0;
}

const Attributes &GameObject::getAttr() const
{
    return m_attr;
}

void GameObject::setAttr(const Attributes & attr)
{
    m_attr = attr;
    update();
}

bool GameObject::canAttack()
{
    return m_attr.hitpoints > 0 &&
           m_attackClock.getElapsedTime().asSeconds() >= m_attr.attackSpeed;
}

void GameObject::setColor(const sf::Color & color)
{
    m_attr.color = color;
    update();
}

sf::Color GameObject::getColor() const
{
    return m_attr.color;
}

sf::Vector2f GameObject::getSize()
{
    sf::FloatRect rect = m_sprite.getGlobalBounds();
    return sf::Vector2f(rect.width, rect.height);
}

sf::Vector2f GameObject::getSpriteSize()
{
    sf::FloatRect rect = m_sprite.getLocalBounds();
    return sf::Vector2f(rect.width, rect.height);
}
