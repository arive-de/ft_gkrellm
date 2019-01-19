/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplayClass.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:49 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:27:16 by arive-de         ###   ########.fr       */
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

protected:

};

#endif
