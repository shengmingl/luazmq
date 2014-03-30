local zmq = require("zmq")

local function hwclient()
  print("Connecting to hello world server ...")
  local context = zmq.zmq_ctx_new()
  local socket = zmq.zmq_socket(context, zmq.ZMQ_REQ)
  zmq.zmq_connect(socket, "tcp://localhost:5555")
  
  for i = 1 , 10 do
    print("Sending Hello[" .. i .. "] ...")
    zmq.zmq_send(socket, "Hello", 5, 0)
    local r, buff = zmq.zmq_recv(socket, 100, 0)
    print("hwclient received[" .. i .. "]): " .. buff)
  end
  
  zmq.zmq_close(socket)
  zmq.zmq_ctx_shutdown(context)
end

hwclient()