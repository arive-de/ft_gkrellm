/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellUIClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:56:47 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 17:21:57 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShellUIClass.hpp"
#include <iostream>

ShellUI::ShellUI(void)
{
    return;
}

ShellUI::ShellUI(ShellUI const & src) 
{
    *this = src;
    return;
}

ShellUI::~ShellUI(void)
{
    return;
}

ShellUI &	ShellUI::operator=(ShellUI const & rhs)
{
    if (this != &rhs)
    {
        this->_displayMode = rhs.getDisplayMode();
        this->_start = rhs._start;
        this->_ctt = rhs._ctt;
        this->_win = rhs._win;
        this->_cttStr = rhs._cttStr;
    }
    return *this;
}
