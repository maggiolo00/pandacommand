/* PandaServer.c generated by valac 0.10.0, the Vala compiler
 * generated from PandaServer.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <libsoup/soup.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <stdio.h>
#include <json-glib/json-glib.h>


#define TYPE_PANDA_SERVER (panda_server_get_type ())
#define PANDA_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PANDA_SERVER, PandaServer))
#define PANDA_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PANDA_SERVER, PandaServerClass))
#define IS_PANDA_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PANDA_SERVER))
#define IS_PANDA_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PANDA_SERVER))
#define PANDA_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PANDA_SERVER, PandaServerClass))

typedef struct _PandaServer PandaServer;
typedef struct _PandaServerClass PandaServerClass;
typedef struct _PandaServerPrivate PandaServerPrivate;

#define TYPE_PANDA_PLUGIN (panda_plugin_get_type ())
#define PANDA_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PANDA_PLUGIN, PandaPlugin))
#define IS_PANDA_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PANDA_PLUGIN))
#define PANDA_PLUGIN_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_PANDA_PLUGIN, PandaPluginIface))

typedef struct _PandaPlugin PandaPlugin;
typedef struct _PandaPluginIface PandaPluginIface;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define __g_list_free_g_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_list_free_g_object_unref (var), NULL)))
typedef struct _PandaServerLoadModulesData PandaServerLoadModulesData;

#define TYPE_PANDA_PLUGIN_LOADER (panda_plugin_loader_get_type ())
#define PANDA_PLUGIN_LOADER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PANDA_PLUGIN_LOADER, PandaPluginLoader))
#define PANDA_PLUGIN_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PANDA_PLUGIN_LOADER, PandaPluginLoaderClass))
#define IS_PANDA_PLUGIN_LOADER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PANDA_PLUGIN_LOADER))
#define IS_PANDA_PLUGIN_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PANDA_PLUGIN_LOADER))
#define PANDA_PLUGIN_LOADER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PANDA_PLUGIN_LOADER, PandaPluginLoaderClass))

typedef struct _PandaPluginLoader PandaPluginLoader;
typedef struct _PandaPluginLoaderClass PandaPluginLoaderClass;
#define _json_object_unref0(var) ((var == NULL) ? NULL : (var = (json_object_unref (var), NULL)))
typedef struct _PandaServerLoadOneData PandaServerLoadOneData;

struct _PandaServer {
	GObject parent_instance;
	PandaServerPrivate * priv;
};

struct _PandaServerClass {
	GObjectClass parent_class;
};

struct _PandaPluginIface {
	GTypeInterface parent_iface;
	char* (*get_handler_path) (PandaPlugin* self);
	void (*request_handler) (PandaPlugin* self, SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client);
};

struct _PandaServerPrivate {
	SoupServer* server;
	GeeHashMap* plugins;
};

struct _PandaServerLoadModulesData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PandaServer* self;
	char* path;
	GFile* dir;
	char* attribute;
	GFileEnumerator* e;
	GList* files;
	GFileType type;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	char* _tmp3_;
	GList* info_collection;
	GList* info_it;
	GFileInfo* info;
	GError * err;
	GError * _inner_error_;
};

struct _PandaServerLoadOneData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PandaServer* self;
	char* path;
	JsonParser* parser;
	JsonObject* root_object;
	char* module_name;
	char* module_entry;
	PandaPluginLoader* loader;
	PandaPlugin* plugin;
	char* _tmp0_;
	char* _tmp1_;
	GError * err;
	GError * _inner_error_;
};


static gpointer panda_server_parent_class = NULL;

GType panda_server_get_type (void) G_GNUC_CONST;
GType panda_plugin_get_type (void) G_GNUC_CONST;
#define PANDA_SERVER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PANDA_SERVER, PandaServerPrivate))
enum  {
	PANDA_SERVER_DUMMY_PROPERTY
};
PandaServer* panda_server_new (gint port);
PandaServer* panda_server_construct (GType object_type, gint port);
void panda_server_default_handler (PandaServer* self, SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client);
static void _panda_server_default_handler_soup_server_callback (SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client, gpointer self);
void panda_server_load_modules (PandaServer* self, const char* path, GAsyncReadyCallback _callback_, gpointer _user_data_);
void panda_server_load_modules_finish (PandaServer* self, GAsyncResult* _res_);
void panda_server_run (PandaServer* self);
void panda_server_plugins_handler (PandaServer* self, SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client);
void panda_plugin_request_handler (PandaPlugin* self, SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client);
static void panda_server_load_modules_data_free (gpointer _data);
static void panda_server_load_modules_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean panda_server_load_modules_co (PandaServerLoadModulesData* data);
static void _g_list_free_g_object_unref (GList* self);
void panda_server_load_one (PandaServer* self, const char* path, GAsyncReadyCallback _callback_, gpointer _user_data_);
void panda_server_load_one_finish (PandaServer* self, GAsyncResult* _res_);
static void panda_server_load_one_data_free (gpointer _data);
static void panda_server_load_one_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean panda_server_load_one_co (PandaServerLoadOneData* data);
PandaPluginLoader* panda_plugin_loader_new (GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, const char* name);
PandaPluginLoader* panda_plugin_loader_construct (GType object_type, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, const char* name);
GType panda_plugin_loader_get_type (void) G_GNUC_CONST;
gboolean panda_plugin_loader_load (PandaPluginLoader* self);
gpointer panda_plugin_loader_new_object (PandaPluginLoader* self);
char* panda_plugin_get_handler_path (PandaPlugin* self);
static void _panda_server_plugins_handler_soup_server_callback (SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client, gpointer self);
static void panda_server_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 25 "PandaServer.vala"
static void _panda_server_default_handler_soup_server_callback (SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client, gpointer self) {
#line 154 "PandaServer.c"
	panda_server_default_handler (self, server, msg, path, query, client);
}


#line 10 "PandaServer.vala"
PandaServer* panda_server_construct (GType object_type, gint port) {
#line 161 "PandaServer.c"
	PandaServer * self;
	SoupServer* _tmp0_;
	GeeHashMap* _tmp1_;
	char* _tmp2_;
#line 10 "PandaServer.vala"
	self = (PandaServer*) g_object_new (object_type, NULL);
#line 12 "PandaServer.vala"
	self->priv->server = (_tmp0_ = soup_server_new (SOUP_SERVER_PORT, port, NULL), _g_object_unref0 (self->priv->server), _tmp0_);
#line 13 "PandaServer.vala"
	soup_server_add_handler (self->priv->server, "/", _panda_server_default_handler_soup_server_callback, g_object_ref (self), g_object_unref);
#line 14 "PandaServer.vala"
	self->priv->plugins = (_tmp1_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, TYPE_PANDA_PLUGIN, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_str_hash, g_str_equal, NULL), _g_object_unref0 (self->priv->plugins), _tmp1_);
#line 15 "PandaServer.vala"
	panda_server_load_modules (self, _tmp2_ = g_strconcat (g_getenv ("PWD"), "/plugins/", NULL), NULL, NULL);
#line 176 "PandaServer.c"
	_g_free0 (_tmp2_);
	return self;
}


#line 10 "PandaServer.vala"
PandaServer* panda_server_new (gint port) {
#line 10 "PandaServer.vala"
	return panda_server_construct (TYPE_PANDA_SERVER, port);
#line 186 "PandaServer.c"
}


#line 20 "PandaServer.vala"
void panda_server_run (PandaServer* self) {
#line 20 "PandaServer.vala"
	g_return_if_fail (self != NULL);
#line 22 "PandaServer.vala"
	soup_server_run (self->priv->server);
#line 196 "PandaServer.c"
}


#line 25 "PandaServer.vala"
void panda_server_default_handler (PandaServer* self, SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client) {
#line 202 "PandaServer.c"
	char* response_text;
	GFile* file;
	GError * _inner_error_ = NULL;
#line 25 "PandaServer.vala"
	g_return_if_fail (self != NULL);
#line 25 "PandaServer.vala"
	g_return_if_fail (server != NULL);
#line 25 "PandaServer.vala"
	g_return_if_fail (msg != NULL);
#line 25 "PandaServer.vala"
	g_return_if_fail (path != NULL);
#line 25 "PandaServer.vala"
	g_return_if_fail (client != NULL);
#line 28 "PandaServer.vala"
	response_text = g_strdup ("");
#line 29 "PandaServer.vala"
	file = g_file_new_for_path ("index.html");
#line 30 "PandaServer.vala"
	if (!g_file_query_exists (file, NULL)) {
#line 222 "PandaServer.c"
		char* _tmp0_;
#line 31 "PandaServer.vala"
		fprintf (stderr, "File '%s' doesn't exist.\n", _tmp0_ = g_file_get_path (file));
#line 226 "PandaServer.c"
		_g_free0 (_tmp0_);
		_g_object_unref0 (file);
		_g_free0 (response_text);
#line 32 "PandaServer.vala"
		return;
#line 232 "PandaServer.c"
	}
	{
		GFileInputStream* _tmp1_;
		GFileInputStream* _tmp2_;
		GDataInputStream* _tmp3_;
		GDataInputStream* in_stream;
		char* line;
#line 38 "PandaServer.vala"
		_tmp1_ = g_file_read (file, NULL, &_inner_error_);
#line 242 "PandaServer.c"
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
#line 38 "PandaServer.vala"
		in_stream = (_tmp3_ = g_data_input_stream_new ((GInputStream*) (_tmp2_ = _tmp1_)), _g_object_unref0 (_tmp2_), _tmp3_);
#line 248 "PandaServer.c"
		line = NULL;
#line 41 "PandaServer.vala"
		while (TRUE) {
#line 252 "PandaServer.c"
			char* _tmp4_;
			char* _tmp5_;
			char* _tmp6_;
#line 41 "PandaServer.vala"
			_tmp4_ = g_data_input_stream_read_line (in_stream, NULL, NULL, &_inner_error_);
#line 258 "PandaServer.c"
			if (_inner_error_ != NULL) {
				_g_free0 (line);
				_g_object_unref0 (in_stream);
				goto __catch0_g_error;
			}
#line 41 "PandaServer.vala"
			if (!((line = (_tmp5_ = _tmp4_, _g_free0 (line), _tmp5_)) != NULL)) {
#line 41 "PandaServer.vala"
				break;
#line 268 "PandaServer.c"
			}
#line 42 "PandaServer.vala"
			response_text = (_tmp6_ = g_strconcat (response_text, line, NULL), _g_free0 (response_text), _tmp6_);
#line 272 "PandaServer.c"
		}
		_g_free0 (line);
		_g_object_unref0 (in_stream);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 46 "PandaServer.vala"
			g_error ("PandaServer.vala:46: %s", e->message);
#line 286 "PandaServer.c"
			_g_error_free0 (e);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (file);
		_g_free0 (response_text);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
#line 49 "PandaServer.vala"
	soup_message_set_response (msg, "text/html", SOUP_MEMORY_COPY, response_text, strlen (response_text));
#line 51 "PandaServer.vala"
	soup_message_set_status (msg, (guint) SOUP_STATUS_OK);
#line 302 "PandaServer.c"
	_g_object_unref0 (file);
	_g_free0 (response_text);
}


#line 53 "PandaServer.vala"
void panda_server_plugins_handler (PandaServer* self, SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client) {
#line 310 "PandaServer.c"
	PandaPlugin* plug;
#line 53 "PandaServer.vala"
	g_return_if_fail (self != NULL);
#line 53 "PandaServer.vala"
	g_return_if_fail (server != NULL);
#line 53 "PandaServer.vala"
	g_return_if_fail (msg != NULL);
#line 53 "PandaServer.vala"
	g_return_if_fail (path != NULL);
#line 53 "PandaServer.vala"
	g_return_if_fail (client != NULL);
#line 57 "PandaServer.vala"
	plug = (PandaPlugin*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->plugins, path);
#line 58 "PandaServer.vala"
	panda_plugin_request_handler (plug, server, msg, path, query, client);
#line 326 "PandaServer.c"
	_g_object_unref0 (plug);
}


static void panda_server_load_modules_data_free (gpointer _data) {
	PandaServerLoadModulesData* data;
	data = _data;
	_g_free0 (data->path);
	g_object_unref (data->self);
	g_slice_free (PandaServerLoadModulesData, data);
}


void panda_server_load_modules (PandaServer* self, const char* path, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PandaServerLoadModulesData* _data_;
	_data_ = g_slice_new0 (PandaServerLoadModulesData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, panda_server_load_modules);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, panda_server_load_modules_data_free);
	_data_->self = g_object_ref (self);
	_data_->path = g_strdup (path);
	panda_server_load_modules_co (_data_);
}


void panda_server_load_modules_finish (PandaServer* self, GAsyncResult* _res_) {
	PandaServerLoadModulesData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void panda_server_load_modules_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	PandaServerLoadModulesData* data;
	data = _user_data_;
	data->_res_ = _res_;
	panda_server_load_modules_co (data);
}


static void _g_list_free_g_object_unref (GList* self) {
	g_list_foreach (self, (GFunc) g_object_unref, NULL);
	g_list_free (self);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean panda_server_load_modules_co (PandaServerLoadModulesData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
		case 3:
		goto _state_3;
	}
	_state_0:
	data->dir = g_file_new_for_path (data->path);
	{
		data->attribute = g_strdup (G_FILE_ATTRIBUTE_STANDARD_NAME "," G_FILE_ATTRIBUTE_STANDARD_TYPE);
		data->_state_ = 1;
		g_file_enumerate_children_async (data->dir, data->attribute, 0, G_PRIORITY_DEFAULT, NULL, panda_server_load_modules_ready, data);
		return FALSE;
		_state_1:
		data->e = g_file_enumerate_children_finish (data->dir, data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			_g_free0 (data->attribute);
			goto __catch1_g_error;
		}
#line 68 "PandaServer.vala"
		while (TRUE) {
#line 404 "PandaServer.c"
			data->_state_ = 2;
			g_file_enumerator_next_files_async (data->e, 10, G_PRIORITY_DEFAULT, NULL, panda_server_load_modules_ready, data);
			return FALSE;
			_state_2:
			data->files = g_file_enumerator_next_files_finish (data->e, data->_res_, &data->_inner_error_);
			if (data->_inner_error_ != NULL) {
				_g_object_unref0 (data->e);
				_g_free0 (data->attribute);
				goto __catch1_g_error;
			}
#line 70 "PandaServer.vala"
			if (data->files == NULL) {
#line 417 "PandaServer.c"
				__g_list_free_g_object_unref0 (data->files);
#line 71 "PandaServer.vala"
				break;
#line 421 "PandaServer.c"
			}
			{
				data->info_collection = data->files;
				for (data->info_it = data->info_collection; data->info_it != NULL; data->info_it = data->info_it->next) {
					data->info = _g_object_ref0 ((GFileInfo*) data->info_it->data);
					{
						data->type = g_file_info_get_file_type (data->info);
#line 75 "PandaServer.vala"
						if (data->type == G_FILE_TYPE_DIRECTORY) {
#line 76 "PandaServer.vala"
							panda_server_load_modules (data->self, data->_tmp1_ = g_build_filename (data->_tmp0_ = g_file_get_path (data->dir), g_file_info_get_name (data->info), NULL), NULL, NULL);
#line 433 "PandaServer.c"
							_g_free0 (data->_tmp1_);
							_g_free0 (data->_tmp0_);
						} else {
#line 77 "PandaServer.vala"
							if (_vala_strcmp0 (g_file_info_get_name (data->info), "plugin.json") == 0) {
#line 439 "PandaServer.c"
								data->_state_ = 3;
								panda_server_load_one (data->self, data->_tmp3_ = g_build_filename (data->_tmp2_ = g_file_get_path (data->dir), g_file_info_get_name (data->info), NULL), panda_server_load_modules_ready, data);
								return FALSE;
								_state_3:
#line 78 "PandaServer.vala"
								panda_server_load_one_finish (data->self, data->_res_);
#line 446 "PandaServer.c"
								_g_free0 (data->_tmp3_);
								_g_free0 (data->_tmp2_);
							}
						}
						_g_object_unref0 (data->info);
					}
				}
			}
			__g_list_free_g_object_unref0 (data->files);
		}
		_g_object_unref0 (data->e);
		_g_free0 (data->attribute);
	}
	goto __finally1;
	__catch1_g_error:
	{
		data->err = data->_inner_error_;
		data->_inner_error_ = NULL;
		{
#line 85 "PandaServer.vala"
			g_warning ("PandaServer.vala:85: Error: %s\n", data->err->message);
#line 468 "PandaServer.c"
			_g_error_free0 (data->err);
		}
	}
	__finally1:
	if (data->_inner_error_ != NULL) {
		_g_object_unref0 (data->dir);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	_g_object_unref0 (data->dir);
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


static void panda_server_load_one_data_free (gpointer _data) {
	PandaServerLoadOneData* data;
	data = _data;
	_g_free0 (data->path);
	g_object_unref (data->self);
	g_slice_free (PandaServerLoadOneData, data);
}


void panda_server_load_one (PandaServer* self, const char* path, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PandaServerLoadOneData* _data_;
	_data_ = g_slice_new0 (PandaServerLoadOneData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, panda_server_load_one);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, panda_server_load_one_data_free);
	_data_->self = g_object_ref (self);
	_data_->path = g_strdup (path);
	panda_server_load_one_co (_data_);
}


void panda_server_load_one_finish (PandaServer* self, GAsyncResult* _res_) {
	PandaServerLoadOneData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void panda_server_load_one_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	PandaServerLoadOneData* data;
	data = _user_data_;
	data->_res_ = _res_;
	panda_server_load_one_co (data);
}


static gpointer _json_object_ref0 (gpointer self) {
	return self ? json_object_ref (self) : NULL;
}


#line 53 "PandaServer.vala"
static void _panda_server_plugins_handler_soup_server_callback (SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client, gpointer self) {
#line 533 "PandaServer.c"
	panda_server_plugins_handler (self, server, msg, path, query, client);
}


static gboolean panda_server_load_one_co (PandaServerLoadOneData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->parser = json_parser_new ();
#line 93 "PandaServer.vala"
		json_parser_load_from_file (data->parser, data->path, &data->_inner_error_);
#line 550 "PandaServer.c"
		if (data->_inner_error_ != NULL) {
			_g_object_unref0 (data->parser);
			goto __catch2_g_error;
		}
		data->root_object = _json_object_ref0 (json_node_get_object (json_parser_get_root (data->parser)));
		data->module_name = g_strdup (json_object_get_string_member (data->root_object, "name"));
		data->module_entry = g_strdup (json_object_get_string_member (data->root_object, "entry"));
		data->loader = panda_plugin_loader_new (TYPE_PANDA_PLUGIN, (GBoxedCopyFunc) g_object_ref, g_object_unref, data->module_entry);
#line 98 "PandaServer.vala"
		if (panda_plugin_loader_load (data->loader)) {
#line 561 "PandaServer.c"
			data->plugin = (PandaPlugin*) panda_plugin_loader_new_object (data->loader);
#line 100 "PandaServer.vala"
			soup_server_add_handler (data->self->priv->server, data->_tmp0_ = panda_plugin_get_handler_path (data->plugin), _panda_server_plugins_handler_soup_server_callback, g_object_ref (data->self), g_object_unref);
#line 565 "PandaServer.c"
			_g_free0 (data->_tmp0_);
#line 101 "PandaServer.vala"
			gee_abstract_map_set ((GeeAbstractMap*) data->self->priv->plugins, data->_tmp1_ = panda_plugin_get_handler_path (data->plugin), data->plugin);
#line 569 "PandaServer.c"
			_g_free0 (data->_tmp1_);
			_g_object_unref0 (data->plugin);
		}
		_g_object_unref0 (data->loader);
		_g_free0 (data->module_entry);
		_g_free0 (data->module_name);
		_json_object_unref0 (data->root_object);
		_g_object_unref0 (data->parser);
	}
	goto __finally2;
	__catch2_g_error:
	{
		data->err = data->_inner_error_;
		data->_inner_error_ = NULL;
		{
#line 105 "PandaServer.vala"
			g_warning ("PandaServer.vala:105: Error: %s\n", data->err->message);
#line 587 "PandaServer.c"
			_g_error_free0 (data->err);
		}
	}
	__finally2:
	if (data->_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


static void panda_server_class_init (PandaServerClass * klass) {
	panda_server_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PandaServerPrivate));
	G_OBJECT_CLASS (klass)->finalize = panda_server_finalize;
}


static void panda_server_instance_init (PandaServer * self) {
	self->priv = PANDA_SERVER_GET_PRIVATE (self);
}


static void panda_server_finalize (GObject* obj) {
	PandaServer * self;
	self = PANDA_SERVER (obj);
	_g_object_unref0 (self->priv->server);
	_g_object_unref0 (self->priv->plugins);
	G_OBJECT_CLASS (panda_server_parent_class)->finalize (obj);
}


GType panda_server_get_type (void) {
	static volatile gsize panda_server_type_id__volatile = 0;
	if (g_once_init_enter (&panda_server_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PandaServerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) panda_server_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PandaServer), 0, (GInstanceInitFunc) panda_server_instance_init, NULL };
		GType panda_server_type_id;
		panda_server_type_id = g_type_register_static (G_TYPE_OBJECT, "PandaServer", &g_define_type_info, 0);
		g_once_init_leave (&panda_server_type_id__volatile, panda_server_type_id);
	}
	return panda_server_type_id__volatile;
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}



