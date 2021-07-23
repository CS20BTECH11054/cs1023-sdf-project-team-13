#include "menuWindow.h"
#include <iostream>
#include <unistd.h>
menuWindow::menuWindow()
{
    /// setting up menu background
    this->texturebg.loadFromFile("Background/menubg.jpg");
    this->spritebg.setTexture(this->texturebg);
    sf::Vector2u bgsize=this->texturebg.getSize();
    spritebg.setScale(1920/static_cast<float>(bgsize.x),1080/static_cast<float>(bgsize.y));
    spritebg.setPosition(0.f,0.f);
    
    for(int i=0;i<4;i++)
    {
        _tile[i] = new tile();
    }
    /// setting up text and tiles
    this->font.loadFromFile("Fonts/LibreBaskerville-Italic.ttf");
    text[0].setString("Play");
    text[1].setString("Help");
    text[2].setString("About");
    text[3].setString("Close");
    for(int i=0;i<4;i++)
    {
        this->text[i].setCharacterSize(55);
        this->text[i].setFillColor(sf::Color::Blue);
        this->text[i].setFont(this->font);
        this->text[i].setPosition(700.f,300.f+200*i);
        _tile[i]->tiles.setPosition(500.f,250.f+200*i);
    }
}

/// resetting screen to original condition
void menuWindow::reset()
{
    _tile[0]->state = "Hover";
    _tile[0]->tiles.setFillColor(sf::Color::Red);
    _tile[0]->updateColor();
    for(int i=1;i<4;i++)
    {
        _tile[i]->state = "NULL";
        _tile[i]->updateColor();
        _tile[i]->tiles.setFillColor(sf::Color::Yellow);
    }
    event.key.code = sf::Keyboard::Space;
}

/// function to render graphics on screen
void menuWindow::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(spritebg);
    for(int i=0;i<4;i++)
    {
        _tile[i]->setText(text[i]);
        window.draw(_tile[i]->tiles);
        window.draw(_tile[i]->text);
    }
    window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
    window.display();
}

jump_t menuWindow::call(sf::RenderWindow& window)
{
    int i;
    reset();
    while(true)
    {
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::KeyPressed)
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Up: 
                        for(i=0;i<4;i++)
                            if(_tile[i]->state == "Hover")
                            {
                                _tile[i]->state = "NULL";
                                _tile[i]->updateColor();
                                _tile[(i+3)%4]->state = "Hover";
                                _tile[(i+3)%4]->updateColor();
                                break;
                            }
                        break;
                    case sf::Keyboard::Down:
                        for(i=0;i<4;i++)
                            if(_tile[i]->state == "Hover")
                            {
                                _tile[i]->state = "NULL";
                                _tile[i]->updateColor();
                                _tile[(i+1)%4]->state = "Hover";
                                _tile[(i+1)%4]->updateColor();
                                break;
                            }
                        break;
                    case sf::Keyboard::Enter:
                        for(i=0;i<4;i++)
                        {
                            if(_tile[i]->state == "Hover")
                            {
                                _tile[0]->tiles.setFillColor(sf::Color::Yellow);
                                _tile[i]->tiles.setFillColor(sf::Color::Red);
                                break;
                            }
                        }
                }
            }
            render(window);
            if(event.key.code==sf::Keyboard::Enter)
            {
                sleep(1);
                if(_tile[i]->text.getString()=="Play")
                    return jump_t::LEVELS;
                if(_tile[i]->text.getString()=="Close")
                    return jump_t::CLOSE;
                if(_tile[i]->text.getString()=="Help")
                    return jump_t::HELP;
                if(_tile[i]->text.getString()=="About")
                    return jump_t::ABOUT;
            }
        }
    }
}
