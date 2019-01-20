/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalUIClass.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:55:45 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 19:56:10 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicalUIClass.hpp"
#include "IMonitorModuleClass.hpp"
#include "OsInfosModule.hpp"
#include "DatetimeModule.hpp"
#include "HostnameModule.hpp"
#include "CpuModule.hpp"
#include "UsernameModule.hpp"
#include <iostream>
#include <algorithm>

GraphicalUI::GraphicalUI(sf::RenderWindow &window) : _window(&window)
{
    this->_modules.push_back(new OsInfosModule());
	this->_modules.push_back(new HostnameModule());
	this->_modules.push_back(new DatetimeModule());
	this->_modules.push_back(new CpuModule());
	this->_modules.push_back(new UsernameModule());
	//this->_modules.push_back(new NetworkInfoModule(" NETWORK INFO "));
    if (!this->_font.loadFromFile("Fonts/Dosis-Light.ttf"))
		throw("COULD NOT LOAD FONT!");
    /*this->addTitles(15, "Hostname/username modules :", 50, 130);
    this->addTitles(15, "OSinfo :", 570, 130);
    this->addTitles(15, "Date/time module :", 120, 330);
    this->addTitles(15, "CPUmodule :", 570, 330);
    this->addTitles(15, "RAMmodule :", 120, 530);
    this->addTitles(15, "FT_GKRELLM", 300, 35); */
    this->addRectangle(800, 100, 0, 0);
    this->addRectangle(800, 600, 0, 100);
    if (!this->_space.loadFromFile("Textures/space.jpg"))
        return;
    if (!this->_metal.loadFromFile("Textures/metal.jpg"))
        return;
    if (!this->_cadre.loadFromFile("Textures/cadre.png"))
        return;

    return;
}

void    GraphicalUI::addTitles(int size, std::string text, int x, int y)
{
    sf::Text    text1;
    text1.setFont(this->_font);
	text1.setCharacterSize(size);
	text1.setColor(sf::Color::Red);
	//text1.setStyle(sf::Text::Bold);
	text1.setString(text);
	text1.setPosition(x, y);

    this->_titles.push_back(text1);
}

void    GraphicalUI::addRectangle(int size_x, int size_y, int pos_x, int pos_y)
{
    sf::Texture texture1;

    if (!texture1.loadFromFile("Textures/space.jpg"))
        return;
    sf::RectangleShape rect(sf::Vector2f(size_x, size_y));
    rect.setTexture(&texture1);
    rect.setPosition(sf::Vector2f(pos_x, pos_y));
    this->_rectangles.push_back(rect);
}

void    GraphicalUI::addCadre(int size_x, int size_y, int pos_x, int pos_y)
{
    sf::Texture texture1;

    if (!texture1.loadFromFile("Textures/space.jpg"))
        return;
    sf::RectangleShape rect(sf::Vector2f(size_x, size_y));
    rect.setPosition(sf::Vector2f(pos_x, pos_y));
    this->_cadres.push_back(rect);
}

void    GraphicalUI::render(void)
{
    this->_window->clear();
    this->_titles.erase(this->_titles.begin(), this->_titles.end());
    this->_cadres.erase(this->_cadres.begin(), this->_cadres.end());
    int     pos_x = 0;
    int     pos_y = 100;
    std::string     tmp;
    size_t     pospos;
    for(unsigned int i = 0; i < this->_modules.size(); i++)
    {
        tmp = this->_modules.at(i)->getInfos();
        pospos = tmp.find("Numb");
        if (pospos != std::string::npos)
            tmp[pospos - 1] = '\n';
        pospos = tmp.find("Cpu");
        if (pospos != std::string::npos)
            tmp[pospos - 1] = '\n';
        pospos = tmp.find("Cloc");
        if (pospos != std::string::npos)
            tmp[pospos - 1] = '\n'; 
        addTitles(15, tmp, pos_x + 50, pos_y + 50);
        if (pos_x == 0)
        {
            this->addCadre(400, 200, pos_x, pos_y);
            pos_x = 400;
        }
        else
        {
            this->addCadre(400, 200, pos_x, pos_y);
            pos_x = 0;
            pos_y += 200;
        }
    }
}

void    GraphicalUI::refresh(void)
{
    this->_window->clear(sf::Color::Black);
    sf::RectangleShape  shapetmp;
    std::vector<sf::RectangleShape>::const_iterator it = this->_rectangles.begin();
    std::vector<sf::RectangleShape>::const_iterator ite = this->_rectangles.end();
    std::vector<sf::Text>::const_iterator it2 = this->_titles.begin();
    std::vector<sf::Text>::const_iterator ite2 = this->_titles.end();
    for(it = this->_rectangles.begin(); it != ite; it++)
    {
        shapetmp = *it;
        if (shapetmp.getPosition().y == 0)
            shapetmp.setTexture(&this->_metal);
        else if (shapetmp.getPosition().y == 100)
            shapetmp.setTexture(&this->_space); 
        this->_window->draw(shapetmp);
    }
    ite = this->_cadres.end();
    for(it = this->_cadres.begin(); it != ite; it++)
    {
        shapetmp = *it;
        shapetmp.setTexture(&this->_cadre); 
        this->_window->draw(shapetmp);
    }
    for(it2 = this->_titles.begin(); it2 != ite2; it2++)
    {
        this->_window->draw(*it2);
    }
	this->_window->display();
}

GraphicalUI::~GraphicalUI(void)
{
    return;
}

