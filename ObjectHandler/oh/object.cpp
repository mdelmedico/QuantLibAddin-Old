
/*
 Copyright (C) 2004, 2005 Eric Ehlers

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#if defined(HAVE_CONFIG_H)     // Dynamically created by configure
    #include <oh/config.hpp>
#endif
#include <oh/object.hpp>
#include <oh/exception.hpp>
#include <iomanip>

namespace ObjHandler {

    const Properties& Object::getProperties() const {
        return properties_;
    }

    std::ostream& operator<<(std::ostream& out, const any_ptr& any) {
        if (any->empty())
            return out << "null";
        else if (any->type() == typeid(int))
            return out << boost::any_cast<int>(*any);
        else if (any->type() == typeid(double))
            return out << boost::any_cast<double>(*any);
        else if (any->type() == typeid(std::string))
            return out << boost::any_cast<std::string>(*any);
        else if (any->type() == typeid(std::vector<long>)) {
            out << std::endl;
            std::vector<long> v= boost::any_cast< std::vector<long> >(*any);
            for (std::vector<long>::const_iterator i = v.begin();
            i != v.end(); i++) {
                out << *i << std::endl;
            }
            return out;       
        } else if (any->type() == typeid(std::vector<double>)) {
            out << std::endl;
            std::vector<double> v= boost::any_cast< std::vector<double> >(*any);
            for (std::vector<double>::const_iterator i = v.begin();
            i != v.end(); i++) {
                out << *i << std::endl;
            }
            return out;       
        } else
            throw Exception("any_ptr << operator: unrecognized type");
    }

  std::ostream& operator<<(std::ostream& out, const Object &object) {
        out << std::endl;
        Properties properties = object.getProperties();
        Properties::const_iterator it;
        for (it = properties.begin(); it != properties.end(); it++) {
            ObjectProperty property = *it;
            out << std::left << "property = " << std::setw(10) << property.name() <<
                " value = " << property() << std::endl;
        } 
        return out;
    }

}

