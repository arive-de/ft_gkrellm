/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:40:25 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/19 14:31:54 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplayClass.hpp"
#include "IMonitorModuleClass.hpp"


int     main( void ) {

    IMonitorDisplay display;

    display.init_display();

    int keycode;

    while (1)
    {
        if (display.duration())
        {
            display.refreshTime();
            wrefresh(stdscr);
        }
        if ((keycode = getch()) == ERR)
            continue;
        else if (keycode == 'p')
        {
            std::cout << "previous" << std::endl;
        }
        else if (keycode == 'n')
        {
            std::cout << "next" << std::endl;           
        }
    }
    endwin();
    return 0;
}