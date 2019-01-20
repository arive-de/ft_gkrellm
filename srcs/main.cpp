/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:05:46 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 19:41:55 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Window.hpp>


#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "HostnameModule.hpp"
#include "GraphicalUIClass.hpp"
#include "ShellUIClass.hpp"

int main()
{
	ShellUI shell;

    //shell.init_display();

	sf::RenderWindow window(sf::VideoMode(800, 700), "Text intro", sf::Style::Default);
	window.setFramerateLimit(60);
	GraphicalUI		ui(window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		ui.render();
		ui.refresh();
	}
}
