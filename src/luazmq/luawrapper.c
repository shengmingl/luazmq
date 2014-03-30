/*
    0MQ C接口的Lua封装

    2014/3/30 by 黎胜明
    *************************************************************************
*/
#include <zmq.h>
#include <lua.h>
#include <lauxlib.h>

static int lua_zmq_version(lua_State *L)
{
	int major;
	int minor;
	int patch;
	zmq_version(&major,&minor,&patch);
	lua_pushnumber(L,major);
	lua_pushnumber(L,minor);
	lua_pushnumber(L,patch);	
	return 3;
}

static int lua_zmq_errno(lua_State *L)
{
	lua_pushnumber(L,zmq_errno());	
	return 1;
}

static int lua_zmq_strerror(lua_State *L)
{
	int errnum = lua_tointeger(L,1);
	const char * s = zmq_strerror(errnum);
	lua_pushstring(L,s);
	return 1;
}

static int lua_zmq_ctx_new(lua_State *L)
{	
	lua_pushlightuserdata(L,zmq_ctx_new());
	return 1;
}

static int lua_zmq_ctx_term(lua_State *L)
{
	void *ctx = lua_topointer(L,1);
	lua_pushnumber(L,zmq_ctx_term(ctx) );	
	return 1;
}

static int lua_zmq_ctx_shutdown(lua_State *L)
{
	const void *ctx = lua_topointer(L,1);
	lua_pushnumber(L,zmq_ctx_shutdown(ctx) );	
	return 1;
}

static int lua_zmq_ctx_set(lua_State *L)
{
	const void *ctx = lua_topointer(L,1);
	int option = lua_tointeger(L,2);
	int optval = lua_tointeger(L,3);	
	lua_pushnumber(L,zmq_ctx_set(ctx,option,optval) );	
	return 1;
}

static int lua_zmq_ctx_get(lua_State *L)
{
	const void *ctx = lua_topointer(L,1);
	int option = lua_tointeger(L,2);	
	lua_pushnumber(L,zmq_ctx_get(ctx,option) );	
	return 1;
}

/******************************************************************************/
/*  0MQ message definition.                                                   */
/******************************************************************************/
static int lua_zmq_msg_new(lua_State *L)
{
	lua_pushlightuserdata(L,malloc(sizeof(zmq_msg_t)));
	return 1;
}

static int lua_zmq_msg_init(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);	
	lua_pushnumber(L,zmq_msg_init(msg));
	return 1;
}

static int lua_zmq_msg_init_size(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);	
	size_t size = lua_tointeger(L,2);
	lua_pushnumber(L,zmq_msg_init_size(msg,size));
	return 1;
}

static int lua_zmq_msg_send(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);
	void *s = lua_topointer(L,2);
	int flags = lua_tointeger(L,3);
	lua_pushnumber(L,zmq_msg_send(msg,s,flags));
	return 1;
}

static int lua_zmq_msg_recv(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);
	void *s = lua_topointer(L,2);
	int flags = lua_tointeger(L,3);
	lua_pushnumber(L,zmq_msg_recv(msg,s,flags));
	return 1;
}

static int lua_zmq_msg_close(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);	
	lua_pushnumber(L,zmq_msg_close(msg));
	return 1;
}

static int lua_zmq_msg_move(lua_State *L)
{
	struct zmq_msg_t *dest = (struct zmq_msg_t *)lua_topointer(L,1);	
	struct zmq_msg_t *src = (struct zmq_msg_t *)lua_topointer(L,1);	
	lua_pushnumber(L,zmq_msg_move(dest,src));
	return 1;
}

static int lua_zmq_msg_copy(lua_State *L)
{
	struct zmq_msg_t *dest = (struct zmq_msg_t *)lua_topointer(L,1);	
	struct zmq_msg_t *src = (struct zmq_msg_t *)lua_topointer(L,1);	
	lua_pushnumber(L,zmq_msg_copy(dest,src));
	return 1;
}

static int lua_zmq_msg_data(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);		
	lua_pushlightuserdata(L,zmq_msg_data(msg));
	return 1;
}

