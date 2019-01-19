/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModuleClass.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:31 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:03:17 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorModuleClass.hpp"
#include <iostream>

MonitorModule::MonitorModule(void)
{
    return;
}

    MonitorModule::MonitorModule(MonitorModule const & src) 
{
    *this = src;
    return;
}

MonitorModule::~MonitorModule(void)
{
    return;
}

int                 MonitorModule::getFlag(void) const
{
    return this->_flag;
}

bool                 MonitorModule::getStart(void) const
{
    return this->_start;
}



MonitorModule &	MonitorModule::operator=(MonitorModule const & rhs)
{
    if (this != &rhs)
    {
        this->_start = rhs.getStart();
        this->_flag = rhs.getFlag();
    }
    return *this;
}
