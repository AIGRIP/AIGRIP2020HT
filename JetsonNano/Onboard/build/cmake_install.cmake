# Install script for directory: /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/GeneralTypedefs/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/ParallelMotorAnglet2CPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/InverseKinematicsPreshapeCPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/ApproachObjectCPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/ForwardKinematicsCPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/MorphologicalFiltersCPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/colourBalanceGPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/StableLineCPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/GetValidGripPointsCPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/codegen/lib/GetSignatureCPU/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/imageCapture/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/communication/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/control/cmake_install.cmake")
  include("/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/Executable/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
