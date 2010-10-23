/* PandaTorrent.c generated by valac 0.10.0, the Vala compiler
 * generated from PandaTorrent.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <libsoup/soup.h>
#include <gmodule.h>
#include <json-glib/json-glib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <gobject/gvaluecollector.h>


#define TYPE_PANDA_PLUGIN (panda_plugin_get_type ())
#define PANDA_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PANDA_PLUGIN, PandaPlugin))
#define IS_PANDA_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PANDA_PLUGIN))
#define PANDA_PLUGIN_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_PANDA_PLUGIN, PandaPluginIface))

typedef struct _PandaPlugin PandaPlugin;
typedef struct _PandaPluginIface PandaPluginIface;

#define TYPE_PANDA_TORRENT (panda_torrent_get_type ())
#define PANDA_TORRENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PANDA_TORRENT, PandaTorrent))
#define PANDA_TORRENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PANDA_TORRENT, PandaTorrentClass))
#define IS_PANDA_TORRENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PANDA_TORRENT))
#define IS_PANDA_TORRENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PANDA_TORRENT))
#define PANDA_TORRENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PANDA_TORRENT, PandaTorrentClass))

typedef struct _PandaTorrent PandaTorrent;
typedef struct _PandaTorrentClass PandaTorrentClass;
typedef struct _PandaTorrentPrivate PandaTorrentPrivate;

#define TYPE_TRANSMISSION (transmission_get_type ())
#define TRANSMISSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRANSMISSION, Transmission))
#define TRANSMISSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRANSMISSION, TransmissionClass))
#define IS_TRANSMISSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRANSMISSION))
#define IS_TRANSMISSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRANSMISSION))
#define TRANSMISSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRANSMISSION, TransmissionClass))

typedef struct _Transmission Transmission;
typedef struct _TransmissionClass TransmissionClass;
#define _transmission_unref0(var) ((var == NULL) ? NULL : (var = (transmission_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _TransmissionPrivate TransmissionPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _soup_buffer_free0(var) ((var == NULL) ? NULL : (var = (soup_buffer_free (var), NULL)))
#define _json_array_unref0(var) ((var == NULL) ? NULL : (var = (json_array_unref (var), NULL)))
#define _json_object_unref0(var) ((var == NULL) ? NULL : (var = (json_object_unref (var), NULL)))
#define _json_node_free0(var) ((var == NULL) ? NULL : (var = (json_node_free (var), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _ParamSpecTransmission ParamSpecTransmission;

struct _PandaPluginIface {
	GTypeInterface parent_iface;
	char* (*get_handler_path) (PandaPlugin* self);
	void (*request_handler) (PandaPlugin* self, SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client);
};

struct _PandaTorrent {
	GObject parent_instance;
	PandaTorrentPrivate * priv;
	Transmission* transmission;
};

struct _PandaTorrentClass {
	GObjectClass parent_class;
};

struct _Transmission {
	GTypeInstance parent_instance;
	volatile int ref_count;
	TransmissionPrivate * priv;
};

struct _TransmissionClass {
	GTypeClass parent_class;
	void (*finalize) (Transmission *self);
};

struct _TransmissionPrivate {
	SoupSessionAsync* session;
	char* user;
	char* password;
	char* path;
	char* sessionid;
};

struct _ParamSpecTransmission {
	GParamSpec parent_instance;
};


static gpointer panda_torrent_parent_class = NULL;
static PandaPluginIface* panda_torrent_panda_plugin_parent_iface = NULL;
static char** transmission_std_fields;
static gint transmission_std_fields_length1;
static char** transmission_std_fields = NULL;
static gint transmission_std_fields_length1 = 0;
static gint _transmission_std_fields_size_ = 0;
static gpointer transmission_parent_class = NULL;

GType panda_plugin_get_type (void) G_GNUC_CONST;
GType panda_torrent_get_type (void) G_GNUC_CONST;
gpointer transmission_ref (gpointer instance);
void transmission_unref (gpointer instance);
GParamSpec* param_spec_transmission (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_transmission (GValue* value, gpointer v_object);
void value_take_transmission (GValue* value, gpointer v_object);
gpointer value_get_transmission (const GValue* value);
GType transmission_get_type (void) G_GNUC_CONST;
enum  {
	PANDA_TORRENT_DUMMY_PROPERTY
};
static char* panda_torrent_real_get_handler_path (PandaPlugin* base);
static void panda_torrent_real_request_handler (PandaPlugin* base, SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client);
Transmission* transmission_new (const char* host, gint port, const char* user, const char* password);
Transmission* transmission_construct (GType object_type, const char* host, gint port, const char* user, const char* password);
char* transmission_request_list (Transmission* self);
PandaTorrent* panda_torrent_new (void);
PandaTorrent* panda_torrent_construct (GType object_type);
static void panda_torrent_finalize (GObject* obj);
GType register_plugin (GModule* module);
#define TRANSMISSION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_TRANSMISSION, TransmissionPrivate))
enum  {
	TRANSMISSION_DUMMY_PROPERTY
};
static void transmission_auth (Transmission* self, SoupMessage* msg, SoupAuth* auth, gboolean retry);
static void _transmission_auth_soup_session_authenticate (SoupSession* _sender, SoupMessage* msg, SoupAuth* auth, gboolean retrying, gpointer self);
static void transmission_finalize (Transmission* obj);



static char* panda_torrent_real_get_handler_path (PandaPlugin* base) {
	PandaTorrent * self;
	char* result = NULL;
	self = (PandaTorrent*) base;
	result = g_strdup ("/torrent.json");
	return result;
}


static void panda_torrent_real_request_handler (PandaPlugin* base, SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client) {
	PandaTorrent * self;
	char* response;
	self = (PandaTorrent*) base;
	g_return_if_fail (server != NULL);
	g_return_if_fail (msg != NULL);
	g_return_if_fail (path != NULL);
	if (self->transmission == NULL) {
		Transmission* _tmp0_;
		self->transmission = (_tmp0_ = transmission_new ("192.168.0.2", 9091, NULL, NULL), _transmission_unref0 (self->transmission), _tmp0_);
	}
	response = transmission_request_list (self->transmission);
	soup_message_set_response (msg, "text/html", SOUP_MEMORY_COPY, response, strlen (response));
	soup_message_set_status (msg, (guint) SOUP_STATUS_OK);
	_g_free0 (response);
}


PandaTorrent* panda_torrent_construct (GType object_type) {
	PandaTorrent * self;
	self = (PandaTorrent*) g_object_new (object_type, NULL);
	return self;
}


PandaTorrent* panda_torrent_new (void) {
	return panda_torrent_construct (TYPE_PANDA_TORRENT);
}


static void panda_torrent_class_init (PandaTorrentClass * klass) {
	panda_torrent_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = panda_torrent_finalize;
}


static void panda_torrent_panda_plugin_interface_init (PandaPluginIface * iface) {
	panda_torrent_panda_plugin_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_handler_path = panda_torrent_real_get_handler_path;
	iface->request_handler = panda_torrent_real_request_handler;
}


static void panda_torrent_instance_init (PandaTorrent * self) {
}


static void panda_torrent_finalize (GObject* obj) {
	PandaTorrent * self;
	self = PANDA_TORRENT (obj);
	_transmission_unref0 (self->transmission);
	G_OBJECT_CLASS (panda_torrent_parent_class)->finalize (obj);
}


GType panda_torrent_get_type (void) {
	static volatile gsize panda_torrent_type_id__volatile = 0;
	if (g_once_init_enter (&panda_torrent_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PandaTorrentClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) panda_torrent_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PandaTorrent), 0, (GInstanceInitFunc) panda_torrent_instance_init, NULL };
		static const GInterfaceInfo panda_plugin_info = { (GInterfaceInitFunc) panda_torrent_panda_plugin_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType panda_torrent_type_id;
		panda_torrent_type_id = g_type_register_static (G_TYPE_OBJECT, "PandaTorrent", &g_define_type_info, 0);
		g_type_add_interface_static (panda_torrent_type_id, TYPE_PANDA_PLUGIN, &panda_plugin_info);
		g_once_init_leave (&panda_torrent_type_id__volatile, panda_torrent_type_id);
	}
	return panda_torrent_type_id__volatile;
}


GType register_plugin (GModule* module) {
	GType result = 0UL;
	g_return_val_if_fail (module != NULL, 0UL);
	result = TYPE_PANDA_TORRENT;
	return result;
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void _transmission_auth_soup_session_authenticate (SoupSession* _sender, SoupMessage* msg, SoupAuth* auth, gboolean retrying, gpointer self) {
	transmission_auth (self, msg, auth, retrying);
}


Transmission* transmission_construct (GType object_type, const char* host, gint port, const char* user, const char* password) {
	Transmission* self;
	gboolean _tmp0_ = FALSE;
	char* _tmp3_;
	char* _tmp4_;
	SoupSessionAsync* _tmp5_;
	SoupMessage* msg;
	char* _tmp6_;
	g_return_val_if_fail (host != NULL, NULL);
	self = (Transmission*) g_type_create_instance (object_type);
	if (user != NULL) {
		_tmp0_ = password != NULL;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		char* _tmp1_;
		char* _tmp2_;
		self->priv->user = (_tmp1_ = g_strdup (user), _g_free0 (self->priv->user), _tmp1_);
		self->priv->password = (_tmp2_ = g_strdup (password), _g_free0 (self->priv->password), _tmp2_);
	}
	self->priv->path = (_tmp4_ = g_strconcat ("http://", string_to_string (host), ":", _tmp3_ = g_strdup_printf ("%i", port), "/transmission/rpc", NULL), _g_free0 (self->priv->path), _tmp4_);
	_g_free0 (_tmp3_);
	self->priv->session = (_tmp5_ = (SoupSessionAsync*) soup_session_async_new (), _g_object_unref0 (self->priv->session), _tmp5_);
	g_signal_connect ((SoupSession*) self->priv->session, "authenticate", (GCallback) _transmission_auth_soup_session_authenticate, self);
	msg = soup_message_new ("GET", self->priv->path);
	soup_session_send_message ((SoupSession*) self->priv->session, msg);
	self->priv->sessionid = (_tmp6_ = g_strdup (soup_message_headers_get (msg->response_headers, "X-Transmission-Session-Id")), _g_free0 (self->priv->sessionid), _tmp6_);
	if (self->priv->sessionid == NULL) {
		g_error ("PandaTorrent.vala:47: Transmission version to old or not configured on" \
" that port");
	}
	_g_object_unref0 (msg);
	return self;
}


Transmission* transmission_new (const char* host, gint port, const char* user, const char* password) {
	return transmission_construct (TYPE_TRANSMISSION, host, port, user, password);
}


static gpointer _json_object_ref0 (gpointer self) {
	return self ? json_object_ref (self) : NULL;
}


static gpointer _json_array_ref0 (gpointer self) {
	return self ? json_array_ref (self) : NULL;
}


char* transmission_request_list (Transmission* self) {
	char* result = NULL;
	gsize length = 0UL;
	char* json;
	SoupMessage* msg;
	JsonGenerator* gen;
	JsonNode* root;
	JsonObject* object;
	JsonObject* args;
	JsonArray* fields;
	char* _tmp0_;
	SoupBuffer* _tmp1_;
	char* _tmp2_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	json = NULL;
	msg = soup_message_new ("POST", self->priv->path);
	gen = json_generator_new ();
	root = json_node_new (JSON_NODE_OBJECT);
	object = json_object_new ();
	json_node_set_object (root, object);
	json_generator_set_root (gen, root);
	args = json_object_new ();
	json_object_set_object_member (object, "arguments", _json_object_ref0 (args));
	json_object_set_string_member (object, "method", "torrent-get");
	fields = json_array_new ();
	{
		char** s_collection;
		int s_collection_length1;
		int s_it;
		s_collection = transmission_std_fields;
		s_collection_length1 = transmission_std_fields_length1;
		for (s_it = 0; s_it < transmission_std_fields_length1; s_it = s_it + 1) {
			char* s;
			s = g_strdup (s_collection[s_it]);
			{
				json_array_add_string_element (fields, s);
				_g_free0 (s);
			}
		}
	}
	json_object_set_array_member (args, "fields", _json_array_ref0 (fields));
	json = (_tmp0_ = json_generator_to_data (gen, &length), _g_free0 (json), _tmp0_);
	soup_message_body_append (msg->request_body, SOUP_MEMORY_COPY, json, length);
	soup_message_headers_append (msg->request_headers, "X-Transmission-Session-Id", self->priv->sessionid);
	soup_session_send_message ((SoupSession*) self->priv->session, msg);
	result = (_tmp2_ = g_strdup ((_tmp1_ = soup_message_body_flatten (msg->response_body))->data), _soup_buffer_free0 (_tmp1_), _tmp2_);
	_json_array_unref0 (fields);
	_json_object_unref0 (args);
	_json_object_unref0 (object);
	_json_node_free0 (root);
	_g_object_unref0 (gen);
	_g_object_unref0 (msg);
	_g_free0 (json);
	return result;
	_json_array_unref0 (fields);
	_json_object_unref0 (args);
	_json_object_unref0 (object);
	_json_node_free0 (root);
	_g_object_unref0 (gen);
	_g_object_unref0 (msg);
	_g_free0 (json);
}


static void transmission_auth (Transmission* self, SoupMessage* msg, SoupAuth* auth, gboolean retry) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (msg != NULL);
	g_return_if_fail (auth != NULL);
	if (self->priv->user != NULL) {
		_tmp0_ = self->priv->password != NULL;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		soup_auth_authenticate (auth, self->priv->user, self->priv->password);
	} else {
		if (retry) {
			g_error ("PandaTorrent.vala:103: Wrong username/password");
		} else {
			g_error ("PandaTorrent.vala:105: Transmission server requires authentication");
		}
	}
}


static void value_transmission_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_transmission_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		transmission_unref (value->data[0].v_pointer);
	}
}


static void value_transmission_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = transmission_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_transmission_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_transmission_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		Transmission* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = transmission_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_transmission_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	Transmission** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = transmission_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_transmission (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecTransmission* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_TRANSMISSION), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_transmission (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_TRANSMISSION), NULL);
	return value->data[0].v_pointer;
}


void value_set_transmission (GValue* value, gpointer v_object) {
	Transmission* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_TRANSMISSION));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_TRANSMISSION));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		transmission_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		transmission_unref (old);
	}
}


void value_take_transmission (GValue* value, gpointer v_object) {
	Transmission* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_TRANSMISSION));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_TRANSMISSION));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		transmission_unref (old);
	}
}


static void transmission_class_init (TransmissionClass * klass) {
	char** _tmp0_ = NULL;
	transmission_parent_class = g_type_class_peek_parent (klass);
	TRANSMISSION_CLASS (klass)->finalize = transmission_finalize;
	g_type_class_add_private (klass, sizeof (TransmissionPrivate));
	transmission_std_fields = (_tmp0_ = g_new0 (char*, 6 + 1), _tmp0_[0] = g_strdup ("id"), _tmp0_[1] = g_strdup ("name"), _tmp0_[2] = g_strdup ("percentDone"), _tmp0_[3] = g_strdup ("rateDownload"), _tmp0_[4] = g_strdup ("rateUpload"), _tmp0_[5] = g_strdup ("sizeWhenDone"), _tmp0_);
	transmission_std_fields_length1 = 6;
}


static void transmission_instance_init (Transmission * self) {
	self->priv = TRANSMISSION_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void transmission_finalize (Transmission* obj) {
	Transmission * self;
	self = TRANSMISSION (obj);
	_g_object_unref0 (self->priv->session);
	_g_free0 (self->priv->user);
	_g_free0 (self->priv->password);
	_g_free0 (self->priv->path);
	_g_free0 (self->priv->sessionid);
}


GType transmission_get_type (void) {
	static volatile gsize transmission_type_id__volatile = 0;
	if (g_once_init_enter (&transmission_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_transmission_init, value_transmission_free_value, value_transmission_copy_value, value_transmission_peek_pointer, "p", value_transmission_collect_value, "p", value_transmission_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (TransmissionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) transmission_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Transmission), 0, (GInstanceInitFunc) transmission_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType transmission_type_id;
		transmission_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Transmission", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&transmission_type_id__volatile, transmission_type_id);
	}
	return transmission_type_id__volatile;
}


gpointer transmission_ref (gpointer instance) {
	Transmission* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void transmission_unref (gpointer instance) {
	Transmission* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		TRANSMISSION_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




