static string JS_server_server = 
  "/*jslint indent: 2,\n"
  "         nomen: true,\n"
  "         maxlen: 100,\n"
  "         sloppy: true,\n"
  "         vars: true,\n"
  "         white: true,\n"
  "         plusplus: true */\n"
  "/*global require, db, edges, ModuleCache, Module,\n"
  "  ArangoCollection, ArangoEdgesCollection, ArangoDatabase,\n"
  "  ArangoEdges, ArangoError, ShapedJson,\n"
  "  SYS_DEFINE_ACTION */\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief JavaScript server functions\n"
  "///\n"
  "/// @file\n"
  "///\n"
  "/// DISCLAIMER\n"
  "///\n"
  "/// Copyright 2011-2012 triagens GmbH, Cologne, Germany\n"
  "///\n"
  "/// Licensed under the Apache License, Version 2.0 (the \"License\");\n"
  "/// you may not use this file except in compliance with the License.\n"
  "/// You may obtain a copy of the License at\n"
  "///\n"
  "///     http://www.apache.org/licenses/LICENSE-2.0\n"
  "///\n"
  "/// Unless required by applicable law or agreed to in writing, software\n"
  "/// distributed under the License is distributed on an \"AS IS\" BASIS,\n"
  "/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
  "/// See the License for the specific language governing permissions and\n"
  "/// limitations under the License.\n"
  "///\n"
  "/// Copyright holder is triAGENS GmbH, Cologne, Germany\n"
  "///\n"
  "/// @author Dr. Frank Celler\n"
  "/// @author Copyright 2011-2012, triAGENS GmbH, Cologne, Germany\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                                 Module \"internal\"\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8ModuleInternal\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief internal module\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "(function () {\n"
  "  var internal = require(\"internal\");\n"
  "  var console = require(\"console\");\n"
  "\n"
  "  internal.db = db;\n"
  "  internal.edges = edges;\n"
  "  internal.ArangoCollection = ArangoCollection;\n"
  "  internal.ArangoEdgesCollection = ArangoEdgesCollection;\n"
  "\n"
  "  if (typeof SYS_DEFINE_ACTION === \"undefined\") {\n"
  "    ModuleCache[\"/internal\"].exports.defineAction = function() {\n"
  "      console.error(\"SYS_DEFINE_ACTION not available\");\n"
  "    };\n"
  "  }\n"
  "  else {\n"
  "    ModuleCache[\"/internal\"].exports.defineAction = SYS_DEFINE_ACTION;\n"
  "  }\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "}());\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                             Module \"simple-query\"\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8ModuleSimpleQuery\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "(function () {\n"
  "  var console = require(\"console\");\n"
  "\n"
  "  try {\n"
  "    require(\"simple-query\");\n"
  "  }\n"
  "  catch (err) {\n"
  "    console.error(\"while loading 'simple-query' module: %s\", err);\n"
  "  }\n"
  "}());\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                                        ShapedJson\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8Shell\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "(function () {\n"
  "  var internal = require(\"internal\");\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief prints a shaped json\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ShapedJson.prototype._PRINT = function(seen, path, names, level) {\n"
  "    if (this instanceof ShapedJson) {\n"
  "      internal.printObject(this, seen, path, names, level);\n"
  "    }\n"
  "    else {\n"
  "      internal.output(this.toString());\n"
  "    }\n"
  "  };\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "}());\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                                      ArangoError\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8Shell\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "(function () {\n"
  "  var internal = require(\"internal\");\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief prints an error\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoError.prototype._PRINT = function() {\n"
  "    var errorNum = this.errorNum;\n"
  "    var errorMessage = this.errorMessage;\n"
  "\n"
  "    internal.output(\"[ArangoError \", errorNum, \": \", errorMessage, \"]\");\n"
  "  };\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief converts error to string\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoError.prototype.toString = function() {\n"
  "    var errorNum = this.errorNum;\n"
  "    var errorMessage = this.errorMessage;\n"
  "\n"
  "    return \"[ArangoError \" + errorNum + \": \" + errorMessage + \"]\";\n"
  "  };\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "}());\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                                   ArangoDatabase\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8Shell\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "(function () {\n"
  "  var internal = require(\"internal\");\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief drops a collection\n"
  "///\n"
  "/// @FUN{db._drop(@FA{collection})}\n"
  "///\n"
  "/// Drops a @FA{collection} and all its indexes.\n"
  "///\n"
  "/// @FUN{db._drop(@FA{collection-identifier})}\n"
  "///\n"
  "/// Drops a collection identified by @FA{collection-identifier} and all its\n"
  "/// indexes. No error is thrown if there is no such collection.\n"
  "///\n"
  "/// @FUN{db._drop(@FA{collection-name})}\n"
  "///\n"
  "/// Drops a collection named @FA{collection-name} and all its indexes. No error\n"
  "/// is thrown if there is no such collection.\n"
  "///\n"
  "/// @EXAMPLES\n"
  "///\n"
  "/// Drops a collection:\n"
  "///\n"
  "/// @verbinclude shell_collection-drop-db\n"
  "///\n"
  "/// Drops a collection identified by name:\n"
  "///\n"
  "/// @verbinclude shell_collection-drop-name-db\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoDatabase.prototype._drop = function(name) {\n"
  "    var collection = name;\n"
  "\n"
  "    if (! (name instanceof ArangoCollection\n"
  "        || name instanceof ArangoEdgesCollection)) {\n"
  "      collection = internal.db._collection(name);\n"
  "    }\n"
  "\n"
  "    if (collection === null) {\n"
  "      return;\n"
  "    }\n"
  "\n"
  "    return collection.drop();\n"
  "  };\n"
  "\n"
  "  ArangoEdges.prototype._drop = ArangoDatabase.prototype._drop;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief truncates a collection\n"
  "///\n"
  "/// @FUN{db._truncate(@FA{collection})}\n"
  "///\n"
  "/// Truncates a @FA{collection}, removing all documents but keeping all its\n"
  "/// indexes.\n"
  "///\n"
  "/// @FUN{db._truncate(@FA{collection-identifier})}\n"
  "///\n"
  "/// Truncates a collection identified by @FA{collection-identified}. No error is\n"
  "/// thrown if there is no such collection.\n"
  "///\n"
  "/// @FUN{db._truncate(@FA{collection-name})}\n"
  "///\n"
  "/// Truncates a collection named @FA{collection-name}. No error is thrown if\n"
  "/// there is no such collection.\n"
  "///\n"
  "/// @EXAMPLES\n"
  "///\n"
  "/// Truncates a collection:\n"
  "///\n"
  "/// @verbinclude shell_collection-truncate-db\n"
  "///\n"
  "/// Truncates a collection identified by name:\n"
  "///\n"
  "/// @verbinclude shell_collection-truncate-name-db\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoDatabase.prototype._truncate = function(name) {\n"
  "    var collection = name;\n"
  "\n"
  "    if (! (name instanceof ArangoCollection\n"
  "        || name instanceof ArangoEdgesCollection)) {\n"
  "      collection = internal.db._collection(name);\n"
  "    }\n"
  "\n"
  "    if (collection === null) {\n"
  "      return;\n"
  "    }\n"
  "\n"
  "    var all = collection.ALL(null, null).documents;\n"
  "    var i;\n"
  "\n"
  "    for (i = 0;  i < all.length;  ++i) {\n"
  "      collection.remove(all[i]._id);\n"
  "    }\n"
  "  };\n"
  "\n"
  "  ArangoEdges.prototype._truncate = ArangoDatabase.prototype._truncate;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief finds an index\n"
  "///\n"
  "/// @FUN{db._index(@FA{index-handle})}\n"
  "///\n"
  "/// Returns the index with @FA{index-handle} or null if no such index exists.\n"
  "///\n"
  "/// @EXAMPLES\n"
  "///\n"
  "/// @verbinclude shell_index-read-db\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoDatabase.prototype._index = function(id) {\n"
  "    if (id.hasOwnProperty(\"id\")) {\n"
  "      id = id.id;\n"
  "    }\n"
  "\n"
  "    var re = /^([0-9]+)\\/([0-9]+)/;\n"
  "    var pa = re.exec(id);\n"
  "    var err;\n"
  "\n"
  "    if (pa === null) {\n"
  "      err = new ArangoError();\n"
  "      err.errorNum = internal.errors.ERROR_ARANGO_INDEX_HANDLE_BAD.code;\n"
  "      err.errorMessage = internal.errors.ERROR_ARANGO_INDEX_HANDLE_BAD.message;\n"
  "      throw err;\n"
  "    }\n"
  "\n"
  "    var col = this._collection(parseInt(pa[1]));\n"
  "\n"
  "    if (col === null) {\n"
  "      err = new ArangoError();\n"
  "      err.errorNum = internal.errors.ERROR_ARANGO_COLLECTION_NOT_FOUND.code;\n"
  "      err.errorMessage = internal.errors.ERROR_ARANGO_COLLECTION_NOT_FOUND.message;\n"
  "      throw err;\n"
  "    }\n"
  "\n"
  "    var indexes = col.getIndexes();\n"
  "    var i;\n"
  "\n"
  "    for (i = 0;  i < indexes.length;  ++i) {\n"
  "      var index = indexes[i];\n"
  "\n"
  "      if (index.id === id) {\n"
  "        return index;\n"
  "      }\n"
  "    }\n"
  "\n"
  "    return null;\n"
  "  };\n"
  "\n"
  "  ArangoEdges.prototype._index = ArangoDatabase.prototype._index;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief drops an index\n"
  "///\n"
  "/// @FUN{db._dropIndex(@FA{index})}\n"
  "///\n"
  "/// Drops the @FA{index}.  If the index does not exists, then @LIT{false} is\n"
  "/// returned. If the index existed and was dropped, then @LIT{true} is\n"
  "/// returned. Note that you cannot drop the primary index.\n"
  "///\n"
  "/// @FUN{db._dropIndex(@FA{index-handle})}\n"
  "///\n"
  "/// Drops the index with @FA{index-handle}.\n"
  "///\n"
  "/// @EXAMPLES\n"
  "///\n"
  "/// @verbinclude shell_index-drop-index-db\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoDatabase.prototype._dropIndex = function(id) {\n"
  "    if (id.hasOwnProperty(\"id\")) {\n"
  "      id = id.id;\n"
  "    }\n"
  "\n"
  "    var re = /^([0-9]+)\\/([0-9]+)/;\n"
  "    var pa = re.exec(id);\n"
  "    var err;\n"
  "\n"
  "    if (pa === null) {\n"
  "      err = new ArangoError();\n"
  "      err.errorNum = internal.errors.ERROR_ARANGO_INDEX_HANDLE_BAD.code;\n"
  "      err.errorMessage = internal.errors.ERROR_ARANGO_INDEX_HANDLE_BAD.message;\n"
  "      throw err;\n"
  "    }\n"
  "\n"
  "    var col = this._collection(parseInt(pa[1]));\n"
  "\n"
  "    if (col === null) {\n"
  "      err = new ArangoError();\n"
  "      err.errorNum = internal.errors.ERROR_ARANGO_COLLECTION_NOT_FOUND.code;\n"
  "      err.errorMessage = internal.errors.ERROR_ARANGO_COLLECTION_NOT_FOUND.message;\n"
  "      throw err;\n"
  "    }\n"
  "\n"
  "    return col.dropIndex(id);\n"
  "  };\n"
  "\n"
  "  ArangoEdges.prototype._dropIndex = ArangoDatabase.prototype._dropIndex;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief prints a database\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "    ArangoDatabase.prototype._PRINT = function(seen, path, names, level) {\n"
  "      internal.output(\"[ArangoDatabase \\\"\" + this._path + \"\\\"]\");\n"
  "    };\n"
  "\n"
  "    ArangoEdges.prototype._PRINT =  function(seen, path, names, level) {\n"
  "      internal.output(\"[ArangoEdges \\\"\" + this._path + \"\\\"]\");\n"
  "    };\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief strng representation of a database\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "    ArangoDatabase.prototype.toString = function(seen, path, names, level) {\n"
  "      return \"[ArangoDatabase \\\"\" + this._path + \"\\\"]\";\n"
  "    };\n"
  "\n"
  "    ArangoEdges.prototype.toString = function(seen, path, names, level) {\n"
  "      return \"[ArangoEdges \\\"\" + this._path + \"\\\"]\";\n"
  "    };\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "}());\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                                 ArangoCollection\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8Shell\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "(function () {\n"
  "  var internal = require(\"internal\");\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief collection is corrupted\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.STATUS_CORRUPTED = 0;\n"
  "  ArangoEdgesCollection.STATUS_CORRUPTED = 0;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief collection is new born\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.STATUS_NEW_BORN = 1;\n"
  "  ArangoEdgesCollection.STATUS_NEW_BORN = 1;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief collection is unloaded\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.STATUS_UNLOADED = 2;\n"
  "  ArangoEdgesCollection.STATUS_UNLOADED = 2;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief collection is loaded\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.STATUS_LOADED = 3;\n"
  "  ArangoEdgesCollection.STATUS_LOADED = 3;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief collection is unloading\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.STATUS_UNLOADING = 4;\n"
  "  ArangoEdgesCollection.STATUS_UNLOADING = 4;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief collection is deleted\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.STATUS_DELETED = 5;\n"
  "  ArangoEdgesCollection.STATUS_DELETED = 5;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief converts collection into an array\n"
  "///\n"
  "/// @FUN{@FA{collection}.toArray()}\n"
  "///\n"
  "/// Converts the collection into an array of documents. Never use this call\n"
  "/// in a production environment.\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.prototype.toArray = function() {\n"
  "    return this.ALL(null, null).documents;\n"
  "  };\n"
  "\n"
  "  ArangoEdgesCollection.prototype.toArray = ArangoCollection.prototype.toArray;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief truncates a collection\n"
  "///\n"
  "/// @FUN{@FA{collection}.truncate()}\n"
  "///\n"
  "/// Truncates a @FA{collection}, removing all documents but keeping all its\n"
  "/// indexes.\n"
  "///\n"
  "/// @EXAMPLES\n"
  "///\n"
  "/// Truncates a collection:\n"
  "///\n"
  "/// @verbinclude shell_collection-truncate\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.prototype.truncate = function() {\n"
  "    return internal.db._truncate(this);\n"
  "  };\n"
  "\n"
  "  ArangoEdgesCollection.prototype.truncate = ArangoCollection.prototype.truncate;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief finds an index of a collection\n"
  "///\n"
  "/// @FUN{@FA{collection}.index(@FA{index-handle})}\n"
  "///\n"
  "/// Returns the index with @FA{index-handle} or null if no such index exists.\n"
  "///\n"
  "/// @EXAMPLES\n"
  "///\n"
  "/// @verbinclude shell_index-read\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.prototype.index = function(id) {\n"
  "    var indexes = this.getIndexes();\n"
  "    var i;\n"
  "\n"
  "    if (typeof id === \"string\") {\n"
  "      var re = /^([0-9]+)\\/([0-9]+)/;\n"
  "      var pa = re.exec(id);\n"
  "\n"
  "      if (pa === null) {\n"
  "        id = this._id + \"/\" + id;\n"
  "      }\n"
  "    }\n"
  "    else if (id.hasOwnProperty(\"id\")) {\n"
  "      id = id.id;\n"
  "    }\n"
  "\n"
  "    for (i = 0;  i < indexes.length;  ++i) {\n"
  "      var index = indexes[i];\n"
  "\n"
  "      if (index.id === id) {\n"
  "        return index;\n"
  "      }\n"
  "    }\n"
  "\n"
  "    return null;\n"
  "  };\n"
  "\n"
  "  ArangoEdgesCollection.prototype.index = ArangoCollection.prototype.index;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief prints a collection\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.prototype._PRINT = function() {\n"
  "    var status = \"unknown\";\n"
  "\n"
  "    switch (this.status()) {\n"
  "      case ArangoCollection.STATUS_NEW_BORN: status = \"new born\"; break;\n"
  "      case ArangoCollection.STATUS_UNLOADED: status = \"unloaded\"; break;\n"
  "      case ArangoCollection.STATUS_UNLOADING: status = \"unloading\"; break;\n"
  "      case ArangoCollection.STATUS_LOADED: status = \"loaded\"; break;\n"
  "      case ArangoCollection.STATUS_CORRUPTED: status = \"corrupted\"; break;\n"
  "      case ArangoCollection.STATUS_DELETED: status = \"deleted\"; break;\n"
  "    }\n"
  "\n"
  "    internal.output(\"[ArangoCollection \",\n"
  "                    this._id, \n"
  "                    \", \\\"\", this.name(), \"\\\" (status \", status, \")]\");\n"
  "  };\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief strng representation of a collection\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.prototype.toString = function(seen, path, names, level) {\n"
  "    return \"[ArangoCollection \" + this._id + \"]\";\n"
  "  };\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "}());\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                            ArangoEdgesCollection\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8Shell\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "(function () {\n"
  "  var internal = require(\"internal\");\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief prints a collection\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoEdgesCollection.prototype._PRINT = function() {\n"
  "    var status = \"unknown\";\n"
  "\n"
  "    switch (this.status()) {\n"
  "      case ArangoCollection.STATUS_NEW_BORN: status = \"new born\"; break;\n"
  "      case ArangoCollection.STATUS_UNLOADED: status = \"unloaded\"; break;\n"
  "      case ArangoCollection.STATUS_UNLOADING: status = \"unloading\"; break;\n"
  "      case ArangoCollection.STATUS_LOADED: status = \"loaded\"; break;\n"
  "      case ArangoCollection.STATUS_CORRUPTED: status = \"corrupted\"; break;\n"
  "      case ArangoCollection.STATUS_DELETED: status = \"deleted\"; break;\n"
  "    }\n"
  "\n"
  "    internal.output(\"[ArangoEdgesCollection \",\n"
  "                    this._id,\n"
  "                    \", \\\"\", this.name(), \"\\\" (status \", status, \")]\");\n"
  "  };\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief string representation of a collection\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "  ArangoCollection.prototype.toString = function(seen, path, names, level) {\n"
  "    return \"[ArangoEdgesCollection \" + this._id + \"]\";\n"
  "  };\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "}());\n"
  "\n"
  "// Local Variables:\n"
  "// mode: outline-minor\n"
  "// outline-regexp: \"^\\\\(/// @brief\\\\|/// @addtogroup\\\\|// --SECTION--\\\\|/// @page\\\\|/// @}\\\\)\"\n"
  "// End:\n"
;
