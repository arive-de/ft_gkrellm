/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfosModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:52 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 15:08:22 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_INFOS_MODULE_HPP
# define OS_INFOS_MODULE_HPP

# include "IMonitorModuleClass.hpp"

class OsInfosModule : public IMonitorModule {

public:

        OsInfosModule(void);
        OsInfosModule(OsInfosModule const & src);
        ~OsInfosModule(void);

        OsInfosModule & operator=(OsInfosModule const & rhs);

        std::string    getOsInfos(void);

private:

        std::string     _osInfos;
};

#endif