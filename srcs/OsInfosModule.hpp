/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfosModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:52 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 19:21:30 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_INFOS_MODULE_HPP
# define OS_INFOS_MODULE_HPP

# include "IMonitorModuleClass.hpp"
# define BUFFER_LEN 1000

class OsInfosModule : public IMonitorModule {

public:

        OsInfosModule(void);
        OsInfosModule(OsInfosModule const & src);
        virtual ~OsInfosModule(void);

        OsInfosModule & operator=(OsInfosModule const & rhs);

        std::string    getInfos(void);
        std::string    getStdOut(std::string);

private:

        std::string     _osInfos;
        std::string     buffer[BUFFER_LEN];
        char            _buffer[BUFFER_LEN];
        size_t          _bufferlen;
};

#endif