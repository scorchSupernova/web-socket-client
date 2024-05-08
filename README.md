# web-socket-client

## Pre-requisite:
    [1] C++.
    [2] Boost library for asio action.
    [3] MingW/ or any compiler you want to use.
    [4] vcpkg/any package you can use. I have used vcpkg to install every library.

    
## Steps:
    [1] Run server: 
        g++ server.cpp -o server -I<location-to-boost> -L<location-to-boost-lib> -lboost_system-vc143-mt-x64-1_84 -lws2_32 -lwsock32

   ** After executing the command you will see a executable file server.exe has created. Then run server.exe.

    [2] Run Client:
         g++ client.cpp utils.cpp -o client -I<location-to-boost> -L<location-to-boost-lib> -lboost_system-vc143-mt-x64-1_84 -lws2_32 -lwsock32

    ** After executing the command you will see a executable file client.exe has created. Then run client.exe.

    Done!! You are good to go.