local zmq = require("zmq")

local function hwserver()
  local context = zmq.zmq_ctx_new()
  local socket = zmq.zmq_socket(context, zmq.ZMQ_REP)
  assert(zmq.zmq_bind(socket, "tcp://*:5555") == 0, "zmq_bind failed")
  
  local i = 0;
  while true do  
    i = i + 1    
    local r, buff= zmq.zmq_recv(socket, 10, 0)    
    print("hwserver received[" .. i .. "]: " .. buff)
    
    local reply = "your name is " .. buff
    zmq.zmq_send(socket,reply,string.len(reply),0)
  end
   
end

hwserver()