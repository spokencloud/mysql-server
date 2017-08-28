/* Copyright (c) 2014, 2017, Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

#ifndef DD_TABLES__SCHEMATA_INCLUDED
#define DD_TABLES__SCHEMATA_INCLUDED

#include <string>

#include "sql/dd/impl/types/entity_object_table_impl.h"
#include "sql/dd/object_id.h"
#include "sql/dd/string_type.h"
#include "sql/dd/types/schema.h"

namespace dd {

class Item_name_key;
class Object_key;
class Raw_record;

namespace tables {

///////////////////////////////////////////////////////////////////////////

class Schemata : public Entity_object_table_impl
{
public:
  static const Schemata &instance();

  enum enum_fields
  {
    FIELD_ID,
    FIELD_CATALOG_ID,
    FIELD_NAME,
    FIELD_DEFAULT_COLLATION_ID,
    FIELD_CREATED,
    FIELD_LAST_ALTERED,
    FIELD_OPTIONS
  };

  enum enum_indexes
  {
    INDEX_PK_ID= static_cast<uint>(Common_index::PK_ID),
    INDEX_UK_CATALOG_ID_NAME= static_cast<uint>(Common_index::UK_NAME),
    INDEX_K_DEFAULT_COLLATION_ID
  };

  enum enum_foreign_keys
  {
    FK_CATALOG_ID,
    FK_DEFAULT_COLLATION_ID
  };

  Schemata();

  virtual Schema *create_entity_object(const Raw_record &) const;

  static bool update_object_key(Item_name_key *key,
                                Object_id catalog_id,
                                const String_type &schema_name);

  static Object_key *create_key_by_catalog_id(Object_id catalog_id);
};

///////////////////////////////////////////////////////////////////////////

}
}

#endif // DD_TABLES__SCHEMATA_INCLUDED
