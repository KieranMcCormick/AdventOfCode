cmake_minimum_required(VERSION 3.10)

# set the project name
project(AdventOfCode VERSION 1.0)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# This is a bug in CMake that causes it to prefer the system version over
# the one in the specified ROOT folder.
set(OPENSSL_ROOT_DIR ${OPENSSL_ROOT_DIR} /usr/local/opt/openssl)
set(OPENSSL_CRYPTO_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libcrypto.dylib CACHE FILEPATH "" FORCE)
set(OPENSSL_SSL_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libssl.dylib CACHE FILEPATH "" FORCE)
find_package(OpenSSL REQUIRED)

# set the project name and version
project(Tutorial VERSION 1.0)

add_subdirectory(2015)