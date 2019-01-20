/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplayClass.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:49 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 15:39:52 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAYCLASS_HPP
# define IMONITORDISPLAYCLASS_HPP

#include <ncurses.h>
#include <iostream>
#include <sys/types.h>
#include <stdio.h>

class IMonitorDisplay {

public: 

    IMonitorDisplay(void); 
    IMonitorDisplay(IMonitorDisplay const & src); 
    ~IMonitorDisplay(void); 

	IMonitorDisplay &		operator=(IMonitorDisplay const & rhs);

    virtual void    init_display(void) = 0;

protected:

    WINDOW *_win;

};

#endif
