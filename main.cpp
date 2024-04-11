#include <QCoreApplication>

#include "OatppTestGlobal.h"

#include "AppComponent.h"

#include "controller/MyTestController.h"

#include "oatpp-swagger/Controller.hpp"
#include "oatpp/network/Server.hpp"

#include <iostream>

void run() {

    //创建服务的相关组件环境
    AppComponent components;

    //获取Http路由对象进行端点设置
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    oatpp::web::server::api::Endpoints docEndpoints;
    docEndpoints.append(router->addController(MyTestController::createShared())->getEndpoints());

    router->addController(oatpp::swagger::Controller::createShared(docEndpoints));
    //router->addController(StaticController::createShared());

    /* Get connection handler component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

    /* Create TCP connection provider */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

    //创建web服务
    oatpp::network::Server server(connectionProvider,
                                  connectionHandler);

    OATPP_LOGD("Server",
               "Running on port %s..., open swagger doc @ http://%s:%s/swagger/ui#/",
               connectionProvider->getProperty("port").toString()->c_str(),
               OatppTest::ip.data(),
               connectionProvider->getProperty("port").toString()->c_str())

    server.run();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    oatpp::base::Environment::init();

    OatppTest::ip="localhost";
    OatppTest::port=8000;

    OatppTest::cors_url = "http://"+OatppTest::ip+":"+std::to_string(OatppTest::port);

    run();

    /* Print how many objects were created during app running, and what have left-probably leaked */
    /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
    std::cout << "\nEnvironment:\n";
    std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
    std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";

    oatpp::base::Environment::destroy();

    return a.exec();
}
