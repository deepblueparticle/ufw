/*
   Copyright 2017 Vladimir Lysyy (mrbald@github)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "application.hpp"
#include "exception_types.hpp"
#include "logger.hpp"
#include "library_repository.hpp"
#include "plugin_repository.hpp"

#include <boost/exception/diagnostic_information.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>


int main(int argc, char const** argv)
{
    ufw::initialize_logger();

    try
    {
        LOG_INF << "starting";
        ufw::application app;
        app.add<ufw::library_repository>("LIBRARY");
        app.add<ufw::plugin_repository>("PLUGIN");

        app.load(argc, argv);

        app.run();
    }
    catch (...)
    {
        LOG_ERR << boost::current_exception_diagnostic_information();
        return 1;
    }
}
