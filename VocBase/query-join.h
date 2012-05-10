////////////////////////////////////////////////////////////////////////////////
/// @brief joins
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2010-2012 triagens GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Jan Steemann
/// @author Copyright 2012, triagens GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_DURHAM_VOC_BASE_JOIN_H
#define TRIAGENS_DURHAM_VOC_BASE_JOIN_H 1

#include <BasicsC/common.h>
#include <BasicsC/vector.h>
#include <BasicsC/strings.h>

#include "VocBase/query-where.h"
#include "VocBase/query-context.h"
#include "VocBase/query-data-feeder.h"
#include "VocBase/query-result-types.h"

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup VocBase
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Maximum number of joins in one query
////////////////////////////////////////////////////////////////////////////////

#define QUERY_MAX_JOINS (16)

////////////////////////////////////////////////////////////////////////////////
/// @brief possible join types
////////////////////////////////////////////////////////////////////////////////

typedef enum {
  JOIN_TYPE_PRIMARY,
  JOIN_TYPE_INNER,
  JOIN_TYPE_OUTER,
  JOIN_TYPE_LIST
}
TRI_join_type_e;

////////////////////////////////////////////////////////////////////////////////
/// @brief join data structure
////////////////////////////////////////////////////////////////////////////////

typedef struct TRI_join_part_s {
  TRI_data_feeder_t *_feeder; // data source
  TRI_join_type_e _type;
  QL_ast_query_where_t* _where;
  TRI_vector_pointer_t* _ranges;
  TRI_vocbase_col_t* _collection;
  char* _collectionName;
  char* _alias;
  struct {
    bool _select;
    bool _where;
    bool _order;
    bool _join;
  } _mustMaterialize;
  QL_ast_query_geo_restriction_t* _geoRestriction;
  TRI_doc_mptr_t* _singleDocument;
  TRI_vector_pointer_t _listDocuments;
  struct {
    size_t _size;
    char* _alias;
    void* _singleValue;
    TRI_vector_pointer_t _listValues;
  } _extraData;
  TRI_js_exec_context_t _context;

  void (*free) (struct TRI_join_part_s*);
} 
TRI_join_part_t;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif

// Local Variables:
// mode: outline-minor
// outline-regexp: "^\\(/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|// --SECTION--\\|/// @\\}\\)"
// End:

