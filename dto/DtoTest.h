#ifndef DTOTEST_H
#define DTOTEST_H
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class MyDto : public oatpp::DTO
{

  DTO_INIT(MyDto, DTO)

  DTO_FIELD(Int32, statusCode);
  DTO_FIELD(String, message);

};


#include OATPP_CODEGEN_END(DTO)

#endif
