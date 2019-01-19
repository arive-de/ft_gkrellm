/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplayClass.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:58 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 12:14:32 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplayClass.hpp"
#include <iostream>

IMonitorDisplay::IMonitorDisplay(void)
{
    return;
}

    IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const & src) 
{
    *this = src;
    return;
}

IMonitorDisplay::~IMonitorDisplay(void)
{
    return;
}

bool                IMonitorDisplay::getDisplayMode(void) const
{
    return this->_displayMode;
}

IMonitorDisplay &	IMonitorDisplay::operator=(IMonitorDisplay const & rhs)
{
    if (&rhs != this)
        this->_displayMode = rhs.getDisplayMode();
    return *this;
}