static int lua_zmq_msg_size(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);		
	lua_pushnumber(L,zmq_msg_size(msg));
	return 1;
}

static int lua_zmq_msg_more(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);		
	lua_pushnumber(L,zmq_msg_more(msg));
	return 1;
}

static int lua_zmq_msg_get(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);		
	int option = lua_tointeger(L,2);
	lua_pushnumber(L,zmq_msg_get(msg,option));
	return 1;
}

static int lua_zmq_msg_set(lua_State *L)
{
	struct zmq_msg_t *msg = (struct zmq_msg_t *)lua_topointer(L,1);		
	int option = lua_tointeger(L,2);
	int optval = lua_tointeger(L,3);	
	lua_pushnumber(L,zmq_msg_set(msg,option,optval));
	return 1;
}

/******************************************************************************/
/*  0MQ socket events and monitoring                                          */
/******************************************************************************/
static int lua_zmq_socket(lua_State *L)
{
	const void *ctx = lua_topointer(L,1);
	int type = lua_tointeger(L,2);
	lua_pushlightuserdata(L,zmq_socket(ctx,type));
	return 1;
}

static int lua_zmq_close(lua_State *L)
{
	const void *s = lua_topointer(L,1);	
	lua_pushinteger(L,zmq_close(s));
	return 1;
}

//int zmq_setsockopt (void *s, int option, const void *optval,size_t optvallen);
static int lua_zmq_setsockopt(lua_State *L)
{
	const void *s = lua_topointer(L,1);
	int option = lua_tointeger(L,2);
	const char * optval = lua_tostring(L,3);
	size_t optvallen = lua_tointeger(L,4);
	lua_pushinteger(L,zmq_setsockopt(s,option,optval,optvallen));
	return 1;
}

//int zmq_getsockopt (void *s, int option, void *optval,size_t *optvallen);
//--> int,string zmq_getsockopt(s, option)
static int lua_zmq_getsockopt(lua_State *L)
{
	const void *s = lua_topointer(L,1);
	int option = lua_tointeger(L,2);
	char optval[1024];
	size_t optvallen = 0;
	int r = zmq_getsockopt(s,option,optval,&optvallen);
	lua_pushinteger(L,r);
	lua_pushlstring(L,optval,optvallen);
	return 2;
}


static int lua_zmq_bind(lua_State *L)
{
	const void *s = lua_topointer(L,1);
	const char * addr = lua_tostring(L,2);
	lua_pushinteger(L,zmq_bind(s,addr));
	return 1;
}

static int lua_zmq_connect(lua_State *L)
{
	const void *s = lua_topointer(L,1);
	const char * addr = lua_tostring(L,2);
	lua_pushinteger(L,zmq_connect(s,addr));
	return 1;
}

static int lua_zmq_disconnect(lua_State *L)
{
	const void *s = lua_topointer(L,1);
	const char * addr = lua_tostring(L,2);
	lua_pushinteger(L,zmq_disconnect(s,addr));
	return 1;
}


static int lua_zmq_send(lua_State *L)
{
	const void *s = lua_topointer(L,1);		
	const char *buf = lua_tostring(L,2);   //lua传过来的可能是二进制数据，即string中可能包含\0字符。
	size_t len = lua_tointeger(L,3);       //因为字符串中可能包含\0字符，因此len必不可少。 其实也可以考虑使用lua_tolstring  
	int flags = lua_tointeger(L,4);		
	lua_pushinteger(L,zmq_send(s,buf,len,flags));
	return 1;
}

static int lua_zmq_send_const(lua_State *L)
{
	const void *s = lua_topointer(L,1);		
	const char *buf = lua_tostring(L,2); 
	size_t len = lua_tointeger(L,3);     
	int flags = lua_tointeger(L,4);	
	lua_pushinteger(L,zmq_send_const(s,buf,len,flags));
	return 1;
}

