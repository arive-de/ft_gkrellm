/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModuleClass.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:31 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:28:10 by arive-de         ###   ########.fr       */
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


IMonitorModule &	IMonitorModule::operator=(IMonitorModule const & rhs)
{
    if (this != &rhs)
    {
        (void) rhs;
    }
    return *this;
}
