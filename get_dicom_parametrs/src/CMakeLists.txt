cmake_minimum_required(VERSION 2.8)

PROJECT(get_dicom_parametrs)

SET(DCMTK_DIR "C:\\Program Files\\DCMTK")
#an example: SET(DCMTK_DIR "C:\\Users\\test\\test_dcmtk\\DCMTK")

# settings for Microsoft Visual C++ 6
SET(CMAKE_C_FLAGS "/nologo /W3 /GX /Gy /YX")
SET(CMAKE_C_FLAGS_DEBUG "/MTd /Z7 /Od")
SET(CMAKE_C_FLAGS_RELEASE "/MT /O2")
SET(CMAKE_CXX_FLAGS "/nologo /W3 /GX /Gy /YX")
SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od")
SET(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")

ADD_DEFINITIONS(-D_REENTRANT)
INCLUDE_DIRECTORIES(${DCMTK_DIR}/include)
LINK_DIRECTORIES(${DCMTK_DIR}/lib)

ADD_EXECUTABLE(get_dicom_parametrs get_dicom_parametrs.cxx "get_dicom_parametrs.h")
TARGET_LINK_LIBRARIES(get_dicom_parametrs netapi32 wsock32 ofstd dcmdata)
#TARGET_LINK_LIBRARIES(get_dicom_parametrs netapi32 wsock32 ofstd dcmdata charls cmr dcmdsig dcmfg dcmimage dcmimgle dcmiod dcmjpeg dcmjpls dcmnet dcmpmap dcmpstat dcmqrdb dcmtr dcmseg dcmsr dcmtls dcmtract dcmwlm i2d ijg8 ijg12 ijg16)