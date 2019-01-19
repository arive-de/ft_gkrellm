/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplayClass.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:58 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 21:14:48 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplayClass.hpp"

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

IMonitorDisplay &	IMonitorDisplay::operator=(IMonitorDisplay const & rhs)
{
    if (&rhs != this)
    {
        (void) rhs;
    }
    return *this;
}
