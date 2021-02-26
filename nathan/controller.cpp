#include "Controller.h"

void Controller::run()
{
    m_window.create(sf::VideoMode(1000, 1000), "Lode Runner");
    while(menu() == Play)
         startGame();
    m_window.close();
}
//-------------------------------------
void Controller::startGame()
{
    for (auto line = std::string();std::getline(m_fileName, line);m_stageNumber++) {
        m_stageSize = std::stoi(line);
        m_board.setBoard(m_fileName, m_stageSize,m_shapesSource);
        m_window.create(sf::VideoMode(m_board.getSize().x, m_board.getSize().y), "Lode Runner");
        if (!play()) {
            //print game over info and quit
            break;
        }
    }
}
//--------------------------------------
bool Controller::play()
{
    sf::Clock clock;
    while (true) {
        display();
        if (clock.getElapsedTime().asMilliseconds() > 100)
        {
            m_board.moveObjects();
            //Checks if the player is completely dead and the game should end
            if (m_board.playerDead())
                return false;
            //Checks if is end of stage
            if (m_board.allGiftsTaken())
                break;
            clock.restart();
        }
        auto event = sf::Event();
        checkCloseEvent(event);
    }
    return true;
}
//--------------------------------------
void Controller::display()
{
    m_window.clear();
    m_board.draw(m_window);
    m_window.display();
}
//--------------------------------------
MenuOp Controller::menu()
{
    //create Play and Exit bars
    Texture playTexture, exitTexture;
    playTexture.loadFromFile("play.png");
    exitTexture.loadFromFile("exit.png");
    Sprite playBar(playTexture), exitBar(exitTexture);
    playBar.setPosition(400,100);
    exitBar.setPosition(400, 400);
   
    while (m_window.isOpen())
    {
        //draw the bars and display on screen 
        m_window.clear();
        m_window.draw(playBar);
        m_window.draw(exitBar);
        m_window.display();

        //check if the user pressed on one of the bars (or exit
        if (auto event = sf::Event();m_window.pollEvent(event)) {
            checkCloseEvent(event);
            if( sf::Event::MouseButtonPressed)
                if (playBar.getGlobalBounds().contains(
                    m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
                    return Play;
                else if (exitBar.getGlobalBounds().contains(
                    m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
                    return Exit;
        }
    }
}

void Controller::checkCloseEvent(sf::Event& event)
{
    if (event.type == sf::Event::Closed ||
        event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        m_window.close();
        m_board.clear();
    }
}
