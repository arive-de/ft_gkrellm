/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfosModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:54 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 15:28:38 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsInfosModule.hpp"

OsInfosModule::OsInfosModule(void) {

    this->_osInfos = IMonitorModule::getStdOut("sw_vers");
}

OsInfosModule::OsInfosModule(OsInfosModule const & src) {

    *this = src;
}

OsInfosModule::~OsInfosModule(void) {


}


OsInfosModule & OsInfosModule::operator=(OsInfosModule const & rhs) {

    this->_osInfos = rhs._osInfos;
    return *this;
}


std::string                 OsInfosModule::getOsInfos(void)
{
    return this->_osInfos;
}