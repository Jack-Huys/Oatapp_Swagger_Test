#ifndef SWAGGERCOMPONENT_H
#define SWAGGERCOMPONENT_H


#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/core/macro/component.hpp"

#include "OatppTestGlobal.h"

/**
 *  Swagger ui is served at
 *  http://host:localhost:8080/swagger/ui
 */
class SwaggerComponent {
public:

  /**
   *  General API docs info
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {

    oatpp::swagger::DocumentInfo::Builder builder;

    builder
    .setTitle("User entity service")
    .setDescription("CRUD API Example project with swagger docs")
    .setVersion("1.0")
    .setContactName("Ivan Ovsyanochka")
    .setContactUrl("https://oatpp.io/")

    .setLicenseName("Apache License, Version 2.0")
    .setLicenseUrl("http://www.apache.org/licenses/LICENSE-2.0")

    .addServer(OatppTest::cors_url, "server on "+OatppTest::cors_url);

    return builder.build();

  }());


  /**
   *  Swagger-Ui Resources (<oatpp-examples>/lib/oatpp-swagger/res)
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
    // Make sure to specify correct full path to oatpp-swagger/res folder !!!
    // path e.g.: "<YOUR-PATH-TO-REPO>/lib/oatpp-swagger/res"
    //特别需要注意的是这里的res目录内容一定要和oatpp-swagger的版本对应上，否则网页会打不开
    //auto swagger_path = QString("%1/3rd/swagger-oatpp-1.3.0/res").arg(aos::AosKernelCommon::get_installer_dir());
    return oatpp::swagger::Resources::loadResources("D:/Code/OtappTest/swagger-oatpp-1.3.0/res");
  }());

};
#endif // SWAGGERCOMPONENT_H
