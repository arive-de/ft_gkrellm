/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalUIClass.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:55:34 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 17:49:47 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICALUICLASS_HPP
# define GRAPHICALUICLASS_HPP

# include <iostream>
# include "IMonitorDisplayClass.hpp"
# include "IMonitorModuleClass.hpp"
# include <vector>

#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class GraphicalUI : public IMonitorDisplay
{

public: 

    GraphicalUI(sf::RenderWindow &window); 
    virtual ~GraphicalUI(void); 

    void    refresh(void);
    void    render(void);


private:
        std::vector<IMonitorModule*>	_modules;
        sf::RenderWindow				*_window;
        std::vector<sf::RectangleShape> _rectangles;
        std::vector<sf::RectangleShape> _cadres;
        std::vector<sf::Text>           _titles;
        std::vector<sf::Texture>        _textures;
        sf::Font                        _font;
        sf::Texture                     _space;
        sf::Texture                     _metal;
        sf::Texture                     _cadre;
        
        void    addTitles(int size, std::string text, int x, int y);
        void    addRectangle(int size_x, int size_y, int pos_x, int pos_y);
        void    addFont(void);
        void    addCadre(int size_x, int size_y, int pos_x, int pos_y);

        GraphicalUI &		operator=(GraphicalUI const & rhs);
        GraphicalUI(void);
        GraphicalUI(GraphicalUI const & src); 
};

#endif
