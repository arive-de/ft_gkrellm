/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DatetimeModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:58 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 16:31:20 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIME_MODULE_HPP
# define DATETIME_MODULE_HPP

# include "IMonitorModuleClass.hpp"

class DatetimeModule : public IMonitorModule {

public:

        DatetimeModule(void);
        DatetimeModule(DatetimeModule const & src);
        ~DatetimeModule(void);

        DatetimeModule & operator=(DatetimeModule const & rhs);

        std::string    getInfos(void);


private:

        std::string     _datetime;
};

#endif