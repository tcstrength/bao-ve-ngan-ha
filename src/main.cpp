#include "Engines/GameEngine.h"

//void test()
//{
//    ObjectTypeManager* mng = ObjectTypeManager::instance();
//    ObjectType& hero = mng->make(0);
//    hero.attr.scale = 4.f;
//    hero.texture = TextureManager::instance()->get("hero.png");

//    ObjectType& aaa = mng->make(1);
//    aaa.attr.scale = 5.f;
//    aaa.texture = TextureManager::instance()->get("wtf.png");

//    mng->show();
//}

int main()
{
    Config config;
    GameEngine game(config);
    game.init();
    game.run();
    return 0;
}
