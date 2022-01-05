#include "MainMenuScene.h"
#include "Niveau1.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{

    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    //LA CREATION DES ELEMENTS DE MENU

    auto playItem = MenuItemImage::create("MainMenu/CloseNormal.png", "MainMenu/CloseNormal.png",
            CC_CALLBACK_1(MainMenu::GoToGameScene, this));

    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point((visibleSize.width / 2) +
    origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(menu);

    auto backgroundSprite = Sprite::create("MainMenu/BackgroundMenu.png");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(backgroundSprite, -2);


    return true;
}


// LA FONCTION QUI PERMENT DE PASSER AU 1ER NIVEAU: 

void MainMenu::GoToGameScene(Ref* pSender)
{
    auto scene = Niveau1::createScene();

    Director::getInstance()->replaceScene(scene);
}