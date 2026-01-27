/**
 * @name m_Application.h
 * @author jj
 * @brief The main application, for Mariner.
 */

#include <print>

#include "App/m_Application.hpp"

void m_Application::m_Application_Start() {

    std::printf("%s\n", "haiiii");
    m_AppContextService* AppContextService = new m_AppContextService();
    

};

void m_Application::m_Application_Stop() {


};