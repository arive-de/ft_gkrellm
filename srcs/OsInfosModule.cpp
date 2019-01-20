/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfosModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:54 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 16:30:49 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsInfosModule.hpp"

OsInfosModule::OsInfosModule(void) {

    this->_osInfos = getStdOut("sw_vers");
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


std::string           OsInfosModule::getInfos(void)
{
    return this->_osInfos;
}

std::string           OsInfosModule::getStdOut(std::string cmd)
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