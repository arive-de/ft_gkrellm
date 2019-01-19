/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:40:25 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/19 15:43:45 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorDisplayClass.hpp"
#include "MonitorModuleClass.hpp"
#include "IMonitorDisplayClass.hpp"
#include "IMonitorModuleClass.hpp"

#include <stdio.h>

int     main( void ) {

    MonitorDisplay display;
    MonitorModule  module;

    display.init_display();

    int keycode;
    
    // char* pPath;
    // pPath = getenv ("PATH");
    // if (pPath!=NULL)
    //   printf ("The current path is: %s",pPath);

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