/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:57 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 16:28:45 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameModule.hpp"

HostnameModule::HostnameModule(void) {

    this->_hostname = getStdOut("sysctl -n kern.hostname");
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

std::string                HostnameModule::getInfos(void)
{
    return this->_hostname;
}

std::string           HostnameModule::getStdOut(std::string cmd)
{
    std::string data;
    FILE * stream;

    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream)
    {
        while (!feof(stream))
            if (fgets(this->_buffer, this->_bufferlen, stream) != NULL) data.append(this->_buffer);
              pclose(stream);
    }
    memset(this->_buffer, 0, sizeof(this->_buffer));
    data = data.substr(0, data.size() - 1);
    return data;
}