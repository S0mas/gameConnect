
        set(gameConnect_INCLUDE_DIRS C:/D/Programowanie/MojeLibki/gameConnect/gameConnect_server/include;C:/D/Programowanie/MojeLibki/gameConnect/gameConnect_serviceClient/include)
        if(NOT gRPC)
            find_package(gRPC)
        endif()
        include("${CMAKE_CURRENT_LIST_DIR}/gameConnectTargets.cmake")
        