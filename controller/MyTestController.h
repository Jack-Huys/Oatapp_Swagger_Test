#pragma once

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "OatppTestGlobal.h"
#include "dto/DtoTest.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class MyTestController : public oatpp::web::server::api::ApiController
{
public:
    /**
   * Constructor with object mapper.
   * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
   */
    MyTestController(const std::shared_ptr<ObjectMapper>& objectMapper)
        : oatpp::web::server::api::ApiController(objectMapper)
    {}
public:

    static std::shared_ptr<MyTestController> createShared(
        OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
        )
    {
        return std::make_shared<MyTestController>(objectMapper);
    }

    /**
     *
     * GET /api/v1/test/hello
     *
     */
    ADD_CORS(hello, OatppTest::cors_url, "GET, POST, OPTIONS")
    ENDPOINT_INFO(hello)
    {
        info->tags.push_back("Test Projects");
        info->summary = "Test Projects --- say hello";
        //info->addResponse<Object<ConfluxGenerals>>(Status::CODE_200, "application/json");
        //info->addResponse<String>(Status::CODE_500, "text/plain");
    }

    ENDPOINT("GET",
             "/api/v1/test/hello",
             hello)
    {
        auto dto = MyDto::createShared();
        dto->statusCode = 200;
        dto->message = "Hello World!";
        return createDtoResponse(Status::CODE_200, dto);
    }

};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
