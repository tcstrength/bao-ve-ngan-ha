#include "Object.h"

Object::Object(Context& context, ObjectType& type)
:   GameObject(context)
,   m_attr(type.attr)
{
    m_sprite.setTexture(TextureManager::instance()->get(type.attr.texture.c_str()));
    m_hpBar.setTexture(TextureManager::instance()->get("hpbar.png"));
    m_hpBar.setScale(0.5f, 0.5f);
    m_hpBarBack.setTexture(TextureManager::instance()->get("hpbar_back.png"));
    m_hpBarBack.setScale(0.5f, 0.5f);
    m_hpText.setFont(m_context.font);
    m_hpText.setCharacterSize(13);
    update();
}

Object::~Object()
{
    for (auto it : m_missiles)
    {
        delete it;
    }

    for (auto it : m_floatTexts)
    {
        delete it;
    }

    m_missiles.clear();
}

void Object::tick()
{
    for (auto it = m_missiles.begin(); it != m_missiles.end(); ++it)
    {
        if ((*it)->isDeath())
        {
            auto tmp = (*it);
            m_missiles.remove((*it++));
            delete tmp;
        }
        else
        {
            (*it)->tick();
        }
    }

    for (auto it = m_floatTexts.begin(); it != m_floatTexts.end(); ++it)
    {
        if ((*it)->isDeath())
        {
            auto tmp = (*it);
            m_floatTexts.remove((*it++));
            delete tmp;
        }
        else
        {
            (*it)->tick();
        }
    }

    if (m_attr.hitpoints == 0)
    {
        if (m_attr.decay <= 1 && m_attr.decay >= 0)
        {
            m_attr.color.a = static_cast<sf::Uint8>(static_cast<float>(255) * m_attr.decay);
            update();
        }

        m_attr.decay -= m_clock.getElapsedTime().asSeconds();
    }

    m_clock.restart();
}

void Object::render()
{
    for (auto it : m_missiles)
    {
        it->render();
    }

    m_context.window.draw(m_hpBarBack);
    m_context.window.draw(m_hpBar);
    m_context.window.draw(m_hpText);
    m_context.window.draw(m_sprite);

    for (auto it : m_floatTexts)
    {
        it->render();
    }
}

void Object::attack(Group& group)
{
    if (m_attackClock.getElapsedTime().asSeconds() >= m_attr.attackSpeed && m_attr.hitpoints > 0)
    {
        auto mss = new Missile(m_context, group, *this);
        mss->setPosition(m_position);
        m_missiles.push_back(mss);
        m_attackClock.restart();
    }
}

void Object::beingHit(DamageType dmgType, int dmg)
{
    if (m_attr.hitpoints == 0)
    {
        return;
    }

    switch(dmgType)
    {
        case DamageType::FIRE:
            dmg *= 2;
            break;

        case DamageType::NUCLEAR:
            dmg *= 3;
            break;

        case DamageType::NORMAL:
            break;
    }

    FloatingText* ft = nullptr;

    if (m_attr.player == Player::PLAYER)
    {
        ft = new FloatingText(m_context, sf::Color::Green);
    }
    else
    {
        ft = new FloatingText(m_context, sf::Color::Red);
    }

    ft->setPosition(getPosition());
    ft->setText(std::to_string(dmg));
    m_floatTexts.push_back(ft);

    m_attr.hitpoints -= dmg;

    if (m_attr.hitpoints < 0)
        m_attr.hitpoints = 0;

    update();
}

void Object::update()
{
    if (m_attr.hitpoints > m_attr.maxHitpoints)
        m_attr.maxHitpoints = m_attr.hitpoints;

    m_sprite.setScale(m_attr.scale, m_attr.scale);
    m_sprite.setColor(m_attr.color);
    m_sprite.setPosition(getCenterPoint());
    m_hpBar.setColor(m_attr.color);
    m_hpBarBack.setColor(m_attr.color);
    m_hpText.setFillColor(m_attr.color);
    m_hpText.setString(std::to_string(m_attr.hitpoints));
    updateHpBar();
    updateHpText();
}

void Object::updateHpBar()
{
    sf::Vector2f pos = m_position;
    sf::FloatRect rect = m_hpBarBack.getGlobalBounds();
    pos.x -= rect.width / 2;
    pos.y -= rect.height + 5 + getSize().y / 2;

    m_hpBar.setPosition(pos);
    m_hpBarBack.setPosition(pos);

    sf::IntRect backRect = m_hpBarBack.getTextureRect();
    float hpRate = static_cast<float>(m_attr.hitpoints) / m_attr.maxHitpoints;
    backRect.width *= hpRate;
    m_hpBar.setTextureRect(backRect);

//    pos = m_position;
//    rect = m_hpText.getGlobalBounds();

//    pos.x -= rect.width / 2;
//    pos.y -= rect.height + 5 + getSize().y / 2;
//    m_hpText.setPosition(pos);

}

void Object::updateHpText()
{
    sf::Vector2f pos = m_position;
    sf::FloatRect rect = m_hpText.getGlobalBounds();

    pos.x -= rect.width / 2;
    pos.y -= rect.height + 9 + getSize().y / 2;

    m_hpText.setPosition(pos);
}

Attributes& Object::getAttr()
{
    return m_attr;
}

void Object::setPosition(const sf::Vector2f& position)
{
    m_position = position;
    update();
}

sf::Vector2f Object::getSize() const
{
    auto rect = m_sprite.getGlobalBounds();
    return sf::Vector2f(rect.width, rect.height);
}

