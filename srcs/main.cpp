/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:05:46 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 19:58:40 by jgourdin         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	ShellUI shell;
	if (argc != 2)
		std::cout << "Please enter Shell or Graphics" << std::endl;
	else if (argv[1] == "Shell")
    	shell.init_display();
	else if (argv[1] == "Graphics")
	{
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
	else
		std::cout << "Please enter Shell or Graphics" << std::endl;
	return ;
}
