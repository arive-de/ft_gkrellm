/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalUIClass.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:55:45 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:09:57 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicalUIClass.hpp"
#include <iostream>

GraphicalUI::GraphicalUI(void)
{
    return;
}

    GraphicalUI::GraphicalUI(GraphicalUI const & src) 
{
    *this = src;
    return;
}

GraphicalUI::~GraphicalUI(void)
{
    return;
}

GraphicalUI &	GraphicalUI::operator=(GraphicalUI const & rhs)
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
