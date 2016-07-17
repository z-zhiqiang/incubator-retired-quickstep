/**
 *   Copyright 2016, Quickstep Research Group, Computer Sciences Department,
 *     University of Wisconsin—Madison.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

#include "query_optimizer/QueryHandle.hpp"

#include <set>

#include "catalog/CatalogDatabase.hpp"
#include "catalog/CatalogRelation.hpp"

namespace quickstep {

const std::size_t QueryHandle::getMemoryTempRelationsBytes() {
  std::size_t memory = 0;
  for (relation_id rid : temp_relation_ids_) {
    if (catalog_database_->hasRelationWithId(rid)) {
      memory += catalog_database_->getRelationById(rid)->getRelationSizeBytes();
    } else {
      removeTempRelationID(rid);
    }
  }
  return memory;
}

}  // namespace quickstep
