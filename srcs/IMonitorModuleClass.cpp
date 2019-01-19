/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModuleClass.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:31 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 12:10:56 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModuleClass.hpp"
#include <iostream>

IMonitorModule::IMonitorModule(void)
{
    return;
}

    IMonitorModule::IMonitorModule(IMonitorModule const & src) 
{
    *this = src;
    return;
}

IMonitorModule::~IMonitorModule(void)
{
    return;
}

int                 IMonitorModule::getFlag(void) const
{
    return this->_flag;
}

bool                 IMonitorModule::getStart(void) const
{
    return this->_start;
}


IMonitorModule &	IMonitorModule::operator=(IMonitorModule const & rhs)
{
    if (this != &rhs)
    {
        this->_start = rhs.getStart();
        this->_flag = rhs.getFlag();
    }
    return *this;
}
