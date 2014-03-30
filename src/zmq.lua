module( ... , package.seeall)

local luazmq = require("luazmq");
zmq_version         = luazmq.zmq_version       
zmq_errno           = luazmq.zmq_errno         
zmq_strerror        = luazmq.zmq_strerror      
zmq_ctx_new         = luazmq.zmq_ctx_new       
zmq_ctx_term        = luazmq.zmq_ctx_term      
zmq_ctx_shutdown    = luazmq.zmq_ctx_shutdown  
zmq_ctx_set         = luazmq.zmq_ctx_set       
zmq_ctx_get         = luazmq.zmq_ctx_get       
zmq_msg_new         = luazmq.zmq_msg_new       
zmq_msg_init        = luazmq.zmq_msg_init      
zmq_msg_init_size   = luazmq.zmq_msg_init_size 
zmq_msg_send        = luazmq.zmq_msg_send      
zmq_msg_recv        = luazmq.zmq_msg_recv      
zmq_msg_close       = luazmq.zmq_msg_close     
zmq_msg_move        = luazmq.zmq_msg_move      
zmq_msg_copy        = luazmq.zmq_msg_copy      
zmq_msg_data        = luazmq.zmq_msg_data      
zmq_msg_size        = luazmq.zmq_msg_size      
zmq_msg_more        = luazmq.zmq_msg_more      
zmq_msg_get         = luazmq.zmq_msg_get       
zmq_msg_set         = luazmq.zmq_msg_set       
zmq_socket          = luazmq.zmq_socket        
zmq_close           = luazmq.zmq_close    
zmq_setsockopt      = luazmq.zmq_setsockopt
zmq_getsockopt      = luazmq.zmq_getsockopt      
zmq_bind            = luazmq.zmq_bind          
zmq_connect         = luazmq.zmq_connect       
zmq_disconnect      = luazmq.zmq_disconnect  
zmq_send            = luazmq.zmq_send
zmq_send_const      = luazmq.zmq_send_const
zmq_recv            = luazmq.zmq_recv      
zmq_socket_monitor  = luazmq.zmq_socket_monitor
zmq_sendmsg         = luazmq.zmq_sendmsg       
zmq_recvmsg         = luazmq.zmq_recvmsg       

--版本信息
ZMQ_VERSION_MAJOR = 4
ZMQ_VERSION_MINOR = 0
ZMQ_VERSION_PATCH = 4
ZMQ_VERSION = ZMQ_VERSION_MAJOR * 10000 + ZMQ_VERSION_MINOR * 100 + ZMQ_VERSION_PATCH

--错误代码
ZMQ_HAUSNUMBERO = 156384712
--平台错误
ENOTSUP         = ZMQ_HAUSNUMBERO + 1
EPROTONOSUPPORT = ZMQ_HAUSNUMBERO + 2
ENOBUFS         = ZMQ_HAUSNUMBERO + 3
ENETDOWN        = ZMQ_HAUSNUMBERO + 4
EADDRINUSE      = ZMQ_HAUSNUMBERO + 5
EADDRNOTAVAIL   = ZMQ_HAUSNUMBERO + 6
ECONNREFUSED    = ZMQ_HAUSNUMBERO + 7
EINPROGRESS     = ZMQ_HAUSNUMBERO + 8
ENOTSOCK        = ZMQ_HAUSNUMBERO + 9
EMSGSIZE        = ZMQ_HAUSNUMBERO + 10
EAFNOSUPPORT    = ZMQ_HAUSNUMBERO + 11
ENETUNREACH     = ZMQ_HAUSNUMBERO + 12
ECONNABORTED    = ZMQ_HAUSNUMBERO + 13
ECONNRESET      = ZMQ_HAUSNUMBERO + 14
ENOTCONN        = ZMQ_HAUSNUMBERO + 15
ETIMEDOUT       = ZMQ_HAUSNUMBERO + 16
EHOSTUNREACH    = ZMQ_HAUSNUMBERO + 17
ENETRESET       = ZMQ_HAUSNUMBERO + 18
--0MQ本身错误
EFSM            = ZMQ_HAUSNUMBERO + 51
ENOCOMPATPROTO  = ZMQ_HAUSNUMBERO + 52
ETERM           = ZMQ_HAUSNUMBERO + 53
EMTHREAD        = ZMQ_HAUSNUMBERO + 54