//int zmq_recv (void *s, void *buf, size_t len, int flags);
//--> int,string = zmq_recv(s, size_t len, int flags)
static int lua_zmq_recv(lua_State *L)
{
	int r = 0;
	const void *s = lua_topointer(L,1);	
	size_t len = lua_tointeger(L,2);
	int flags = lua_tointeger(L,3);	
	char * buf = (char *)malloc(len + 1);		
	r = zmq_recv(s, buf,len, flags);
	lua_pushinteger(L,r);
	lua_pushlstring(L,buf, len);
	free(buf);
	return 2;
}


static int lua_zmq_socket_monitor(lua_State *L)
{
	const void *s = lua_topointer(L,1);
	const char * addr = lua_tostring(L,2);
	int events = lua_tointeger(L,3);
	lua_pushinteger(L,zmq_socket_monitor(s,addr,events));
	return 1;
}

static int lua_zmq_sendmsg(lua_State *L)
{
	const void *s = lua_topointer(L,1);
	zmq_msg_t *msg = (zmq_msg_t *)lua_topointer(L,2);
	int flags = lua_tointeger(L,3);;
	lua_pushinteger(L,zmq_sendmsg(s,msg,flags));
	return 1;
}

static int lua_zmq_recvmsg(lua_State *L)
{
	const void *s = lua_topointer(L,1);
	zmq_msg_t *msg = (zmq_msg_t *)lua_topointer(L,2);
	int flags = lua_tointeger(L,3);;
	lua_pushinteger(L,zmq_recvmsg(s,msg,flags));
	return 1;
}



static const struct luaL_Reg luazmq[] = 
{
	{"zmq_version"       , lua_zmq_version       },
	{"zmq_errno"         , lua_zmq_errno         },
	{"zmq_strerror"      , lua_zmq_strerror      },
	{"zmq_ctx_new"       , lua_zmq_ctx_new       },
	{"zmq_ctx_term"      , lua_zmq_ctx_term      },
	{"zmq_ctx_shutdown"  , lua_zmq_ctx_shutdown  },
	{"zmq_ctx_set"       , lua_zmq_ctx_set       },
	{"zmq_ctx_get"       , lua_zmq_ctx_get       },
	{"zmq_msg_new"       , lua_zmq_msg_new       },
	{"zmq_msg_init"      , lua_zmq_msg_init      },
	{"zmq_msg_init_size" , lua_zmq_msg_init_size },
	{"zmq_msg_send"      , lua_zmq_msg_send      },
	{"zmq_msg_recv"      , lua_zmq_msg_recv      },
	{"zmq_msg_close"     , lua_zmq_msg_close     },
	{"zmq_msg_move"      , lua_zmq_msg_move      },
	{"zmq_msg_copy"      , lua_zmq_msg_copy      },
	{"zmq_msg_data"      , lua_zmq_msg_data      },
	{"zmq_msg_size"      , lua_zmq_msg_size      },
	{"zmq_msg_more"      , lua_zmq_msg_more      },
	{"zmq_msg_get"       , lua_zmq_msg_get       },
	{"zmq_msg_set"       , lua_zmq_msg_set       },
	{"zmq_socket"        , lua_zmq_socket        },
	{"zmq_close"         , lua_zmq_close         },
	{"zmq_setsockopt"    , lua_zmq_setsockopt    },
	{"zmq_getsockopt"    , lua_zmq_getsockopt    },
	{"zmq_bind"          , lua_zmq_bind          },
	{"zmq_connect"       , lua_zmq_connect       },
	{"zmq_disconnect"    , lua_zmq_disconnect    },
	{"zmq_send"          , lua_zmq_send          },
	{"zmq_send_const"    , lua_zmq_send_const    },
	{"zmq_recv"          , lua_zmq_recv          },
	{"zmq_socket_monitor", lua_zmq_socket_monitor},
	{"zmq_sendmsg"       , lua_zmq_sendmsg       },
	{"zmq_recvmsg"       , lua_zmq_recvmsg       },
	{NULL, NULL}
};

LUALIB_API int luaopen_luazmq(lua_State *L)
{
	luaL_register(L, "luazmq", luazmq);
	return 1;
}