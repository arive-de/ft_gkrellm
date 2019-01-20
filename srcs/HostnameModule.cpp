/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:57 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 15:28:45 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameModule.hpp"

HostnameModule::HostnameModule(void) {

    this->_hostname = IMonitorModule::getStdOut("sysctl -n kern.hostname");
}

HostnameModule::HostnameModule(HostnameModule const & src) {

    *this = src;
}

HostnameModule::~HostnameModule(void) {


}

HostnameModule & HostnameModule::operator=(HostnameModule const & rhs) {

    this->_hostname = rhs._hostname;
    return *this;
}

std::string                HostnameModule::getHostName(void)
{
    return this->_hostname;
}