--0MQ运行参数
ZMQ_IO_THREADS  = 1
ZMQ_MAX_SOCKETS = 2

ZMQ_IO_THREADS_DFLT  = 1
ZMQ_MAX_SOCKETS_DFLT = 1023

--0MQ socket定义

--Socket类型
ZMQ_PAIR  = 0
ZMQ_PUB   = 1
ZMQ_SUB   = 2
ZMQ_REQ   = 3
ZMQ_REP   = 4
ZMQ_DEALER  = 5
ZMQ_ROUTER  = 6
ZMQ_PULL  = 7
ZMQ_PUSH  = 8
ZMQ_XPUB  = 9
ZMQ_XSUB  = 10
ZMQ_STREAM  = 11

--Socket选项
ZMQ_AFFINITY               =  4                         
ZMQ_IDENTITY               =  5                         
ZMQ_SUBSCRIBE              =  6                        
ZMQ_UNSUBSCRIBE            =  7                      
ZMQ_RATE                   =  8                             
ZMQ_RECOVERY_IVL           =  9                     
ZMQ_SNDBUF                 =  11                          
ZMQ_RCVBUF                 =  12                          
ZMQ_RCVMORE                =  13                         
ZMQ_FD                     =  14                              
ZMQ_EVENTS                 =  15                          
ZMQ_TYPE                   =  16                            
ZMQ_LINGER                 =  17                          
ZMQ_RECONNECT_IVL          =  18                   
ZMQ_BACKLOG                =  19                         
ZMQ_RECONNECT_IVL_MAX      =  21               
ZMQ_MAXMSGSIZE             =  22                      
ZMQ_SNDHWM                 =  23                          
ZMQ_RCVHWM                 =  24                          
ZMQ_MULTICAST_HOPS         =  25                  
ZMQ_RCVTIMEO               =  27                        
ZMQ_SNDTIMEO               =  28                        
ZMQ_LAST_ENDPOINT          =  32                   
ZMQ_ROUTER_MANDATORY       =  33                
ZMQ_TCP_KEEPALIVE          =  34                   
ZMQ_TCP_KEEPALIVE_CNT      =  35               
ZMQ_TCP_KEEPALIVE_IDLE     =  36              
ZMQ_TCP_KEEPALIVE_INTVL    =  37             
ZMQ_TCP_ACCEPT_FILTER      =  38               
ZMQ_IMMEDIATE              =  39                       
ZMQ_XPUB_VERBOSE           =  40                    
ZMQ_ROUTER_RAW             =  41                      
ZMQ_IPV6                   =  42                            
ZMQ_MECHANISM              =  43                       
ZMQ_PLAIN_SERVER           =  44                    
ZMQ_PLAIN_USERNAME         =  45                  
ZMQ_PLAIN_PASSWORD         =  46                  
ZMQ_CURVE_SERVER           =  47                    
ZMQ_CURVE_PUBLICKEY        =  48                 
ZMQ_CURVE_SECRETKEY        =  49                 
ZMQ_CURVE_SERVERKEY        =  50                 
ZMQ_PROBE_ROUTER           =  51                    
ZMQ_REQ_CORRELATE          =  52                   
ZMQ_REQ_RELAXED            =  53                     
ZMQ_CONFLATE               =  54                        
ZMQ_ZAP_DOMAIN             =  55                      

--Message选项
ZMQ_MORE     = 1

--Send/recv选项
ZMQ_DONTWAIT = 1
SNDMORE      = 2

--Security mechanisms
ZMQ_NULL     = 0
ZMQ_PLAIN    = 1
ZMQ_CURVE    = 2

--0MQ socket events and monitoring

--Socket transport events (tcp and ipc only)
ZMQ_EVENT_CONNECTED       = 1
ZMQ_EVENT_CONNECT_DELAYED = 2
ZMQ_EVENT_CONNECT_RETRIED = 4

ZMQ_EVENT_LISTENING       = 8
ZMQ_EVENT_BIND_FAILED     = 16

ZMQ_EVENT_ACCEPTED        = 32
ZMQ_EVENT_ACCEPT_FAILED   = 64

ZMQ_EVENT_CLOSED          = 128
ZMQ_EVENT_CLOSE_FAILED    = 256
ZMQ_EVENT_DISCONNECTED    = 512
ZMQ_EVENT_MONITOR_STOPPED = 1024

ZMQ_EVENT_ALL             = 2047 --1|2|4| ... | 1024

